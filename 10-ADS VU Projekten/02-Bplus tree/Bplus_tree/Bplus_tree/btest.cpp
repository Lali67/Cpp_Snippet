// Die Zurverfügungstellung des Programmes oder Teilen davon auf anderen Plattformen,
// Repositories, etc. ist nicht zulässig.
//
// Last Modified: Wed 2020-06-17 15:41:08 (+0200)

#if _WIN32 || _WIN64
#error btest does not work on windows.
#endif

#include <algorithm>
#include <future>
#include <iostream>
#include <random>
#include <set>
#include <sstream>
#include <thread>
#include <vector>

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// VG MACROS {{{
// entnommen aus valgrind/valgrind.h zwecks vermeidung von dependency darauf.
// gültig für amd64 linux, darwin und solaris, kein effekt auf anderen
#define __SPECIAL_INSTRUCTION_PREAMBLE                            \
                     "rolq $3,  %%rdi ; rolq $13, %%rdi\n\t"      \
                     "rolq $61, %%rdi ; rolq $51, %%rdi\n\t"

#define VALGRIND_DO_CLIENT_REQUEST_EXPR(                          \
        _zzq_default, _zzq_request,                               \
        _zzq_arg1, _zzq_arg2, _zzq_arg3, _zzq_arg4, _zzq_arg5)    \
    __extension__                                                 \
    ({ volatile unsigned long int _zzq_args[6];                   \
    volatile unsigned long int _zzq_result;                       \
    _zzq_args[0] = (unsigned long int)(_zzq_request);             \
    _zzq_args[1] = (unsigned long int)(_zzq_arg1);                \
    _zzq_args[2] = (unsigned long int)(_zzq_arg2);                \
    _zzq_args[3] = (unsigned long int)(_zzq_arg3);                \
    _zzq_args[4] = (unsigned long int)(_zzq_arg4);                \
    _zzq_args[5] = (unsigned long int)(_zzq_arg5);                \
    __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
                     /* %RDX = client_request ( %RAX ) */         \
                     "xchgq %%rbx,%%rbx"                          \
                     : "=d" (_zzq_result)                         \
                     : "a" (&_zzq_args[0]), "0" (_zzq_default)    \
                     : "cc", "memory"                             \
                    );                                            \
    _zzq_result;                                                  \
    })

#define RUNNING_ON_VALGRIND                                       \
    (unsigned)VALGRIND_DO_CLIENT_REQUEST_EXPR(0 /* if not */,     \
                                              0x1001,             \
                                              0, 0, 0, 0, 0)      \
// }}}

#include "ADS_set.h"

#if !defined PH1 && !defined PH2
#define PH2
#endif

bool const ISTTY = isatty(fileno(stderr)) && isatty(fileno(stdout));

#define RED(x)    (ISTTY ? "\033[1;31m" : "") << x << (ISTTY ? "\033[0m" : "")
#define GREEN(x)  (ISTTY ? "\033[1;32m" : "") << x << (ISTTY ? "\033[0m" : "")
#define YELLOW(x) (ISTTY ? "\033[1;33m" : "") << x << (ISTTY ? "\033[0m" : "")
#define BLUE(x)   (ISTTY ? "\033[1;34m" : "") << x << (ISTTY ? "\033[0m" : "")
#define PURPLE(x) (ISTTY ? "\033[1;35m" : "") << x << (ISTTY ? "\033[0m" : "")
#define CYAN(x)   (ISTTY ? "\033[1;36m" : "") << x << (ISTTY ? "\033[0m" : "")

#define DEFINED 0x55
using RNG = std::mt19937_64;

// ANTI-POW NASTINESS {{{
// das ist nicht portabel und funktioniert nur weil der linker
// anscheinend sehr naiv ist. offiziell UB und führt zumindest
// unter gcc zu einem "illegal instruction" wenn der abort nicht
// zuvor kommen würde.
extern "C" double pow(double, double)
{
    fprintf(stderr, "\n");
    for(int i = 0; i < 4; ++i) {
        if(i != 0) { usleep(500*1'000); }
        fprintf(stderr, "DO NOT USE POW!");
        usleep(1'000*1'000);

        fprintf(stderr, "\r");
        for(int j = 0; j < 15; ++j) { fprintf(stderr, " "); }
        fprintf(stderr, "\r");
    }

    fprintf(stderr, "DO NOT USE POW!\n");
    abort();
}
// }}}

struct val_t {
    size_t i;
    char defined = ~DEFINED;

    val_t(size_t i): i{ i }, defined{ DEFINED } {}

    val_t()                        = default;
    val_t(val_t const&)            = default;
    val_t& operator=(val_t const&) = default;
};

std::ostream& operator<<(std::ostream& o, val_t const& v) {
    if(v.defined == DEFINED) { return o << v.i; }
    return o << "undefined";
}

std::istream& operator>>(std::istream& i, val_t& v) {
    v.defined = DEFINED;
    return i >> v.i;
}

namespace std {
    template <>
    struct hash<val_t> {
        size_t operator()(val_t const& v) const {
            if(v.defined == DEFINED) { return std::hash<size_t>{}(v.i); }
            throw std::invalid_argument{ "hash: undefined value" };
        }
    };

    template <>
    struct equal_to<val_t> {
        bool operator()(val_t const& lhs, val_t const& rhs) const {
            if(lhs.defined != DEFINED && rhs.defined != DEFINED) {
                throw std::invalid_argument{ "equal_to: both lhs and rhs undefined" };
            } else if(lhs.defined != DEFINED) {
                throw std::invalid_argument{ "equal_to: lhs undefined" };
            } else if(rhs.defined != DEFINED) {
                throw std::invalid_argument{ "equal_to: rhs undefined" };
            }

            return lhs.i == rhs.i;
        }
    };

    template <>
    struct less<val_t> {
        bool operator()(val_t const& lhs, val_t const& rhs) const {
            if(lhs.defined != DEFINED && rhs.defined != DEFINED) {
                throw std::invalid_argument{ "less: both lhs and rhs undefined" };
            } else if(lhs.defined != DEFINED) {
                throw std::invalid_argument{ "less: lhs undefined" };
            } else if(rhs.defined != DEFINED) {
                throw std::invalid_argument{ "less: rhs undefined" };
            }

            return lhs.i < rhs.i;
        }
    };
}

namespace ads {
    template <class T>
    using set =
#ifdef SIZE
        ADS_set<T, SIZE>;
#else
        ADS_set<T>;
#endif
}

// gestohlen aus simpletest
template <typename C, typename It>
std::string it2str(const C &c, const It &it) {
    if(it == c.end()) return std::string{"end()"};
    std::stringstream buf;
    buf << '&' << *it;
    return buf.str();
}

// gestohlen aus simpletest
template <typename C1, typename It1, typename C2, typename It2>
bool it_equal(const C1 &c1, const It1 &it1, const C2 &c2, const It2 &it2) {
    return (it1 == c1.end() && it2 == c2.end()) ||
           (it1 != c1.end() && it2 != c2.end() && std::equal_to<typename C1::value_type>{}(*it1, *it2));
}

bool operator==(ads::set<val_t> const& lhs, std::set<val_t> const& rhs) {
    if(lhs.size() != rhs.size()) { return false; }
    for(auto const& v: rhs) { if(!lhs.count(v)) { return false; } }
    return true;
}

bool operator==(std::set<val_t> const& lhs, std::set<val_t> const& rhs) {
    if(lhs.size() != rhs.size()) { return false; }
    for(auto const& v: lhs) { if(!rhs.count(v)) { return false; } }
    return true;
}

bool operator!=(std::set<val_t> const& lhs, std::set<val_t> const& rhs) {
    return !(lhs == rhs);
}

bool operator!=(ads::set<val_t> const& lhs, std::set<val_t> const& rhs) {
    return !(lhs == rhs);
}

void wait_read(float d=5) {
    if(!ISTTY) { return; }

    std::cerr << "^^^THIS^^^ is your error message.  ";
    char spinny_thingy[]{'|', '/', '-', '\\'};

    size_t steps = sizeof(spinny_thingy)*2;
    for(size_t i = 0; i < steps; ++i) {
        std::cerr << '\b' << spinny_thingy[i % sizeof(spinny_thingy)];
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<size_t>(d/steps*1000)));
    }

    std::cerr << '\r';
    for(size_t i = 0; i < 35; ++i) { std::cerr << ' '; }
    std::cerr << '\r';
}

