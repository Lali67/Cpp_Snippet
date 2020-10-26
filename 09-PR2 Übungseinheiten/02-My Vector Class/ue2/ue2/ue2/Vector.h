#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <iostream>				//move, swap
#include <stdexcept>			

using namespace std;

class Vector {
	
	public:
		using value_type = double;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using reference = double&;
		using const_reference = const double&;
		using pointer = double*;
		using const_pointer = const double*;
		using iterator = double*;
		using const_iterator = const double*;
	
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
					Iterator():ptr(nullptr) {};
					Iterator(pointer optr) { 
						ptr = optr;
					}
					reference operator * () const ;
					pointer operator -> ()
					{
						return static_cast<pointer> (ptr);
					}
					bool operator == (const const_iterator&) const;
					bool operator != (const const_iterator&) const;
					Iterator& operator ++ ()				// (Prefix): no const because 'ptr' changes
					{
						++ptr;
						return *this;
					}
					Iterator operator ++ (int)				// (Postfix)
					{
						++(*ptr); 
						return *this;
					}
					operator const_iterator() const;		// (Typ - Konversion)
		};

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
					ConstIterator():ptr(nullptr) {};
					ConstIterator(pointer optr) {
						ptr = optr;
					}
					reference operator * () const;
					pointer operator -> () const;
					bool operator == (const const_iterator&) const;
					bool operator != (const const_iterator&) const;
					const_iterator& operator ++ () const;		// (Prefix)
					const_iterator operator++(int) const;		// (Postfix)
		};

	private:	
		static constexpr size_type min_sz{5};			//Mindestgroesse (5) fuer max_sz festlegt einfuehren
		size_type	sz;									//Anzahl der Elemente im Vector
		size_type	max_sz;								//maximale Anzahl an Elementen die	moeglich sind
		pointer		values;								//Zeigt auf ein Feld, welches die Elemente des Vectors beinhaltet

	public:
		Vector()										//Liefert einen leeren Vector
		{
			sz = 0;
			max_sz = min_sz;
			values = new value_type[max_sz];
		}
		Vector(size_type n)								//Liefert einen Vector mit Platz fuer n Elemente
		{	
			sz = n;
			max_sz = n + min_sz;
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
		Vector(const Vector& obj)						//Kopierkonstruktor: Liefert einen Vector mit demselben Inhalt
		{
			sz = 0;
			max_sz = obj.max_sz + min_sz;
			values	= new value_type[max_sz];
			for (size_type i = 0; i < obj.size(); i++)
				push_back(obj.values[i]);
		}
		
		//--------- Methoden für Iteratoren ---------
		iterator begin()
			{ return values; }
		iterator end()
			{ return values + sz; }
		const_iterator begin() const
			{ return values; }
		const_iterator end() const
			{ return values + sz; }
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
		void reserve(size_type n)							//Kapazitaet des Vectors wird auf n vergroessert, falls noetig
		{
			size_type newCapacity = n;
			if (newCapacity < max_sz)
				return;

			iterator newArray = new value_type[newCapacity];
				for (size_type k = 0; k < max_sz; ++k)
					newArray[k] = std::move(values[k]);

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
				newArray[k] = std::move(values[k]);
			delete[] values;

			values = new value_type[sz];
			for (int k = 0; k < sz; ++k)
				values[k] = std::move(newArray[k]);
			delete[] newArray;

			max_sz = sz + min_sz;
		}
		void push_back(value_type x)						//Fuegt eine Kopie von x am Ende des Vectors hinzu
		{
			if (sz == max_sz)
				reserve(2 * max_sz+1);
			values[sz++] = x;
		}
		void pop_back()									//Entfernt das letzte Element im Vector Wirfteine Exception falls der Vector leer war
		{ 
			if(sz==0)
				throw std::out_of_range("pop_back() : index is out of range");
			sz--;
		}
		size_t capacity() const							//Retourniert aktuelle Kapazitaet des Vectors
		{
			return max_sz;
		}
		void operator = (const Vector& other)			//Das this-Objekt uebernimmt die Werte vom Parameter
		{
			sz = 0;
			//max_sz: Change is not allowed
			for (int i = 0; i < other.size(); i++)
				push_back(other.values[i]);
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

		~Vector()
		{
			delete [] values;
		}
};


#endif // !VECTOR_H

