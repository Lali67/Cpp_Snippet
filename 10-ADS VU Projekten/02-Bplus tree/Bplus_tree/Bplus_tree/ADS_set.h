#ifndef ADS_SET_H
#define ADS_SET_H

#include <functional>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <queue>

//#define DEBUG 

/******************************************************************************
        class Vector
*******************************************************************************/
template <typename T> class Vector {

public:
    class ConstIterator;
    class Iterator;
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = Vector<value_type>::Iterator;
    using const_iterator = Vector<value_type>::ConstIterator;

public:
    class Iterator {
    public:
        using value_type = Vector::value_type;
        using reference = Vector::reference;
        using pointer = Vector::pointer;
        using difference_type = Vector::difference_type;
        using iterator_category = std::forward_iterator_tag;

    private:
        pointer ptr;

    public:
        Iterator() :ptr(nullptr) { }
        Iterator(pointer optr) :ptr(optr) { }
        Iterator(const Iterator& obj) { ptr = obj.ptr; }

        reference operator * () { return *ptr; }
        pointer operator -> () { return ptr; }
        bool operator == (const iterator& rhs) { return rhs.ptr == ptr; }
        bool operator != (const iterator& rhs) { return rhs.ptr != ptr; }
        iterator& operator ++ () { ++(ptr); return *this; }								// (Prefix)
        iterator operator ++ (int) { iterator temp(ptr); ptr = ++(ptr); return temp; }	// (Postfix)
        iterator& operator -- () { --(ptr); return *this; }								// (Prefix)
        iterator operator -- (int) { iterator temp(ptr); ptr = --(ptr); return temp; }	// (Postfix)
        operator const_iterator() { return  ptr; };

        friend bool operator == (const iterator& lhs, const iterator& rhs)
        {
            return lhs.ptr == rhs.ptr;
        }
        friend bool operator != (const iterator& lhs, const iterator& rhs)
        {
            return lhs.ptr != rhs.ptr;
        }
        friend std::ostream& operator << (std::ostream& os, const Iterator& p)
        {
            os << "Iterator class: " << p.ptr << "\n"; return os;
        }
    }; //end of class Iterator

    class ConstIterator {
    public:
        using value_type = Vector::value_type;
        using reference = Vector::const_reference;
        using pointer = Vector::const_pointer;
        using difference_type = Vector::difference_type;
        using iterator_category = std::forward_iterator_tag;

    private:
        pointer ptr;

    public:
        ConstIterator() :ptr(nullptr) {}
        ConstIterator(pointer optr) : ptr(optr) {}
        ConstIterator(const ConstIterator& obj) : ptr(obj.ptr) {}
        ConstIterator(const Iterator& obj) { Iterator* p = const_cast<Iterator*>(&obj); ptr = (p->operator->()); }

        reference operator * () { reference temp = *ptr; return temp; }
        pointer operator -> () const { return ptr; }
        bool operator == (const const_iterator& rhs) { return rhs.ptr == ptr; }
        bool operator != (const const_iterator& rhs) { return rhs.ptr != ptr; }
        const_iterator& operator ++ () { ++(ptr); return *this; }
        const_iterator operator ++ (int) { ConstIterator temp(ptr); ptr = ++(ptr); return temp; };
        const_iterator& operator -- () { --(ptr); return *this; }								// (Prefix)
        const_iterator operator -- (int) { iterator temp(ptr); ptr = --(ptr); return temp; }	// (Postfix)

        friend bool operator == (const const_iterator& lhs, const const_iterator& rhs)
        {
            return lhs.ptr == rhs.ptr;
        }
        friend bool operator != (const const_iterator& lhs, const const_iterator& rhs)
        {
            return lhs.ptr != rhs.ptr;
        }
        friend difference_type operator - (const Vector::ConstIterator& lop, const Vector::ConstIterator& rop)
        {
            return lop.ptr - rop.ptr;
        }
        friend std::ostream& operator << (std::ostream& os, const ConstIterator& p)
        {
            os << "ConstIterator class: " << p.ptr << "\n"; return os;
        }
    }; //end of class ConstIterator

private:
    static constexpr size_type min_sz{ 5 };				//Mindestgroesse (5) fuer max_sz festlegt einfuehren
    size_type		sz;									//Anzahl der Elemente im Vector
    size_type		max_sz;								//maximale Anzahl an Elementen die	moeglich sind
    pointer			values;								//Zeigt auf ein Feld, welches die Elemente des Vectors beinhaltet

public:
    Vector() :Vector(min_sz) {}							//Liefert einen leeren Vector
    Vector(size_type n)									//Liefert einen Vector mit Platz fuer n Elemente
    {
        sz = 0;
        max_sz = n < min_sz ? min_sz : n;
        values = new value_type[max_sz];
    }
    Vector(std::initializer_list<value_type> arr_list)	//Liefert einen Vector mit spezifiziertem Inhalt
    {
        sz = 0;
        max_sz = arr_list.size() + min_sz;
        values = new value_type[max_sz];
        for (const_reference item : arr_list)			//Range-Based-For-Loop iteration
            push_back(item);
    }
    Vector(const Vector& obj)							//Kopierkonstruktor: Liefert einen Vector mit demselben Inhalt
    {
        sz = obj.sz;
        max_sz = obj.max_sz;
        values = obj.values;
    }

    //--------- Methoden für Iteratoren ---------
    iterator begin()
    {
        return iterator(values);
    }
    iterator end()
    {
        return iterator(values + sz);
    }
    const_iterator begin() const
    {
        return const_iterator(values);
    }
    const_iterator end() const
    {
        return const_iterator(values + sz);
    }

    //--------- Methoden für Vector Klasse---------
    size_type size() const							//liefert die Anzahl der gespeicherten Elemente
    {
        return sz;
    }
    bool empty() const								//liefert true, falls der Vektor leer ist, false sonst
    {
        if (sz == 0) return true;
        else return false;
    }
    void clear()									//Loescht alle Elemente aus dem Vector
    {
        sz = 0;
    }
    void reserve(size_type n)						//Kapazitaet des Vectors wird auf n vergroessert, falls noetig
    {
        size_type newCapacity = n;
        if (newCapacity < max_sz)
            return;

        pointer newArray = new value_type[newCapacity];
        for (size_type k = 0; k < max_sz; ++k)
            newArray[k] = values[k];

        max_sz = newCapacity;
        std::swap(values, newArray);
        delete[] newArray;
    }
    void shrink_to_fit()							//Kapazitaet wird auf Anzahl der Elemente reduziert
    {
        if (sz == max_sz)
            return;

        pointer newArray = new value_type[sz];
        for (int k = 0; k < sz; ++k)
            newArray[k] = values[k];
        delete[] values;

        values = new value_type[sz];
        for (int k = 0; k < sz; ++k)
            values[k] = newArray[k];
        delete[] newArray;

        max_sz = sz + min_sz;
    }
    void push_back(value_type x)						//Fuegt eine Kopie von x am Ende des Vectors hinzu
    {
        if (sz == max_sz)
            reserve(2 * max_sz);
        values[sz] = x;
        ++sz;
    }
    void pop_back()									//Entfernt das letzte Element im Vector Wirfteine Exception falls der Vector leer war
    {
        if (sz == 0)
            throw std::out_of_range("pop_back() : index is out of range");
        sz--;
    }
    size_t capacity() const							//Retourniert aktuelle Kapazitaet des Vectors
    {
        return max_sz;
    }

    iterator insert(const_iterator pos, const_reference val) {
        auto diff = pos - begin();
        if (diff < 0 || static_cast<size_type>(diff) > sz)
            throw std::runtime_error("Iterator out of bounds");
        size_type current{ static_cast<size_type>(diff) };
        if (sz >= max_sz)
            reserve(max_sz * 2); //max_sz*2+10, wenn Ihr Container max_sz==0 erlaubt
        for (size_type i{ sz }; i-- > current;)
            values[i + 1] = values[i];
        values[current] = val;
        ++sz;
        return iterator{ values + current };
    }

    iterator erase(const_iterator pos) {
        auto diff = pos - begin();
        if (diff < 0 || static_cast<size_type>(diff) >= sz)
            throw std::runtime_error("Iterator out of bounds");
        size_type current{ static_cast<size_type>(diff) };
        for (size_type i{ current }; i < sz - 1; ++i)
            values[i] = values[i + 1];
        --sz;
        return iterator{ values + current };
    }
    reference       front()             { return *this->begin(); }
    const_reference front() const       { return *this->begin(); }
    reference       back()              { return *(--this->end()); }
    const_reference back() const        { return *(--this->end()); }

    //--------- Operators---------
    void operator = (const Vector& other)			//Das this-Objekt uebernimmt die Werte vom Parameter
    {
        sz = 0;
        for (size_type k = 0; k < other.sz; ++k)
            push_back(other.values[k]);
    }
    reference operator [] (size_t index)				//Abgesichert, retourniert das	Element an der gegebenen Position(index)
    {
        if (index < 0 || index >= size())
            throw std::out_of_range("operator [] : index is out of range");
        return values[index];
    }
    const_reference operator [] (size_t index) const	// Abgesichert, retourniert das Element an gegebener Position (index)
    {
        if (index < 0 || index >= size())
            throw std::out_of_range("operator [] : index is out of range");
        return values[index];
    }
    pointer operator -> () const { return values; }
    pointer operator -> () { return values; }

    friend std::ostream& operator << (std::ostream& os, const Vector<value_type>& v) {
        os << '[';
        bool first{ true };
        for (size_type i{ 0 }; i < v.size(); ++i) {
            if (first) first = false;
            else os << ", ";
            os << v.values[i];
        }
        os << ']';

        return os;
    }

    ~Vector()
    {
        delete[] values;
        values = nullptr;
    }
};
/******************************************************************************
        class Record
*******************************************************************************/
template <typename T> class Record {
public:
    using nKeyType = T;
    using nValueType = T;
public:
    explicit Record(nValueType aValue) : fValue(aValue) {};
    nValueType value() const { return fValue; };
    void setValue(nValueType aValue) { fValue = aValue; };
private:
    Record() : fValue(0) {};
    nValueType fValue;
};