void dump_compare(ads::set<val_t> const& a, std::set<val_t> const& r, bool force_read=true) {
    if(force_read) { wait_read(); }
    std::cerr << "values that were expected:\n\n";

    for(auto const& v: r) { std::cerr << v << ' '; }
    std::cerr << "\n\n";

    std::cerr << "dump of student container:\n\n";
    a.dump();
    std::cerr << "size = " << a.size() << " (should be " << r.size() << ")\n";
}

void sanity_check(std::string const& where, ads::set<val_t> const& a, std::set<val_t> const& r) {
    if(a != r) {
        std::cerr << RED("[" << where << "] err: sanity check failed --- equality does not hold.\n")
                  << CYAN("NOTE: ") << "equality is checked using count() and size().\n\n";

        dump_compare(a, r);

        std::abort();
    }
}

#ifdef PH2
void test_insert(ads::set<val_t>& a, std::set<val_t>& r, size_t n, size_t max_value, RNG& gen) {
    std::cerr << "\n=== test_insert ===\n";
    std::uniform_int_distribution<size_t> dist{ 0, max_value };
    for(size_t i = 0; i < n; ++i) {
        val_t v{ dist(gen) };

        std::cerr << "in " << v << '\n';
        auto it_r = r.insert(v);
        auto it_a = a.insert(v);

        if(it_a.second != it_r.second) {
            std::cerr << RED("[insert] err: mismatch of insertion status\n"
                      << "value " << v << " was" << (it_a.second ? "" : " not") << " inserted (returned "
                      << std::boolalpha << it_a.second << "), but " << (it_r.second ? "should've" : "shouldn't have")
                      << " been (should've returned " << it_r.second << " instead)\n");

            dump_compare(a, r);
            std::abort();
        }

        if(!it_equal(a, it_a.first, r, it_r.first)) {
            std::cerr << RED("[insert] err: returned iterator does not match expected value.\n"
                      << "inserted value " << v << " but iterator points to " << it2str(a, it_a.first) << '\n');

            dump_compare(a, r);
            std::abort();
        }
    }

    sanity_check("insert", a, r);
}
#endif

void test_insert_it(ads::set<val_t>& a, std::set<val_t>& r, size_t n, size_t max_value, RNG& gen) {
    std::cerr << "\n=== test_insert_it ===\n";
    std::uniform_int_distribution<size_t> dist{ 0, max_value };
    std::vector<val_t> values; values.reserve(n);

    std::cerr << "ii ";
    for(size_t i = 0; i < n; ++i) {
        val_t v{ dist(gen) };

        std::cerr << v << ' ';
        values.push_back(v);
    }
    std::cerr << '\n';

    a.insert(values.begin(), values.end());
    r.insert(values.begin(), values.end());

    sanity_check("insert_it", a, r);
}

void test_insert_ilist(ads::set<val_t>& a, std::set<val_t>& r) {
    std::cerr << "\n=== test_insert_ilist ===\n";
    std::initializer_list<val_t> il = {1, 2, 777, 666, 1337, 891, 278, 1, 2, 4, 8, 16, 32, 64, 128, 256};

    std::cerr << "in { ";
    for(auto const& v: il) { std::cerr << v << ' '; }
    std::cerr << "}\n";
    a.insert(il);
    r.insert(il);

    sanity_check("insert_ilist", a, r);
}

#ifdef PH2
void test_insert_erase(ads::set<val_t>& a, std::set<val_t>& r, size_t n, size_t max_value, RNG& gen) {
    std::cerr << "\n=== test_insert_erase ===\n";
    std::uniform_int_distribution<size_t> dist_i{ 0, max_value };
    std::uniform_real_distribution<double> dist_f{ 0, 1 };

    for(size_t i = 0; i < n; ++i) {
        val_t v{ dist_i(gen) };

        if(dist_f(gen) < 0.5) {
            std::cerr << "in " << v << '\n';
            auto it_r = r.insert(v);
            auto it_a = a.insert(v);

            if(it_a.second != it_r.second) {
                std::cerr << RED("[insert_erase] err: mismatch of insertion status\n"
                          << "value " << v << " was" << (it_a.second ? "" : " not") << " inserted, but "
                          <<  (it_r.second ? "should've" : "shouldn't have") << " been\n");

                dump_compare(a, r);
                std::abort();
            }

            if(!it_equal(a, it_a.first, r, it_r.first)) {
                std::cerr << RED("[insert_erase] err: returned iterator does not match expected value.\n"
                          << "inserted value " << v << " but iterator points to " << it2str(a, it_a.first) << '\n');

                dump_compare(a, r);
                std::abort();
            }
        } else {
            std::cerr << "er " << v << '\n';
            size_t c_r = r.erase(v);
            size_t c_a = a.erase(v);

            if(c_r != c_a) {
                std::cerr << RED("[insert_erase] err: returned count for erase does not match expected value.\n"
                          << "erasing value " << v << " returned " << c_a << ", but expected " << c_r << '\n');

                dump_compare(a, r);
                std::abort();
            }
        }
    }

    sanity_check("insert_erase", a, r);
}

