/*
	A pointer however, is a variable that stores the memory address as its value.
	
	A pointer variable points to a data type (like int or string) of the same type, and is created with the * operator. 
	The address of the variable you're working with is assigned to the pointer.

	Note that the * sign can be confusing here, as it does two different things in our code:
		When used in declaration (string* ptr), it creates a pointer variable.
		When not used in declaration, it act as a dereference operator.
*/

#include<iostream>
#include"vector.h"

using namespace std;

int main() {
	//-------- Pointer basic
	string food = "Pizza";			// A food variable of type string
	string* ptr = &food;			// A pointer variable, with the name ptr, that stores the address of food
	cout << food << "\n";			// Output the value of food (Pizza)
	cout << &food << "\n";			// Output the memory address of food
	cout << ptr << "\n";			// Output the memory address of food with the pointer
	cout << *ptr << "\n";			// Dereference: Output the value of food with the pointer (Pizza)
	*ptr = "Hamburger";				// Change the value of the pointer
	cout << *ptr << "\n";			// Output the new value of the pointer (Hamburger)
	cout << food << "\n";			// Output the new value of the food variable (Hamburger)

	//--------- Const
	const int Constant1 = 96;		//one cannot set the value later
	const int* Constant2;			//Constant2 is a variable pointer to a constant integer
	int const* Constant3;			//Constant3 is a variable pointer to a constant integer	(same Constant2)
	int* const Constant4;			//Constant4 is constant pointer to a variable integer
	int const* const Constant5;		//Constant5 is constant pointer to a constant integer

	//--------- Use of 'const' in Functions Return Values
	char* Function1()
	{	//returns a fixed 'Some text' string
		return "Some text";
	}
	Function1()[1] = 'a';			//program could crash if it accidentally tried to alter the value
	const char* Function2()
	{
		return "Some text";
	}
	Function2()[1] = 'a';			//compiler error: return value is not allowed to alter

	//--------- Use of 'const' in Parameter passing
	void Subroutine3(int Parameter1)
	{	//Parameter1 is changed only int the function body
		Parameter1 = 96;
	};
	void Subroutine4(int& Parameter1)
	{	//set the variable it was called with to 96 ->reference
		Parameter1 = 96;
	};
	void Subroutine5(int* Parameter1)
	{	//pointer to the variable -> Parameter1 changed
		*Parameter1 = 96;
	}
	void Subroutine6(int const& Parameter1) {
		//Parameter1 is not allowed to change
	};

	//--------- Use of 'const' in Object Oriented Programming
	class Class1
	{
		private:
			int MemberVariable1;
		public:
			void Method1() 
				{ MemberVariable1 = MemberVariable1 + 1; };
	}
	class Class2
	{
		private:
			int MemberVariable1;
		public:
			void Method1() const 
				//Method1 cannot change any member variables
				{ MemberVariable1 = MemberVariable1 + 1; };	//compiler error

			const int* const Method3(const int* const&)const {};
			//5 'const' respectively mean that the variable pointed to by the returned pointer and 
			//the returned pointer itself won’t be alterable and 
			//that the method does not alter the variable pointed to by the given pointer, 
			//the given pointer itself and the object of which it is a method!
	}

	return 0;
}