/******************************************************************************
         class Node (Base class)
*******************************************************************************/
template <typename T> class Node {
private:
    const int   fOrder;
    Node* fParent;
    bool is_leaf;

public:

    using nKeyType = T;
    using nValueType = T;

    explicit Node(int aOrder, bool b_is_leaf) : 
            fOrder{ aOrder }, fParent{ nullptr }, is_leaf{ b_is_leaf } {};
    explicit Node(int aOrder, Node* aParent, bool b_is_leaf) : 
            fOrder{ aOrder }, fParent{ aParent }, is_leaf{ b_is_leaf } {};
    virtual ~Node() {};

    int order() const { return fOrder; };
    Node* parent() const { return fParent; };
    void setParent(Node* aParent) { fParent = aParent; };
    bool isRoot() const { return !fParent; };
    bool isLeaf() const { return is_leaf; };

    virtual int size() const { return 0; };
    virtual int minSize() const { return order() / 2; };
    virtual int maxSize() const { return order() - 1; };
    virtual const nKeyType firstKey() const { return nKeyType(); };
    virtual std::ostream& toString(std::ostream& o, bool extended) const {
        if (extended) {
            o << "Node base: <" << std::hex << this << std::dec << "> ";
        }
        return o; 
    };
};

/******************************************************************************
        class LeafNode : public Node<T>
*******************************************************************************/
template <typename T> class InternalNode;
template <typename T> class LeafNode : public Node<T> {
    public:
        using nKeyType = typename Node<T>::nKeyType;
        using nValueType = typename Node<T>::nValueType;
        using key_equal = std::equal_to<T>;
        using key_compare = std::less<T>;
        using mapping_type = std::pair<nKeyType, Record<T>*>;

    private:
        Vector<mapping_type> fMappings;
        LeafNode* fNext;

        void copyHalfFrom(Vector<std::pair<nKeyType, Record<T>*> >& aMappings)
            { for (size_t i = minSize(); i < aMappings.size(); ++i) fMappings.push_back(aMappings[i]); }
        
        void copyAllFrom(Vector<std::pair<nKeyType, Record<T>*> >& aMappings)
            { for (auto mapping : aMappings) fMappings.push_back(mapping); }

        void copyLastFrom(mapping_type aPair) { fMappings.push_back(aPair); }

        void copyFirstFrom(mapping_type aPair, int aParentIndex)
        {
            fMappings.insert(fMappings.begin(), aPair);
            static_cast<InternalNode<T>*>(Node<T>::parent())->setKeyAt(aParentIndex, fMappings.front().first);
        }

    public:
        explicit LeafNode(int aOrder) : Node<T>(aOrder, true), fNext(nullptr) {};
        explicit LeafNode(int aOrder, Node<T>* aParent) : Node<T>(aOrder, aParent, true), fNext(nullptr) {}
        ~LeafNode() override { for (auto& mapping : fMappings) delete mapping.second; }

        const Vector<mapping_type>& getKeysVector() { return fMappings; };

        //----- functions for Insert 
        LeafNode* next() const { return fNext; }
        void setNext(LeafNode* aNext) { fNext = aNext; }
        
        void moveHalfTo(LeafNode* inner)
        {
            inner->copyHalfFrom(fMappings);
            size_t size = fMappings.size();
            for (size_t i = minSize(); i < size; ++i) {
                fMappings.pop_back();
            }
#ifdef DEBUG
 std::cout << "\t\tkey(" << __LINE__ << ")LeafNode->moveHalfTo: "; toString(std::cout) << "\n";
#endif // DEBUG
        };

        void moveAllTo(LeafNode* aRecipient, int)
        {
            aRecipient->copyAllFrom(fMappings);
            fMappings.clear();
            aRecipient->setNext(next());
        }

        int createAndInsertRecord(nKeyType aKey, nValueType aValue) {
            Record<T>* existingRecord = lookup(aKey);
            if (!existingRecord) {
                Record<T>* newRecord = new Record<T>(aValue);
                insert(aKey, newRecord);
            }
#ifdef DEBUG
std::cout << "\t\tkey(" << __LINE__ << ")LeafNode->createAndInsertRecord: "; toString(std::cout) << "\n";
#endif // DEBUG          
            return static_cast<int>(fMappings.size());
        };

        void insert(nKeyType aKey, Record<T>* aRecord)
        {
            auto insertionPoint = fMappings.begin();
            auto end = fMappings.end();
            for (auto it = fMappings.begin(); it != end; it++) {
                if (key_compare{}(static_cast<nKeyType>(it->first), aKey)) 
                    break;
                insertionPoint++;
            }
            insertionPoint;
            fMappings.insert(insertionPoint, mapping_type(aKey, aRecord));
        };

        Record<T>* lookup(nKeyType aKey) const
        {
            for (auto mapping : fMappings) {
                if (key_equal{}(static_cast<nKeyType>(mapping.first), aKey)) {
#ifdef DEBUG
std::cout << "\tkey(" << __LINE__ << ")LeafNode->lookup: "; toString(std::cout) << "\n";
#endif // DEBUG             
                    return mapping.second;
                }
            }
            return nullptr;
        };

        //----- functions for Erase------------------------------------------------
        int removeAndDeleteRecord(nKeyType aKey)
        {
            auto removalPoint = fMappings.begin();
            auto end = fMappings.end();
            while (removalPoint != end && !key_equal{}(removalPoint->first, aKey)) {
                ++removalPoint;
            }
            if (removalPoint == end) {
                throw ("Not found key in removeAndDeleteRecord");
            }
            auto record = *removalPoint;
            fMappings.erase(removalPoint);
            delete record.second;
            return static_cast<int>(fMappings.size());
        };
        
        void moveFirstToEndOf(LeafNode* aRecipient)
        {
            aRecipient->copyLastFrom(fMappings.front());
            fMappings.erase(fMappings.begin());
            static_cast<InternalNode<T>*>(Node<T>::parent())->setKeyAt(1, fMappings.front().first);
        }

        void moveLastToFrontOf(LeafNode* aRecipient, int aParentIndex)
        {
            aRecipient->copyFirstFrom(fMappings.back(), aParentIndex);
            fMappings.pop_back();
        }

        int size() const        { return static_cast<int>(fMappings.size()); }
        int minSize() const     { return Node<T>::order() / 2; }
        int maxSize() const     { return Node<T>::order() - 1; }
        const nKeyType firstKey() const  { return fMappings[0].first; };

        std::ostream& toString(std::ostream& o = std::cerr, bool extended = false) const {
            if (extended) {
                o << "<" << std::hex << this << std::dec << "> ";
            }
            bool first = true;
            for (auto& mapping : fMappings) {
                if (first) first = false;
                else
                    o << " ";
                o << mapping.first;
            }
            if (extended)  o << " <" << std::hex << fNext << "-> ";
            return o;
        };
};