void test_insert_it_erase(ads::set<val_t>& a, std::set<val_t>& r, size_t n, size_t max_value, RNG& gen) {
    std::cerr << "\n=== test_insert_it_erase ===\n";
    std::uniform_int_distribution<size_t> dist_i{ 0, max_value };
    std::uniform_real_distribution<double> dist_f{ 0, 1 };

    std::vector<val_t> values_to_insert; values_to_insert.reserve(n/2 + 1);
    std::vector<val_t> values_to_erase; values_to_erase.reserve(n/2 + 1);

    std::cerr << "ii ";
    for(size_t i = 0; i < n; ++i) {
        val_t v{ dist_i(gen) };

        if(dist_f(gen) < 0.5) {
            std::cerr << v << ' ';
            values_to_insert.push_back(v);
        } else {
            values_to_erase.push_back(v);
        }
    }
    std::cerr << '\n';

    a.insert(values_to_insert.begin(), values_to_insert.end());
    r.insert(values_to_insert.begin(), values_to_insert.end());

    for(auto const& v: values_to_erase) {
        std::cerr << "er " << v << '\n';
        size_t c_r = r.erase(v);
        size_t c_a = a.erase(v);

        if(c_r != c_a) {
            std::cerr << RED("[insert_it_erase] err: returned count for erase does not match expected value.\n"
                      << "erasing value " << v << " returned " << c_a << ", but expected " << c_r << '\n');

            dump_compare(a, r);
            std::abort();
        }
    }

    sanity_check("insert_it_erase", a, r);
}
#endif

void test_count(ads::set<val_t> const& a, std::set<val_t> const& r, size_t max_value) {
    std::cerr << "\n=== test_count ===\n";
    for(size_t i = 0; i < max_value; ++i) {
        std::cerr << "co " << i << '\n';
        size_t c_a = a.count(i);
        size_t c_r = r.count(i);

        if(c_a != c_r) {
            std::cerr << RED("[count] err: returned count does not match for value " << i << '\n'
                      << "expected: " << c_r << " but got " << c_a << '\n');

            dump_compare(a, r);
            std::abort();
        }
    }
}

#ifdef PH2
void test_find(ads::set<val_t> const& a, std::set<val_t> const& r, size_t max_value) {
    std::cerr << "\n=== test_find ===\n";
    for(size_t i = 0; i < max_value; ++i) {
        std::cerr << "fi " << i << '\n';
        auto it_r = r.find(i);
        auto it_a = a.find(i);

        if(!it_equal(a, it_a, r, it_r)) {
            std::cerr << RED("[find] err: returned iterator does not match expected value.\n"
                      << "value to find was " << i << " but iterator points to " << it2str(a, it_a) << '\n');

            dump_compare(a, r);
            std::abort();
        }
    }
}
#endif

void test_initlist_constructor1() {
    std::cerr << "\n=== test_initlist_constructor1 ===\n";

    std::cerr << "constructing w/ { }\n";
    ads::set<val_t> a{ std::initializer_list<val_t>{} };
    std::set<val_t> r{ std::initializer_list<val_t>{} };

    if(a.size() != 0) {
        std::cerr << RED("[initlist_constructor1] err: constructed w/ empty initlist, but size is not 0!\n");
        std::abort();
    }

    if(!a.empty()) {
        std::cerr << RED("[initlist_constructor1] err: constructed w/ empty initlist, but is not empty!\n");
        std::abort();
    }

    for(size_t i = 0; i < 10; ++i) {
        std::cerr << "co " << i << '\n';
        if(a.count(i)) {
            std::cerr << RED("[initlist_constructor1] err: count(" << i << ") returns 1, but expected 0\n");
            std::abort();
        }
    }

    std::vector<val_t> vs{ 1, 2, 3 };
    std::cerr << "ii ";
    for(auto const& v: vs) { std::cerr << v << ' '; }
    std::cerr << '\n';

    a.insert(vs.begin(), vs.end());
    r.insert(vs.begin(), vs.end());

    sanity_check("initlist_constructor1", a, r);
}

void test_initlist_constructor2() {
    std::cerr << "\n=== test_initlist_constructor2 ===\n";

    std::initializer_list<val_t> il = { 1, 2, 3 };

    std::cerr << "constructing w/ { ";
    for(auto const& v: il) { std::cerr << v << ' '; }
    std::cerr << "}\n";

    ads::set<val_t> a{ il };
    std::set<val_t> r{ il };

    sanity_check("initlist_constructor2", a, r);
}

void test_initlist_constructor3(size_t n, size_t max_value, RNG& gen) {
    std::cerr << "\n=== test_initlist_constructor3 ===\n";
    std::initializer_list<val_t> il = { 1, 2, 3 };

    std::cerr << "constructing w/ { ";
    for(auto const& v: il) { std::cerr << v << ' '; }
    std::cerr << "}\n";

    ads::set<val_t> a{ il };
    std::set<val_t> r{ il };

    std::uniform_int_distribution<size_t> dist{ 0, max_value };
    std::vector<val_t> vs;

    std::cerr << "ii ";
    for(size_t i = 0; i < n; ++i) {
        val_t v{ dist(gen) };
        std::cerr << v << ' ';
        vs.push_back(v);
    }
    std::cerr << '\n';

    a.insert(vs.begin(), vs.end());
    r.insert(vs.begin(), vs.end());

    sanity_check("initlist_constructor3", a, r);
}

void test_range_constructor1() {
    std::cerr << "\n=== test_range_constructor1 ===\n";
    std::vector<val_t> vs{ };

    std::cerr << "constructing w/ [ ]\n";
    ads::set<val_t> a(vs.begin(), vs.end());
    std::set<val_t> r(vs.begin(), vs.end());

    if(a.size() != 0) {
        std::cerr << RED("[range_constructor1] err: constructed w/ empty range, but size is not 0!\n");
        std::abort();
    }

    if(!a.empty()) {
        std::cerr << RED("[range_constructor1] err: constructed w/ empty range, but is not empty!\n");
        std::abort();
    }

    for(size_t i = 0; i < 10; ++i) {
        std::cerr << "co " << i << '\n';
        if(a.count(i)) {
            std::cerr << RED("[range_constructor1] err: count(" << i << ") returns 1, but expected 0\n");
            std::abort();
        }
    }

    std::cerr << "ii ";
    for(size_t i = 0; i < 10; ++i) { vs.push_back(i); std::cerr << i << ' '; }
    std::cerr << '\n';

    a.insert(vs.begin(), vs.end());
    r.insert(vs.begin(), vs.end());

    sanity_check("range_constructor1", a, r);
}

