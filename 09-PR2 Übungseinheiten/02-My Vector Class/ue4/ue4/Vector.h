#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <iostream>				//move, swap
#include <stdexcept>			

using namespace std;

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

		//--------- Methoden f�r Iteratoren ---------
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

		//--------- Methoden f�r Vector Klasse---------
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
				throw runtime_error("Iterator out of bounds");
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
				throw runtime_error("Iterator out of bounds");
			size_type current{ static_cast<size_type>(diff) };
			for (size_type i{ current }; i < sz - 1; ++i)
				values[i] = values[i + 1];
			--sz;
			return iterator{ values + current };
		}


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


#endif // !VECTOR_H