/******************************************************************************
        class InternalNode : public Node<T>
*******************************************************************************/
template <typename T> class InternalNode : public Node<T>
{
    public:
        using nKeyType = typename  Node<T>::nKeyType;
        using nValueType = typename Node<T>::nValueType;
        using key_equal = std::equal_to<T>;
        using key_compare = std::less<T>;
        using mapping_type = std::pair<nKeyType, Node<T>*>;
        
    private:
        Vector<mapping_type> fMappings;
        nKeyType DUMMY_KEY{};

        void copyHalfFrom(Vector<mapping_type>& aMappings)
        {
            for (size_t i = minSize(); i < aMappings.size(); ++i) {
                aMappings[i].second->setParent(this);
                fMappings.push_back(aMappings[i]);
            }
        };
        
        void copyLastFrom(mapping_type aPair)
        {
            fMappings.push_back(aPair);
            // fMappings.back().first = fMappings.back().second->fMappings.front().first;
            fMappings.back().first = fMappings.back().second->firstKey();
            fMappings.back().second->setParent(this);
        } 

        void copyFirstFrom(mapping_type aPair, int aParentIndex)
        {
            fMappings.front().first = static_cast<InternalNode<T>*>(Node<T>::parent())->keyAt(aParentIndex);
            fMappings.insert(fMappings.begin(), aPair);
            fMappings.front().first = DUMMY_KEY;
            fMappings.front().second->setParent(this);
            static_cast<InternalNode<T>*>(Node<T>::parent())->setKeyAt(aParentIndex, fMappings.front().first);
        }


    public:
        explicit InternalNode(int aOrder) : Node<T>(aOrder, false) {};
        explicit InternalNode(int aOrder, Node<T>* aParent) : Node<T>(aOrder, aParent, false) {};
        ~InternalNode() override { for (auto& mapping : fMappings) delete mapping.second; };

        Node<T>* lookup(nKeyType key) const
        {
            auto locator = fMappings.begin();
            //++ -> should start from 2. element due to problem of key_compare(std::less)
            // with DUMMY_KEY in other compiler
            auto end = fMappings.end();
            while (locator != end && 
                    ( key_compare{}(static_cast<nKeyType>(locator->first), key) || 
                        key_equal{}(static_cast<nKeyType>(locator->first), key) )) {
                ++locator;
            }
            // locator->first is now the least key (k) such that aKey < k.
            // One before is the greatest key (k) such that aKey >= k.
            --locator;
#ifdef DEBUG
            std::cout << "\t\tkey(" << __LINE__ << ")InternalNode->popNodesTo: "; toString(std::cout, true) << "\n";
#endif // DEBUG
            return locator->second;
        }

        void popNodesTo(Node<T>* aOldNode, nKeyType aNewKey, Node<T>* aNewNode) {
            //fMappings.push_back(std::make_pair(DUMMY_KEY, aOldNode));
                fMappings.push_back(std::make_pair(aNewKey, aOldNode));
            fMappings.push_back(std::make_pair(aNewKey, aNewNode));
#ifdef DEBUG
            std::cout << "\t\tkey(" << __LINE__ << ")InternalNode->popNodesTo: "; toString(std::cout, true) << "\n";
#endif // DEBUG
        };

        int insertNodeAfter(Node<T>* aOldNode, nKeyType aNewKey, Node<T>* aNewNode) {
            auto iter = fMappings.begin();
            for (; iter != fMappings.end() && iter->second != aOldNode; ++iter);
            fMappings.insert(++iter, std::make_pair(aNewKey, aNewNode));
            return size();
        };

        nKeyType replaceAndReturnFirstKey() {
            nKeyType newKey = fMappings[0].first;
            fMappings[0].first = DUMMY_KEY;
            return newKey;
        };
        
        Node<T>* removeAndReturnOnlyChild()
        {
            Node<T>* firstChild = fMappings.front().second;
            fMappings.pop_back();
            return firstChild;
        }
        void moveHalfTo(InternalNode* inner)
        {
            inner->copyHalfFrom(fMappings);
            size_t size = fMappings.size();
            for (size_t i = minSize(); i < size; ++i) {
                fMappings.pop_back();
            }
#ifdef DEBUG
            std::cout << "\t\tkey(" << __LINE__ << ")InternalNode->lookup: "; toString(std::cout, true) << "\n";
#endif // DEBUG
        }

        void moveAllTo(InternalNode* aRecipient, int aIndexInParent)
        {
            fMappings[0].first = static_cast<InternalNode*>(Node<T>::parent())->keyAt(aIndexInParent);
            aRecipient->copyAllFrom(fMappings);
            fMappings.clear();
        }
        
        void moveFirstToEndOf(InternalNode<T>* aRecipient)
        {
            aRecipient->copyLastFrom(fMappings.front());
            fMappings.erase(fMappings.begin());
            static_cast<InternalNode<T>*>(Node<T>::parent())->setKeyAt(1, fMappings.front().first);
        }

        void moveLastToFrontOf(InternalNode<T>* aRecipient, int aParentIndex)
        {
            aRecipient->copyFirstFrom(fMappings.back(), aParentIndex);
            fMappings.pop_back();
        }
        
        void copyAllFrom(Vector<mapping_type>& aMappings)
        {
            for (auto mapping : aMappings) {
                mapping.second->setParent(this);
                fMappings.push_back(mapping);
            }
        }
        nKeyType keyAt(int aIndex) const { return fMappings[aIndex].first; }
        void setKeyAt(int aIndex, nKeyType aKey) { fMappings[aIndex].first = aKey; }

        void remove(int aIndex)     { 
            auto it = fMappings.begin();
            for(;it!= fMappings.end() && (aIndex--) != 0; it++)
            fMappings.erase(it); 
        }

        Node<T>* firstChild() const { return fMappings.front().second; }

        int size() const { return static_cast<int>(fMappings.size()); }
        int minSize() const { return (Node<T>::order() + 1) / 2; }
        int maxSize() const {
            // Includes the first entry, which has key DUMMY_KEY and a value that
            // points to the left of the first positive key k1 (i.e., a node whose keys are all < k1).
            return Node<T>::order();
        };
        const nKeyType firstKey() const { return fMappings[1].first; };
        
        int nodeIndex(Node<T>* aNode) const
        {
            for (size_t i = 0; i < size(); ++i) 
                if (fMappings[i].second == aNode) 
                    return static_cast<int>(i);
            return 0;
        }

        Node<T>* neighbor(int aIndex) const
        {
            return fMappings[aIndex].second;
        }

        std::ostream& toString(std::ostream& o = std::cerr, bool extended = false) const
        {
            if (fMappings.empty()) {
                return o;
            }

            if (extended)
                o << "<" << std::hex << this << std::dec << "> ";
            auto entry = extended ? fMappings.begin() : ++fMappings.begin();
            auto end = fMappings.end();
            bool first = true;
            while (entry != end) {
                if (first) first = false;
                else
                    o << " ";
                o << std::dec << entry->first;
                if (extended) o << "(" << std::hex << entry->second << std::dec << ")";
                ++entry;
            }
            return o;
        };
};