void test_range_constructor2() {
    std::cerr << "\n=== test_range_constructor2 ===\n";
    std::vector<val_t> const vs{ 1, 2, 3 };

    std::cerr << "constructing w/ [ ";
    for(auto const& v: vs) { std::cerr << v << ' '; }
    std::cerr << "]\n";

    ads::set<val_t> a(vs.begin(), vs.end());
    std::set<val_t> r(vs.begin(), vs.end());

    sanity_check("range_constructor2", a, r);
}

void test_range_constructor3(size_t n, size_t max_value, RNG& gen) {
    std::cerr << "\n=== test_range_constructor3 ===\n";
    std::vector<val_t> vs{ 1, 2, 3 };
    vs.reserve(n + 3);

    std::cerr << "constructing w/ [ ";
    for(auto const& v: vs) { std::cerr << v << ' '; }
    std::cerr << "]\n";

    ads::set<val_t> a(vs.begin(), vs.end());
    std::set<val_t> r(vs.begin(), vs.end());

    std::uniform_int_distribution<size_t> dist{ 0, max_value };
    std::cerr << "ii ";
    for(size_t i = 0; i < n; ++i) {
        val_t v{ dist(gen) };
        std::cerr << v << ' ';
        vs.push_back(v);
    }
    std::cerr << '\n';

    a.insert(vs.begin(), vs.end());
    r.insert(vs.begin(), vs.end());

    sanity_check("range_constructor3", a, r);
}

void test_empty(ads::set<val_t> const& a, std::set<val_t> const& r) {
    std::cerr << "\n=== test_empty ===\n";

    std::cerr << "em\n";
    if(a.empty() != r.empty()) {
        std::cerr << RED("[empty] err: container is" << (a.empty() ? "" : " not") << " empty, "
                  << "but shouldn't be\n");
        dump_compare(a, r);

        std::abort();
    }
}

void test_size(ads::set<val_t> const& a, std::set<val_t> const& r) {
    std::cerr << "\n=== test_size ===\n";

    std::cerr << "si\n";
    if(a.size() != r.size()) {
        std::cerr << RED("[empty] err: container size is " << a.size() << ", but should be " << r.size() << '\n');
        dump_compare(a, r);
        std::abort();
    }
}

#ifdef PH2
void test_clear(ads::set<val_t>& a, std::set<val_t>& r) {
    std::cerr << "\n=== test_clear ===\n";

    std::cerr << "cl\n";
    a.clear();
    r.clear();

    if(a.size() != 0) {
        std::cerr << RED("[clear] err: size after clear is not 0!\n");
        dump_compare(a, r);
        std::abort();
    }

    if(!a.empty()) {
        std::cerr << RED("[clear] err: container is not empty after clear!\n");
        dump_compare(a, r);
        std::abort();
    }

    if(a.begin() != a.end()) {
        std::cerr << RED("[clear] err: iterator range is not empty after clear!\n");
        dump_compare(a, r);
        std::abort();
    }
}

void test_copy(ads::set<val_t> const& a, std::set<val_t> const& r) {
    std::cerr << "\n=== test_copy ===\n";
    ads::set<val_t> copy_a{ a };
    std::set<val_t> copy_r{ r };

    if(a.size() != copy_a.size()) {
        std::cerr << RED("[copy] err: size after copying does not match.\n"
                  << "size should be: " << a.size() << ", but is " << copy_a.size() << '\n');

        dump_compare(a, r);
        std::abort();
    }

    for(auto const& v: r) {
        if(!copy_a.count(v)) {
            std::cerr << RED("[copy] err: containers not equal after copy. lost value " << v << '\n');
            dump_compare(copy_a, copy_r);
            std::abort();
        }
    }

    if(a != copy_a) {
        std::cerr << RED("[copy] err: op!= returned true\n");

        std::cerr << "\noriginal\n";
        dump_compare(a, r);

        std::cerr << "\ncopy\n";
        dump_compare(copy_a, copy_r, false);
        std::abort();
    }

    for(size_t i = 0; copy_a.size() == r.size(); ++i) {
        std::cerr << "in (copy) " << i << '\n';
        copy_a.insert(i); copy_r.insert(i);
    }

    for(auto const& v: copy_r) {
        size_t c_r = r.count(v);
        size_t c_a = a.count(v);

        if(c_r != c_a) {
            std::cerr << RED("[copy] err: counted " << c_a << " for value " << v
                      << " in original container, but expected " << c_r << '\n');

            std::cerr << "\norignal\n";
            dump_compare(a, r);

            std::cerr << "\ncopy\n";
            dump_compare(copy_a, copy_r, false);
            std::abort();
        }
    }

    if(a == copy_a) {
        std::cerr << RED("[copy] err: op== returned true\n");

        std::cerr << "\noriginal\n";
        dump_compare(a, r);

        std::cerr << "\ncopy\n";
        dump_compare(copy_a, copy_r, false);
        std::abort();
    }

    sanity_check("test_copy", copy_a, copy_r);
}

void test_assign(ads::set<val_t> const& a, std::set<val_t> const& r) {
    std::cerr << "\n=== test_assign ===\n";

    ads::set<val_t> b;
    b = a;

    if(a.size() != b.size()) {
        std::cerr << RED("[copy] err: size after assigning does not match.\n"
                  << "size should be: " << a.size() << ", but is " << b.size() << '\n');

        dump_compare(a, r);
        std::abort();
    }

    for(auto const& v: a) {
        if(!b.count(v)) {
            std::cerr << RED("[assign] err: containers not equal after assign. lost value " << v << '\n');
            std::cerr << "\noriginal\n";
            dump_compare(a, r);

            std::cerr << "\ncopy\n";
            dump_compare(b, r, false);
            std::abort();
        }
    }

    if(a != b) {
        std::cerr << RED("[assign] err: op!= returned true\n");

        std::cerr << "\noriginal\n";
        dump_compare(a, r);

        std::cerr << "\ncopy\n";
        dump_compare(b, r, false);
        std::abort();
    }
}

void test_assign_initlist(ads::set<val_t>& a, std::set<val_t>& r) {
    std::cerr << "\n=== test_assign_initlist ===\n";

    a = {1, 2, 3};
    r = {1, 2, 3};

    if(a.size() != r.size()) {
        std::cerr << RED("[assign_initlist] err: size after assigning does not match.\n"
                  << "size should be: " << r.size() << ", but is " << a.size() << '\n');

        dump_compare(a, r);
        std::abort();
    }

    sanity_check("assign_initlist", a, r);
}

