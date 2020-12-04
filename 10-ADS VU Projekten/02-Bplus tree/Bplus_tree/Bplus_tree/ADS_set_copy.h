#ifndef ADS_SET_H
#define ADS_SET_H
/*
    https://cewebs.cs.univie.ac.at/ADS/ws20/index.php?m=D&t=schriftlichertest&c=show&CEWebS_what=Projekt
    https://cewebs.cs.univie.ac.at/ADS/ws20/index.php?m=D&t=schriftlichertest&c=show&CEWebS_what=Spezifikation
    https://www.youtube.com/watch?v=4ZG4Smk-tTM
*/
#include <functional>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <stack>

template < typename Key, size_t N= 0>
class ADS_set {
    public:
        class Iterator;
        using value_type = Key;
        using key_type = Key;
        using reference = key_type&;
        using const_reference = const key_type&;
        using size_type = size_t;
        using difference_type = std::ptrdiff_t;
        using iterator = Iterator;
        using const_iterator = Iterator;
        using key_compare = std::less<key_type>;          // B+-Tree
        using key_equal = std::equal_to<key_type>;        // Hashing
        using hasher = std::hash<key_type>;               // Hashing

    private:
        static constexpr size_type MAX_Order{ N };
        static constexpr size_type MAX_Children{ N };
        static constexpr size_type MIN_Children{ 2 };
        static constexpr size_type MAX_Keys{ N-1 };
        static constexpr size_type MIN_Keys{ 1 };

        struct Node; using Link = Node *;
        struct Node {
            key_type *key; 
            Link *link;
            bool is_leaf;
            Node(key_type *akey = nullptr, Link alink = nullptr, bool leaf = false) : 
                key(akey), link(alink), is_leaf(leaf) 
            {}
            ~Node() { delete link; delete key; }
        }; 
        Link root {nullptr};
        size_t sz {0};