/******************************************************************************
        class ADS_set
*******************************************************************************/
template < typename Key, size_t N = 1>
class ADS_set {
    public:
        class Iterator;
        using record = Record<Key>;
        using link_record = Record<Key>*;
        using link_Node = Node<Key>*;
        using link_LeafNode = LeafNode<Key>*;
        using link_LeafInternalNode = InternalNode<Key>*;
        

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
              
        static constexpr size_type fOrder{ 2 * N + 1 };
            
    private:       
        link_Node    fRoot{ nullptr };
        size_t  sz{ 0 };
        
        /*INSERT (private functions related to B+Tree) ******************************************** 
        * 
        *   void insert_key(const key_type& key)
        *       void insertIntoParent(link_Node aOldNode, key_type aKey, link_Node aNewNode)
        * 
        ******************************************************************************************/
        void insertIntoParent(link_Node aOldNode, key_type aKey, link_Node aNewNode)
        {
            link_LeafInternalNode parent = static_cast<link_LeafInternalNode>(aOldNode->parent());
#ifdef DEBUG
std::cout << "\tkey(" << __LINE__ << ")insertIntoParent: " << aKey << "\n";
#endif // DEBUG

            if (parent == nullptr) {
                fRoot = new InternalNode<Key>(fOrder);
                parent = static_cast<link_LeafInternalNode>(fRoot);
                aOldNode->setParent(parent);
                aNewNode->setParent(parent);
                parent->popNodesTo(aOldNode, aKey, aNewNode);
            }
            else {
                
                int newSize = parent->insertNodeAfter(aOldNode, aKey, aNewNode);
                if (newSize > parent->maxSize()) {
                    //link_LeafInternalNode newNode = split(parent);
                    //split
                    link_LeafInternalNode newNode = new InternalNode<Key>(fOrder, parent->parent());
                    parent->moveHalfTo(newNode);
                    //end split
                    key_type newKey = static_cast<key_type>(newNode->replaceAndReturnFirstKey());
                    insertIntoParent(parent, newKey, newNode);
                }
            }
        }