void test_iter(ads::set<val_t> const& a, std::set<val_t> const& r) {
    std::cerr << "\n=== test_iter ===\n";

    size_t dist = std::distance(a.begin(), a.end());
    if(dist != r.size()) {
        std::cerr << RED("[iter] err: range size (distance between begin and end) is wrong.\n"
                  << "expected: " << r.size() << ", but got: " << dist << '\n');
        dump_compare(a, r);
        std::abort();
    }

    std::vector<val_t> dump; dump.reserve(a.size());
    for(auto const& v: a) {
        if(!r.count(v)) {
            std::cerr << RED("[iter] err: encountered unexpected value while iterating: " << v << " should not be part of container!\n");
            dump_compare(a, r);
            std::abort();
        }
        dump.push_back(v);
    }

    std::vector<val_t> dump_copy = dump;

    std::sort(dump.begin(), dump.end(), std::less<val_t>{});
    auto last = std::unique(dump.begin(), dump.end(), std::equal_to<val_t>{});
    dump.erase(last, dump.end());

    if(dump.size() != r.size()) {
        std::cerr << RED("[iter] err: had duplicate encounters while iterating. found following elements (in this order):\n\n");

        for(auto const& v: dump_copy) { std::cerr << v << ' '; }
        std::cerr << '\n';

        dump_compare(a, r);
        std::abort();
    }

    ads::set<val_t>::iterator i;
    for(i = a.begin(); i != a.end(); ++i) {
        if(!r.count(*i)) {
            std::cerr << RED("[iter] err: encountered unexpected value while iterating (default iterator constructor): "
                      << *i << " should not be part of container!\n");

            dump_compare(a, r);
            std::abort();
        }
    }
}

void test_insert_iter(ads::set<val_t>& a, std::set<val_t>& r, size_t n, size_t max_value, RNG& gen) {
    std::cerr << "\n=== test_insert_iter ===\n";
    std::uniform_int_distribution<size_t> dist{ 0, max_value };

    for(size_t i = 0; i < n; ++i) {
        val_t v{ dist(gen) };
        std::cerr << "in " << v << '\n';
        auto it_a = a.insert(v);
        auto it_r = r.insert(v);

        std::vector<val_t> dump{ a.begin(), a.end() };

        if(dump.size() != a.size()) {
            std::cerr << RED("[insert_iter] [begin, end) range length mismatch. expected " << a.size() << " elements, but got "
                      << dump.size()) << "\n\nextracted range:\n\n";

            for(auto const& v: dump) { std::cerr << v << ' '; }
            std::cerr << "\n\n";

            dump_compare(a, r);
            std::abort();
        }

        auto it = std::find_if(dump.begin(), dump.end(), [&v](auto const& w) { return std::equal_to<val_t>{}(v, w); });

        if(it_a.second != it_r.second) {
            std::cerr << RED("[insert_iter] insertion status mismatch. returned '" << it_a.second << "' for value"
                      << *it << ", which was " << (it_r.second ? "" : "not ") << "already part of container.\n");

            dump_compare(a, r);
            std::abort();
        }

        if(!it_equal(a, it_a.first, r, it_r.first)) {
            std::cerr << RED("[insert_iter] err: returned iterator does not match expected value.\n"
                      << "inserted value " << v << " but iterator points to " << it2str(a, it_a.first) << '\n');

            dump_compare(a, r);
            std::abort();
        }

        bool eq_range_left  = std::equal(dump.begin(), it, a.begin(), it_a.first, std::equal_to<val_t>{});
        bool eq_range_left_ = std::equal(a.begin(), it_a.first, dump.begin(), it, std::equal_to<val_t>{});

        bool eq_range_right  = std::equal(it, dump.end(), it_a.first, a.end(), std::equal_to<val_t>{});
        bool eq_range_right_ = std::equal(it_a.first, a.end(), it, dump.end(), std::equal_to<val_t>{});

        if(!eq_range_left || !eq_range_left_) {
            std::cerr << RED("[insert_iter] range spanned from begin to iterator returned by insert does not match subset of original range.\n"
                      << "value was " << *it << "\n\n") << "original extracted [begin, end) range:\n\n";

            for(auto const& v: dump) { std::cerr << v << ' '; }
            std::cerr << '\n';

            std::cerr << "\nsubset of range that was looked at:\n\n";
            for(auto i = dump.begin(); i != it; ++i) { std::cerr << *i << ' '; }
            std::cerr << '\n';

            std::cerr << "\nrange spanned from begin to insert iterator:\n\n";
            for(auto i = a.begin(); i != it_a.first; ++i) { std::cerr << *i << ' '; }
            std::cerr << "\n\n";

            dump_compare(a, r);
            std::abort();
        }

        if(!eq_range_right || !eq_range_right_) {
            std::cerr << RED("[insert_iter] range spanned by iterator returned by insert to end does not match subset of original range.\n"
                      << "value was " << *it << "\n\n") << "original extracted range:\n\n";

            for(auto const& v: dump) { std::cerr << v << ' '; }
            std::cerr << '\n';

            std::cerr << "\nsubset of range that was looked at:\n\n";
            for(auto i = it; i != dump.end(); ++i) { std::cerr << *i << ' '; }
            std::cerr << '\n';

            std::cerr << "\nrange spanned by insert iterator to end:\n\n";
            for(auto i = it_a.first; i != a.end(); ++i) { std::cerr << *i << ' '; }
            std::cerr << "\n\n";

            dump_compare(a, r);
            std::abort();
        }
    }

    sanity_check("insert_iter", a, r);
}