        static Link clone(Link link) {
            return link ? new Node(link->key, clone(link->link), link->leaf)) : nullptr;
        }
        /*
        static Link &find(const key_type &key, Link &link) {
            if (!link || key_equal{}(link->key,key)) return link;
            return find(key, key_compare{}(key, link->key) ? link->left : link->right);
        }
        static void dump(Link link, std::ostream &o, size_t ind = 0) {
            if (!link) return;
            dump(link->right, o, ind+1);
            o << std::setw(ind*4) << "" << link->key << '\n';
            dump(link->left, o, ind+1);
        }
        static Link unlink_min(Link &link) {
            if (link->left) return unlink_min(link->left);
            Link min_link {link};
            link = min_link->right;
            min_link->right = nullptr;
            return min_link;
        }
        static Link unlink(Link &link) {
            Link old_link {link};
            if (!old_link->left) {
              link = old_link->right;
            } else if (!old_link->right) {
              link = old_link->left;
            } else {
              link = unlink_min(link->right);
              link->left = old_link->left;
              link->right = old_link->right;
            }
            old_link->left = old_link->right = nullptr;
            return old_link;
        }
        
        size_type erase_key(const key_type &key) {
            if (Link &link {find(key, root)}) {
              delete unlink(link);
              --sz;
              return 1;
            }
            return 0;
        }
        Link insert_key(const key_type &key) {
            Link &link {find(key, root)};
            if (!link) {
              link = new Node(key);
              ++sz;
            }
            return link;
        }
        Link find_key(const key_type &key) const {
            Link root_copy {root};
            return find(key, root_copy);
        }
        */
    public:
        // [Phase 1]-Default constructor
        ADS_set() {}                                                                            
        // [Phase 1]-Initializer list constructor. The elements are inserted in the order specified in ilist.
        ADS_set(std::initializer_list<key_type> ilist) {  
            insert(ilist); 
        }
        // [Phase 1]-Range constructor.Creates a container that contains the elements from the[first, last[area.
        //         The elements are inserted in the specified order(starting with first).
        template<typename InputIt> ADS_set(InputIt first, InputIt last) { 
            insert(first, last); 
        }
        
        //Copy constructor
        ADS_set(const ADS_set &other) {
            root = clone(other.root);
            sz = other.sz;
        }
        ~ADS_set() { delete root; root = nullptr; }
        
        /*
        ADS_set &operator=(const ADS_set &other) {
            if (this == &other) return *this;
            delete root;
            root = clone(other.root);
            sz = other.sz;
            return *this;
        }
        */
        /*
        ADS_set &operator=(std::initializer_list<key_type> ilist) {
            clear();
            insert(ilist);
            return *this;
        }
        */
        //[Phase 1]-Number of items stored in the container
        size_type size() const { 
            return sz; 
        }
        //[Phase 1]-true if size () == 0, otherwise false
        bool empty() const     { 
            return !sz; 
        }
        //Inserts the elements from ilist. The elements are inserted in the order specified in ilist
        void insert(std::initializer_list<key_type> ilist) { 
            for (const key_type &key: ilist) insert_key(key); 
        }
        /*
            Inserts key.
            Return value: A std :: pair, consisting of an iterator and a bool.
            iterator: points to the inserted element, if an element was inserted, 
            or to the existing element with the same key, if no element was inserted.
            bool: true if an element was inserted, otherwise false.
        */
        std::pair<iterator,bool> insert(const key_type &key) {
            size_type sz_before {sz};
            Link link {insert_key(key)};
            return {const_iterator{root, link}, sz != sz_before};
        }
        
        template<typename InputIt> void insert(InputIt first, InputIt last) { 
            while (first != last) insert_key(*first++); 
        }

        void clear() { delete root; root = nullptr; sz = 0; }
        size_type erase(const key_type &key) { return erase_key(key); }

        void swap(ADS_set &other) {
            std::swap(root, other.root);
            std::swap(sz, other.sz);
        }
        //[Phase 1]-Return value : The number of elements in the container with key key(0 or 1)
        size_type count(const key_type &key) const { return !!find_key(key); }
        /*
        iterator find(const key_type &key) const {
            if (Link link {find_key(key)}) return const_iterator{root, link};
            return end();
        }
        */
        const_iterator begin() const { return const_iterator{root}; }
        const_iterator end() const { return const_iterator{}; }
        /*[Phase 1]
        * In the event of errors, the unit test outputs the contents of the container 
        * using this method in order to facilitate troubleshooting. However, if the output is too extensive, 
        * it can be shortened during the unit test. It can be assumed that during the unit test the container is 
        * only instantiated with element data types (key_type) that support the output operator (<<).
        */
        void dump(std::ostream &o = std::cerr) const { dump(root, o); }

        // Operators --------------------------------------------------------------------------------------------
        friend bool operator==(const ADS_set &lhs, const ADS_set &rhs) { 
            if (lhs.size() != rhs.size()) return false;
            auto lhs_it {lhs.begin()};
            auto rhs_it {rhs.begin()};
            for ( ; lhs_it != lhs.end(); ++lhs_it, ++rhs_it) if (!key_equal{}(*lhs_it, *rhs_it)) return false;
            return true;
        }
        friend bool operator!=(const ADS_set &lhs, const ADS_set &rhs) { 
            return !(lhs==rhs); 
        }
  */
};


template <typename Key, size_t N>
    void swap(ADS_set<Key,N> &lhs, ADS_set<Key,N> &rhs) { lhs.swap(rhs); }

template <typename Key, size_t N> class ADS_set<Key,N>::Iterator {
        std::stack<Link> path;
    
    public:
        using value_type = Key;
        using difference_type = std::ptrdiff_t;
        using reference = const value_type &;
        using pointer = const value_type *;
        using iterator_category = std::forward_iterator_tag;

        explicit Iterator(Link root = nullptr, Link current = nullptr) {
            if (!root) return; // end
            if (!current) {    // begin
                path.push(root);
                while (path.top()->left) path.push(path.top()->left);
                return;
            }   
            Link link{ root };
            while (link != current) {
              if (key_compare{}(current->key, link->key)) {
                path.push(link);
                link = link->left;
              } else {
                link = link->right;
              }
            }
            path.push(link);
          }
        reference operator*() const       { return path.top()->key; }
        pointer operator->() const        { return &path.top()->key; }
        Iterator &operator++() {
            Link old_top {path.top()};
            path.pop();
            if (old_top->right) {
                path.push(old_top->right);
                while (path.top()->left) path.push(path.top()->left);
            }
            return *this;
        }
        Iterator operator++(int) { Iterator tmp{*this}; ++*this; return tmp; }
        friend bool operator==(const Iterator &lhs, const Iterator &rhs) { 
            return lhs.path.size() == rhs.path.size() && (lhs.path.empty() || lhs.path.top() == rhs.path.top()); 
        }
        friend bool operator!=(const Iterator &lhs, const Iterator &rhs) { return !(lhs == rhs); }
};

#endif // ADS_SET_H