        const link_Node insert_key(const key_type& key){
            if (!fRoot) {
#ifdef DEBUG
    std::cout << "\nkey(" << __LINE__ << ")insert_key: " << key << "\n";
#endif // DEBUG
                link_LeafNode newLeafNode = new LeafNode<Key>(fOrder);
                newLeafNode->createAndInsertRecord(key, key);
                fRoot = newLeafNode;
                sz++;
                return newLeafNode;
            }
            else {
#ifdef DEBUG
    std::cout << "\nkey(" << __LINE__ << ")insert_key: " << key << "\n";
#endif // DEBUG              
                link_LeafNode leafNode = findLeafNode(key);
                link_record record = leafNode->lookup(key);
                if (record) {
                    record->setValue(key);
                    return leafNode;
                }
                else
                    sz++;
                int newSize = leafNode->createAndInsertRecord(key, static_cast<value_type>(key));
                //step over limit of LeafNode(fOrder) ? split : return
                if (newSize > leafNode->maxSize()) {
                    //split
                    link_LeafNode newLeaf = new LeafNode<Key>(fOrder, leafNode->parent());
                    leafNode->moveHalfTo(newLeaf);
                    //end of split

                    newLeaf->setNext(leafNode->next());
                    leafNode->setNext(newLeaf);
                    key_type newKey = static_cast<key_type>(newLeaf->firstKey());
                    // create InternalNode
                    this->insertIntoParent(leafNode, newKey, newLeaf);
                }
                return leafNode;
            }
        }