void test_find_iter(ads::set<val_t> const& a, std::set<val_t> const& r) {
    std::cerr << "\n=== test_find_iter ===\n";

    std::vector<val_t> vs; vs.reserve(r.size());
    for(auto const& v: a) { vs.push_back(v); }

    if(vs.size() != a.size()) {
        std::cerr << RED("[insert_iter] [begin, end) range length mismatch. expected " << a.size() << " elements, but got "
                  << vs.size()) << "\n\nextracted range:\n\n";

        for(auto const& v: vs) { std::cerr << v << ' '; }
        std::cerr << "\n\n";

        dump_compare(a, r);
        std::abort();
    }

    for(auto it = vs.begin(); it != vs.end(); ++it) {
        std::cerr << "fi " << *it << '\n';
        auto it_a = a.find(*it);

        if(it_a == a.end() || !std::equal_to<val_t>{}(*it, *it_a)) {
            std::cerr << RED("[find_iter] find failed. points to " << it2str(a, it_a) << " instead.\n");

            dump_compare(a, r);
            std::abort();
        }

        bool eq_range_left  = std::equal(vs.begin(), it, a.begin(), it_a, std::equal_to<val_t>{});
        bool eq_range_left_ = std::equal(a.begin(), it_a, vs.begin(), it, std::equal_to<val_t>{});

        bool eq_range_right  = std::equal(it, vs.end(), it_a, a.end(), std::equal_to<val_t>{});
        bool eq_range_right_ = std::equal(it_a, a.end(), it, vs.end(), std::equal_to<val_t>{});

        if(!eq_range_left || !eq_range_left_) {
            std::cerr << RED("[find_iter] range spanned from begin to iterator returned by find does not match subset of original range.\n"
                      << "value was " << *it << "\n\n") << "original extracted range:\n\n";

            for(auto const& v: vs) { std::cerr << v << ' '; }
            std::cerr << '\n';

            std::cerr << "\nsubset of range that was looked at:\n\n";
            for(auto i = vs.begin(); i != it; ++i) { std::cerr << *i << ' '; }
            std::cerr << '\n';

            std::cerr << "\nrange spanned from begin to find iterator:\n\n";
            for(auto i = a.begin(); i != it_a; ++i) { std::cerr << *i << ' '; }
            std::cerr << "\n\n";

            dump_compare(a, r);
            std::abort();
        }

        if(!eq_range_right || !eq_range_right_) {
            std::cerr << RED("[find_iter] range spanned by iterator returned by find to end does not match subset of original range.\n"
                      << "value was " << *it << "\n\n") << "original extracted range:\n\n";

            for(auto const& v: vs) { std::cerr << v << ' '; }
            std::cerr << '\n';

            std::cerr << "\nsubset of range that was looked at:\n\n";
            for(auto i = it; i != vs.end(); ++i) { std::cerr << *i << ' '; }
            std::cerr << '\n';

            std::cerr << "\nrange spanned by find iterator to end:\n\n";
            for(auto i = it_a; i != a.end(); ++i) { std::cerr << *i << ' '; }
            std::cerr << "\n\n";

            dump_compare(a, r);
            std::abort();
        }
    }
}

void test_swap_insert_erase(ads::set<val_t>& a1, std::set<val_t>& r1, ads::set<val_t>& a2, std::set<val_t>& r2, size_t n, size_t max_value, RNG& gen) {
    std::cerr << "\n=== test_swap_insert_erase ===\n";
    using std::swap; // wäh, igitt

    std::cerr << "swap(a1, a2)\n";
    swap(a1, a2);
    swap(r1, r2);

    std::cerr << CYAN("NOTE: ") << "following test is done on a1 after swap(a1, a2)!\n";
    test_insert_erase(a1, r1, n, max_value, gen);
    sanity_check("swap_insert_erase(a2)", a2, r2);

    std::cerr << "\nswap(a1, a2)\n";
    swap(a1, a2);
    swap(r1, r2);
}

void test_equality(ads::set<val_t> const& a1, std::set<val_t> const& r1, ads::set<val_t> const& a2, std::set<val_t> const& r2) {
    std::cerr << "\n=== test_equality ==\n";
    bool eq_a = a1 == a2;
    bool eq_r = r1 == r2;

    if(eq_a != eq_r) {
        std::cerr << RED("[equality] err: equality mismatch. expected sets to be "
                  << (eq_r ? "equal" : "inequal") << ", but op== returned " << std::boolalpha << eq_a << '\n');

        std::cerr << "\na1\n";
        dump_compare(a1, r1);

        std::cerr << "\na2\n";
        dump_compare(a2, r2, false);
        std::abort();
    }
}

void test_inequality(ads::set<val_t> const& a1, std::set<val_t> const& r1, ads::set<val_t> const& a2, std::set<val_t> const& r2) {
    std::cerr << "\n=== test_inequality ==\n";
    bool ineq_a = a1 != a2;
    bool ineq_r = r1 != r2;

    if(ineq_a != ineq_r) {
        std::cerr << RED("[inequality] err: equality mismatch. expected sets to be "
                  << (ineq_r ? "inequal" : "equal") << ", but op!= returned " << std::boolalpha << ineq_a << '\n');

        std::cerr << "\na1\n";
        dump_compare(a1, r1);

        std::cerr << "\na2\n";
        dump_compare(a2, r2, false);
        std::abort();
    }
}
#endif

void test_all_ph1(size_t n, size_t max_value, RNG& gen) {
    test_initlist_constructor3(n, max_value, gen);
    test_range_constructor3(n, max_value, gen);

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a;
        std::set<val_t> r;

        test_count(a, r, max_value);
        test_empty(a, r);
        test_size(a, r);

        test_insert_it(a, r, n, max_value, gen);

        test_count(a, r, max_value);
        test_size(a, r);
        test_empty(a, r);
    }

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a;
        std::set<val_t> r;

        test_insert_ilist(a, r);
        test_size(a, r);
    }

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a;
        std::set<val_t> r;

        test_insert_it(a, r, n, max_value, gen);
        test_size(a, r);
        test_count(a, r, max_value);
    }

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a;
        std::set<val_t> r;

        test_insert_it(a, r, n, max_value, gen);
        test_count(a, r, max_value);

        test_insert_it(a, r, n, max_value, gen);
        test_count(a, r, max_value);
    }
}

