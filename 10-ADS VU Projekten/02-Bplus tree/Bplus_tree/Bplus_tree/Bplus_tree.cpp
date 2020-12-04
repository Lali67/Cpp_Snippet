/* Bplus_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
    https://www.guru99.com/introduction-b-plus-tree.html
    https://cewebs.cs.univie.ac.at/ADS/ws20/index.php?m=D&t=schriftlichertest&c=show&CEWebS_what=Projekt
    https://cewebs.cs.univie.ac.at/ADS/ws20/index.php?m=D&t=schriftlichertest&c=show&CEWebS_what=Spezifikation
    https://www.youtube.com/watch?v=4ZG4Smk-tTM
*/

#include <functional>
#include <iostream> 
#include <vector>
#include "ADS_set.h"

using namespace std;

class Person {
    std::string vn;
    std::string nn;
public:
    Person() = default;
    Person(const std::string& vn, const std::string& nn) : vn{ vn }, nn{ nn } { }
    friend struct std::hash<Person>;
    friend struct std::equal_to<Person>;
    friend struct std::less<Person>;
    friend std::ostream& operator<<(std::ostream& o, const Person& p) { return o << '[' << p.nn << ", " << p.vn << ']'; }
    friend std::istream& operator>>(std::istream& i, Person& p) { return i >> p.vn >> p.nn; }
};

template <> struct hash<Person> {
    size_t operator()(const Person& p) const {
        return std::hash<std::string>{}(p.vn) ^ std::hash<std::string>{}(p.nn) << 1;
    }
};
template <> struct equal_to<Person> {
    bool operator()(const Person& lhs, const Person& rhs) const {
        return lhs.vn == rhs.vn && lhs.nn == rhs.nn;
    }
};
template <> struct less<Person> {
    bool operator()(const Person& lhs, const Person& rhs) const {
        return lhs.nn < rhs.nn || (lhs.nn == rhs.nn && lhs.vn < rhs.vn);
    }
};


int main()
{
    
    // [Phase 1]-Default constructor test
    ADS_set<double> temp_dct;
    std::cout << "Default constructor test--------------------------------- "  << endl;
    std::cout << "dump: " << endl;
    temp_dct.dump();
    std::cout << "size: " << temp_dct.size() << endl;
    std::cout << "empty: " << temp_dct.empty() << endl;
    std::cout << "count: " << temp_dct.count(5.5) << endl;
    std::cout << endl;
   
    // [Phase 1]-Initializer list constructor. The elements are inserted in the order specified in ilist.
    cout << "Initializer list constructor--------------------------------- " << endl;
    ADS_set<long,1> temp_il;
    std::initializer_list<long> il = { 5,15,25,35,45,55,40,30,20 };
    temp_il.insert(il);
    cout << "dump {... }: " << endl;
    temp_il.dump();
    cout << "size: " << temp_il.size() << endl;
    cout << "empty: " << temp_il.empty() << endl;
    std::cout << "count(56589): " << temp_il.count(82445) << endl;
    std::cout << "count(23): " << temp_il.count(23) << endl;
    cout << endl;
        
    ADS_set<Person> temp_il2;
    cout << "Initializer list constructor with Person--------------------------------- " << endl;
    temp_il2.insert({ Person("aa", "bb"), Person("cc", "dd"), Person("aa", "cb"), Person("ee", "ff") });
    temp_il2.dump();
    cout << "size: " << temp_il2.size() << endl;
    cout << "empty: " << temp_il2.empty() << endl;
    std::cout << "count(Person(cc, dd)): " << temp_il2.count(Person("cc", "dd")) << endl;
    std::cout << "count(Person(cc, aa)): " << temp_il2.count(Person("cc", "aa")) << endl;
    cout << endl;

}