        /*ERASE (private functions related to B+Tree) ********************************************
        *  
        * remove(const key_type& key)  
        *   joinOrRedistribute(key_type* aNode) 
        *       adjustRoot()    
        *       join(key_type* aNeighborNode, key_type* aNode, link_LeafInternalNode aParent, int aIndex)
        *           joinOrRedistribute(key_type* aNode)
        *       redistribute(key_type* aNeighborNode, key_type* aNode, link_LeafInternalNode* aParent, int aIndex)
        *
        ******************************************************************************************/
        size_type remove(const key_type& key)
        {
            if (!fRoot) {
                return 0;
            }
            else {
                link_LeafNode leafNode = findLeafNode(key);
                if (!leafNode)  return 0;
                if (!leafNode->lookup(key)) return 0;

                int newSize = leafNode->removeAndDeleteRecord(key);
                if (newSize < leafNode->minSize()) {
                    this->joinOrRedistribute(leafNode);
                }
                --sz;
                return 1;
            }
        }

        template <typename TLinkNode>
        void joinOrRedistribute(TLinkNode aNode)
        {
            if (aNode->isRoot()) {
                adjustRoot();
                return;
            }
            auto parent = static_cast<link_LeafInternalNode>(aNode->parent());
            int indexOfNodeInParent = parent->nodeIndex(aNode);
            int neighborIndex = (indexOfNodeInParent == 0) ? 1 : indexOfNodeInParent - 1;
            TLinkNode neighborNode = static_cast<TLinkNode>(parent->neighbor(neighborIndex));
            if (aNode->size() + neighborNode->size() <= neighborNode->maxSize()) {
                this->join(neighborNode, aNode, parent, indexOfNodeInParent);
            }
            else {
                this->redistribute(neighborNode, aNode, parent, indexOfNodeInParent);
            }
        }