#ifdef PH2
void test_all_ph2(size_t n, size_t max_value, RNG& gen) {
    test_initlist_constructor3(n, max_value, gen);
    test_range_constructor3(n, max_value, gen);

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a;
        std::set<val_t> r;

        test_iter(a, r);

        test_copy(a, r);
        test_assign(a, r);
        test_assign_initlist(a, r);

        test_insert(a, r, n, max_value, gen);
        test_iter(a, r);
        test_insert_iter(a, r, n, max_value, gen);

        test_clear(a, r);

        test_size(a, r);
        test_empty(a, r);
    }

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a;
        std::set<val_t> r;

        test_insert_it(a, r, n, max_value, gen);
        test_count(a, r, max_value);
        test_find(a, r, max_value);

        test_size(a, r);
        test_clear(a, r);

        test_copy(a, r);
        test_assign(a, r);
    }

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a;
        std::set<val_t> r;

        test_insert_erase(a, r, n, max_value, gen);
        test_count(a, r, max_value);
        test_find(a, r, max_value);
        test_iter(a, r);

        test_size(a, r);
        test_empty(a, r);

        test_insert_erase(a, r, n, max_value, gen);
        test_count(a, r, max_value);
        test_find(a, r, max_value);
        test_iter(a, r);

        test_insert_it(a, r, n, max_value, gen);
        test_count(a, r, max_value);
        test_find(a, r, max_value);

        test_clear(a, r);

        test_size(a, r);
        test_empty(a, r);
    }

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a;
        std::set<val_t> r;
        test_insert_it_erase(a, r, n, max_value, gen);
        test_count(a, r, max_value);
        test_find(a, r, max_value);

        test_size(a, r);
        test_empty(a, r);
    }

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a;
        std::set<val_t> r;

        test_insert_ilist(a, r);
        test_count(a, r, max_value);
        test_find(a, r, max_value);

        test_copy(a, r);
    }

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a1;
        std::set<val_t> r1;

        std::cerr << "\na1";
        test_insert_erase(a1, r1, n, max_value, gen);
        test_insert_erase(a1, r1, n, max_value, gen);
        test_clear(a1, r1);

        test_insert_it_erase(a1, r1, n, max_value, gen);

        test_insert_erase(a1, r1, n, max_value, gen);
        test_insert_erase(a1, r1, n, max_value, gen);
        test_iter(a1, r1);

        test_copy(a1, r1);
        test_iter(a1, r1);
        test_insert_iter(a1, r1, n, max_value, gen);
        test_find_iter(a1, r1);

        ads::set<val_t> a2;
        std::set<val_t> r2;

        std::cerr << "\na2";
        test_insert_it_erase(a2, r2, n, max_value, gen);
        test_insert_erase(a2, r2, n, max_value, gen);

        test_insert(a2, r2, n, max_value, gen);
        test_insert(a2, r2, n, max_value, gen);

        test_swap_insert_erase(a1, r1, a2, r2, n, max_value, gen);

        test_insert_iter(a1, r1, n, max_value, gen);
        test_insert_iter(a2, r2, n, max_value, gen);

        test_insert_erase(a1, r1, n, max_value, gen);
        test_insert_erase(a2, r2, n, max_value, gen);

        test_iter(a1, r1);
        test_iter(a2, r2);

        test_insert_iter(a1, r1, n, max_value, gen);
        test_insert_iter(a2, r2, n, max_value, gen);

        test_find_iter(a1, r1);
        test_find_iter(a2, r2);
    }

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a1;
        std::set<val_t> r1;

        std::cerr << "\na1";
        test_insert_erase(a1, r1, n, max_value, gen);

        ads::set<val_t> a2;
        std::set<val_t> r2;

        std::cerr << "\na2";
        test_insert_erase(a2, r2, n, max_value, gen);

        test_swap_insert_erase(a1, r1, a2, r2, n, max_value, gen);

        test_equality(a1, r1, a2, r2);
        test_inequality(a1, r1, a2, r2);
    }

    {
        std::cerr << "\n----\n";
        ads::set<val_t> a1;
        std::set<val_t> r1;

        ads::set<val_t> a2;
        std::set<val_t> r2;

        test_insert_erase(a1, r1, n, max_value, gen);
        test_insert_erase(a2, r2, n, max_value, gen);

        test_equality(a1, r1, a2, r2);
        test_inequality(a1, r1, a2, r2);

        test_clear(a1, r1);
        test_equality(a1, r1, a2, r2);

        ads::set<val_t> a3;
        std::set<val_t> r3;

        test_equality(a1, r1, a3, r3);
        test_inequality(a1, r1, a3, r3);
    }
}
#endif

void do_stresstest1(RNG* const gen) {
    std::cerr << "\n=== stresstest1 " << (gen ? "(randomized) " : "") << "===\n";

    size_t const n = 1'000'000;
    std::vector<val_t> vs(n);
    std::iota(vs.begin(), vs.end(), 0);

    if(gen) { std::shuffle(vs.begin(), vs.end(), *gen); }

    ads::set<val_t> a;

    double elapsed_insert;
    {
        auto start = std::chrono::high_resolution_clock::now();
        a.insert(vs.begin(), vs.end());
        auto end = std::chrono::high_resolution_clock::now();

        elapsed_insert = std::chrono::duration<double, std::milli>(end - start).count();
    }

    if(a.size() != n) {
        std::cerr << RED("[stresstest1] err: wrong size, expected " << n << " but is " << a.size()) << '\n';
        std::abort();
    }

    std::cerr << "elapsed_insert = " << elapsed_insert << " ms\n";
    if(gen) { std::shuffle(vs.begin(), vs.end(), *gen); }

    double elapsed_count;
    {
        auto start = std::chrono::high_resolution_clock::now();
        for(auto const& v: vs) {
            if(!a.count(v)) {
                std::cerr << RED("[stresstest1] err: missing value " << v << '\n');
                std::abort();
            }
        }
        auto end = std::chrono::high_resolution_clock::now();

        elapsed_count = std::chrono::duration<double, std::milli>(end - start).count();
    }

    std::cerr << "elapsed_count  = " << elapsed_count  << " ms\n";
}

#ifdef PH2
void do_stresstest2(RNG* const gen) {
    std::cerr << "\n=== stresstest2 " << (gen ? "(randomized) " : "") << "===\n";

    size_t const n = 1'000'000;
    std::vector<val_t> vs(n);
    std::iota(vs.begin(), vs.end(), 0);

    if(gen) { std::shuffle(vs.begin(), vs.end(), *gen); }

    ads::set<val_t> a;

    double elapsed_insert;
    {
        auto start = std::chrono::high_resolution_clock::now();
        for(auto const& v: vs) {
            if(!a.insert(v).second) {
                std::cerr << RED("[stresstest2] err: returned wrong insertion status (false) for value " << v << '\n');
                std::abort();
            }
        }
        auto end = std::chrono::high_resolution_clock::now();

        elapsed_insert = std::chrono::duration<double, std::milli>(end - start).count();
    }

    if(a.size() != n) {
        std::cerr << RED("[stresstest2] err: wrong size, expected " << n << " but is " << a.size()) << '\n';
        std::abort();
    }

    std::cerr << "elapsed_insert = " << elapsed_insert << " ms\n";
    if(gen) { std::shuffle(vs.begin(), vs.end(), *gen); }

    double elapsed_count;
    {
        auto start = std::chrono::high_resolution_clock::now();
        for(auto const& v: vs) {
            if(!a.count(v)) {
                std::cerr << RED("[stresstest2] err: missing value " << v << '\n');
                std::abort();
            }
        }
        auto end = std::chrono::high_resolution_clock::now();

        elapsed_count = std::chrono::duration<double, std::milli>(end - start).count();
    }

    std::cerr << "elapsed_count  = " << elapsed_count  << " ms\n";
    if(gen) { std::shuffle(vs.begin(), vs.end(), *gen); }

    double elapsed_find;
    {
        auto start = std::chrono::high_resolution_clock::now();
        for(auto const& v: vs) {
            if(a.find(v) == a.end()) {
                std::cerr << RED("[stresstest2] err: missing value " << v << '\n');
                std::abort();
            }
        }
        auto end = std::chrono::high_resolution_clock::now();

        elapsed_find = std::chrono::duration<double, std::milli>(end - start).count();
    }

    std::cerr << "elapsed_find   = " << elapsed_find  << " ms\n";

    if(!gen) {
        double elapsed_iter;
        size_t i = 0;
        {
            auto start = std::chrono::high_resolution_clock::now();
            for(auto it = a.begin(); it != a.end(); (i % 2 ? ++it : it++), ++i) {
                auto it_f = a.find(*it);

                if(!it_equal(a, it, a, it_f)) {
                    std::cerr << RED("[stresstest2] err: iterator from iterator loop does not match find iterator\n");
                    std::abort();
                }
            }
            auto end = std::chrono::high_resolution_clock::now();

            elapsed_iter = std::chrono::duration<double, std::milli>(end - start).count();
        }

        if(i != n) {
            std::cerr << RED("[stresstest2] err: iterator loop ran " << i << " times instead of the expected " << n << " times.\n");
            std::abort();
        }
        std::cerr << "elapsed_iter   = " << elapsed_iter << " ms\n";
    }

    if(gen) { std::shuffle(vs.begin(), vs.end(), *gen); }

    double elapsed_erase;
    {
        auto start = std::chrono::high_resolution_clock::now();
        for(auto const& v: vs) {
            if(!a.erase(v)) {
                std::cerr << RED("[stresstest2] err: couldn't erase element " << v << '\n');
                std::abort();
            }
        }
        auto end = std::chrono::high_resolution_clock::now();

        elapsed_erase = std::chrono::duration<double, std::milli>(end - start).count();
    }

    if(!a.empty() || a.size()) {
        std::cerr << RED("[stresstest2] err: not empty after erasing everything\n");
        std::abort();
    }

    std::cerr << "elapsed_erase  = " << elapsed_erase  << " ms\n";
}
#endif