        template <typename TLinkNode>
        void join(TLinkNode aNeighborNode, TLinkNode aNode, link_LeafInternalNode aParent, int aIndex)
        {
            if (aIndex == 0) {
                std::swap(aNode, aNeighborNode);
                aIndex = 1;
            }
            aNode->moveAllTo(aNeighborNode, aIndex);
            aParent->remove(aIndex);
            if (aParent->size() < aParent->minSize()) {
                this->joinOrRedistribute(aParent);
            }
            delete aNode;
        }

        template <typename TLinkNode>
        void redistribute(TLinkNode aNeighborNode, TLinkNode aNode, link_LeafInternalNode aParent, int aIndex)
        {
            if (aIndex == 0) {
                aNeighborNode->moveFirstToEndOf(aNode);
            }
            else {
                aNeighborNode->moveLastToFrontOf(aNode, aIndex);
            }
        }

        void adjustRoot()
        {
            if (!fRoot->isLeaf() && fRoot->size() == 1) {
                auto discardedNode = static_cast<link_LeafInternalNode>(fRoot);
                fRoot = static_cast<link_LeafInternalNode>(fRoot)->removeAndReturnOnlyChild();
                fRoot->setParent(nullptr);
                delete discardedNode;
            }
            else if (!fRoot->size()) {
                delete fRoot;
                fRoot = nullptr;
            }
        }

        /*UTILITIES (private functions related to B+Tree) *****************************************
        *
        *   
        *       
        *
        ******************************************************************************************/
        const link_Node clone(link_Node node) {
            if (!node)    return nullptr;
            
            while (!node->isLeaf()) {
                node = static_cast<link_LeafInternalNode>(node)->firstChild();
            }
            auto leafNode = static_cast<link_LeafNode>(node);
            while (leafNode) {
                for (auto mapping : leafNode->getKeysVector()) {
                    insert_key(mapping.first);
                }
#ifdef DEBUG
                std::cout << " | ";
                std::cout << "(" << __LINE__ << ")clone: " << leafNode->toString();
                std::cout << "\n";
#endif // DEBUG
                leafNode = leafNode->next();
            }
            return fRoot;
        };
        
        //Get LeafNode where the key is or should be later
        const link_LeafNode findLeafNode(const key_type& key) {
#ifdef DEBUG
std::cout << "key(" << __LINE__ << ")findLeafNode: " << key << "\n";
#endif // DEBUG      
            if (!fRoot) { return nullptr; }
            auto node = fRoot;
            while (!node->isLeaf()) {
                auto internalNode = static_cast<link_LeafInternalNode>(node);
                node = internalNode->lookup(key);
            }
            return static_cast<link_LeafNode>(node);
        };

       static void	dumpLeaves(std::ostream& o, link_Node link, bool extended=false) {
            if (!link) {
                o << "Empty tree." << std::endl;
                return;
            }
            auto node = link;
            o << "Leaves of Tree: \n";
            while (!node->isLeaf()) {
                node = static_cast<link_LeafInternalNode>(node)->firstChild();
            }
            auto leafNode = static_cast<link_LeafNode>(node);
            while (leafNode) {
                o << "| ";
                leafNode->toString(o, extended);
                leafNode = leafNode->next();
                o << " | -> ";
            }
            o<< "\n";
        }
    
    public://--------------------------------------------------------------------------------------
        //[Phase 1]-Default constructor
        ADS_set() {}                                                                            
        
        //[Phase 1]-Initializer list constructor. The elements are inserted in the order specified in ilist.
        ADS_set(std::initializer_list<key_type> ilist) {  
            this->insert(ilist); 
        }
        
        //[Phase 1]-Range constructor.Creates a container that contains the elements from the[first, last[area.
        //         The elements are inserted in the specified order(starting with first).
        template<typename InputIt> ADS_set(InputIt first, InputIt last) { 
            this->insert(first, last);
        }
        
        //[Phase 2]
        ADS_set(const ADS_set& other) {
            fRoot = clone(other.fRoot);
            sz = other.sz;
        }

        //[Phase 2]
        ~ADS_set() {
            delete fRoot; fRoot = nullptr;
        }

        //[Phase 1]-Number of items stored in the container
        size_type size() const { 
            return sz; 
        }
        
        //[Phase 1]-true if size () == 0, otherwise false
        bool empty() const     { 
            return !sz; 
        }
        
        //[Phase 1]-Inserts the elements from ilist. The elements are inserted in the order specified in ilist
        void insert(std::initializer_list<key_type> ilist) { 
            for (const key_type &key: ilist) insert_key(key); 
        }
       
        //[Phase 1]
        template<typename InputIt> void insert(InputIt first, InputIt last) { 
            for (InputIt it = first; it != last; it++) insert_key(static_cast<key_type>(*it));
        }

        //[Phase 2]
        std::pair<iterator, bool> insert(const key_type& key) {
            bool success = !insert_key(key) ? false: true;
            iterator it=find(key);
            return { it, success };
        }

        //[Phase 1]-Return value : The number of elements in the container with key (0 or 1)
        size_type count(const key_type &key) const {
            if (size() == 0) return 0;

            auto node = fRoot;
            while (!node->isLeaf()) {
                auto internalNode = static_cast<link_LeafInternalNode>(node);
                node = internalNode->lookup(key);
            }
            auto leafNode = static_cast<link_LeafNode>(node);
            if (!leafNode->lookup(key)) return 0;
                else return 1;
        }

        //[Phase 2]
        iterator find(const key_type& key) const {
            auto it = begin();
            for (; it != end(); it++)
                if (key_equal{}(static_cast<const key_type&>(*it), key)) break;
            return it;
        }
        //[Phase 2]
        const_iterator begin() const    { 
            if (!fRoot)    return const_iterator{};

            auto node = fRoot;
            while (!node->isLeaf()) 
                node = static_cast<link_LeafInternalNode>(node)->firstChild();
            auto firstleafNode = static_cast<link_LeafNode>(node);

            return const_iterator{ firstleafNode };
        }
        const_iterator end() const      { return const_iterator{}; }

        /*[Phase 1]
        * In the event of errors, the unit test outputs the contents of the container 
        * using this method in order to facilitate troubleshooting. However, if the output is too extensive, 
        * it can be shortened during the unit test. It can be assumed that during the unit test the container is 
        * only instantiated with element data types (key_type) that support the output operator (<<).
        */
        void dump(std::ostream &o = std::cerr) const { dumpLeaves(o,fRoot); }

        //[Phase 2]
        void clear() {
            //if (fRoot->isLeaf()) delete static_cast<LeafNode<Key>*>(fRoot);
                //else delete static_cast<InternalNode<Key>*>(fRoot);
            delete fRoot;
            fRoot = nullptr;
            sz = 0;
        }
        
        //[Phase 2]
        size_type erase(const key_type& key) { return remove(key); };
        
        //[Phase 2]
        void swap(ADS_set& other) {
            std::swap(fRoot, other.fRoot);
            std::swap(sz, other.sz);
        }
        
        //[Phase 2]
        ADS_set& operator=(const ADS_set& other) {
            if (this == &other) return *this;
            clear();
            fRoot = clone(other.fRoot);
            sz = other.sz;
            return *this;
        }
        
        //[Phase 2]
        ADS_set& operator=(std::initializer_list<key_type> ilist) {
            clear();
            insert(ilist);
            return *this;
        }
        
        //[Phase 2]
        friend bool operator==(const ADS_set& lhs, const ADS_set& rhs) {
            if (lhs.size() != rhs.size()) return false;
            auto lhs_it{ lhs.begin() };
            auto rhs_it{ rhs.begin() };
            for (; lhs_it != lhs.end(); ++lhs_it, ++rhs_it) if (!key_equal{}(*lhs_it, *rhs_it)) return false;
            return true;
        }

        //[Phase 2]
        friend bool operator!=(const ADS_set& lhs, const ADS_set& rhs) { return !(lhs == rhs); }
};

//[Phase 2]
template <typename Key, size_t N>
void swap(ADS_set<Key, N>& lhs, ADS_set<Key, N>& rhs) { lhs.swap(rhs); }

template <typename Key, size_t N>
bool operator==(const ADS_set<Key, N>& lhs, const ADS_set<Key, N>& rhs) { return  ADS_set<Key, N>::key_equal(lhs, rhs); }

template <typename Key, size_t N>
bool operator!=(const ADS_set<Key, N>& lhs, const ADS_set<Key, N>& rhs) { return !ADS_set<Key, N>::key_equal(lhs, rhs); }

/******************************************************************************
        class ADS_set<Key, N>::Iterator
*******************************************************************************/
template <typename Key, size_t N>
class ADS_set<Key, N>::Iterator {
    public:
        using value_type = Key;
        using link_Key = Key*;
        using link_LeafNode = LeafNode<Key>*;

        using difference_type = std::ptrdiff_t;
        using reference = const value_type&;
        using pointer = const value_type*;
        using iterator_category = std::forward_iterator_tag;
        using const_iterator = Iterator;

    private:
        std::queue<value_type> values;

    public:
        explicit Iterator(link_LeafNode leafNode = nullptr) {
            if (!leafNode) return; // for end() of explicit class (ADS_set<Key, N>)
            while (leafNode) {
                for (auto mapping : leafNode->getKeysVector()) {
                    values.push(static_cast<value_type>(mapping.second->value()));
                }
                leafNode = leafNode->next();
            }
        }
        reference operator*() const     { return values.front(); }
        pointer operator->() const      { return &values.front();}
        Iterator& operator++()          { values.pop(); return *this; }
        Iterator operator++(int)        { Iterator tmp{ *this }; ++*this; return tmp; }

        friend bool operator ==(const Iterator& lhs, const Iterator& rhs) { 
            return (lhs.values.size() == rhs.values.size()) && 
                     (lhs.values.empty() ||
                         key_equal{}(lhs.values.front(),rhs.values.front()) );
        }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs) 
            { return !(lhs == rhs); }
        //operator const_iterator() { return  ptr; };
};

#endif // ADS_SET_H