/* zeit möglicherweise zu knapp bemessen für container mit pervers
 * kleinem default N. (-D SIZE) */
void stresstest(RNG* const gen = nullptr) {
#ifdef BST
    if(!gen) { return; }
#endif

    try {
        auto f = std::async(std::launch::async, do_stresstest1, gen);

        unsigned d = 1000 + (gen ? 2 : 0);
        if(f.wait_for(std::chrono::seconds(d)) == std::future_status::timeout) {
            std::cerr << YELLOW("[stresstest1] timeout: exceeded " << d << "s timeframe.\n");
            std::abort();
        }

#ifdef PH2
        auto g = std::async(std::launch::async, do_stresstest2, gen);

        if(g.wait_for(std::chrono::seconds(d + 2)) == std::future_status::timeout) {
            std::cerr << YELLOW("[stresstest2] timeout: exceeded " << d << "s timeframe.\n");
            std::abort();
        }
#endif
    } catch(std::system_error const&) {
        std::cout << BLUE("stresstest disabled because no multithreading available. compile with -pthread to enable.");
    }
}

#ifndef N
#define N 10
#endif

#ifndef M
#define M 10
#endif

#ifndef O
#define O 100
#endif

#ifndef V
#define V 10
#endif

#ifndef W
#define W 10
#endif

#ifndef X
#define X 100
#endif

#ifndef S
#define S 666
#endif

#ifndef T
#define T 1
#endif

int main(int argc, char** argv) {
    size_t n = N;
    size_t m = M;
    size_t o = O;

    size_t v = V;
    size_t w = W;
    size_t x = X;

    size_t s = S;
    size_t t = T;

    bool only_benchmark = false;
    bool no_benchmark = false;

    char c;
    while((c = getopt(argc, argv, "n:m:o:v:w:x:s:t:bBh")) != -1) {
        switch(c) {
            case 'n':
                n = std::atoll(optarg);
                std::cout << "n = " << n << '\n';
                break;
            case 'm':
                m = std::atoll(optarg);
                std::cout << "m = " << m << '\n';
                break;
            case 'o':
                o = std::atoll(optarg);
                std::cout << "o = " << o << '\n';
                break;
            case 'v':
                v = std::atoll(optarg);
                std::cout << "v = " << v << '\n';
                break;
            case 'w':
                w = std::atoll(optarg);
                std::cout << "w = " << w << '\n';
                break;
            case 'x':
                x = std::atoll(optarg);
                std::cout << "x = " << x << '\n';
                break;
            case 's':
                s = std::atoll(optarg);
                std::cout << "s = " << s << '\n';
                break;
            case 't':
                t = std::atoll(optarg);
                std::cout << "t = " << t << '\n';
                break;
            case 'b':
                only_benchmark = true;
                std::cout << "benchmark only\n";
                break;
            case 'B':
                no_benchmark = true;
                std::cout << "no benchmark\n";
                break;
            case 'h':
            default:
                std::cout << "usage: " << argv[0] << " opts\n"
                          << "where opt in opts is one of the following:\n\n"

                          << "  -n $value ... number of values for first test, default: " << N << '\n'
                          << "  -m $value ... stepsize for n, default: " << M << '\n'
                          << "  -o $value ... maximum value for n, default: " << O << '\n'
                          << "  -v $value ... maximum value for first test, default: " << V << '\n'
                          << "  -w $value ... stepsize for v, default: " << W << '\n'
                          << "  -x $value ... maxmimum value for v, default: " << X << '\n'
                          << "  -s $value ... first seed, default: " << S << '\n'
                          << "  -t $value ... number of seeds (will be drawn from rng w/ previous seed), default: " << T << '\n'
                          << "                will do the full test suite t times!\n"
                          << "  -b        ... only do benchmark\n"
                          << "  -B        ... don't do benchmark\n"
                          << "  -h        ... this message\n\n"

                          << "btest is a gluten free program that will try to find a simple way to mess an ADS_set up. it should theoretically\n"
                          << "touch upon the full functionality, but is of course not capable of finding all possible error cases.\n";
                std::exit(-1);
        }
    }

    std::mt19937_64 gen{ s };
    if(only_benchmark) {
        stresstest();
        stresstest(&gen);

        return 0;
    }

    test_initlist_constructor1();
    test_range_constructor1();

    test_initlist_constructor2();
    test_range_constructor2();

    for(size_t i = 0; i < t; ++i) {
        for(size_t n_ = n; n_ <= o; n_ += m) {
            for(size_t v_ = v; v_ <= x; v_ += w) {
                std::cerr << "seed = " << s << "\nn = " << n_ << "\nv = " << v_ << '\n';
#ifdef PH2
                test_all_ph1(n_, v_, gen);
                test_all_ph2(n_, v_, gen);
#else
                test_all_ph1(n_, v_, gen);
#endif
                std::cerr << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            }
        }

        s = gen();
        gen.seed(s);
    }

    if(no_benchmark) { return 0; }
    if(RUNNING_ON_VALGRIND) {
        std::cerr << CYAN("NOTE: ") << "stresstest disabled because program is running under valgrind.\n";
    } else {
        stresstest();
        stresstest(&gen);
    }

    std::cout << GREEN("\nOK\n");
}
