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
	string food = "Pizza";  // A food variable of type string
	string* ptr = &food;    // A pointer variable, with the name ptr, that stores the address of food

	// Output the value of food (Pizza)
	cout << food << "\n";
	// Output the memory address of food
	cout << &food << "\n";
	// Output the memory address of food with the pointer
	cout << ptr << "\n";

	// Dereference: Output the value of food with the pointer (Pizza)
	cout << *ptr << "\n";

	// Change the value of the pointer
	*ptr = "Hamburger";
	// Output the new value of the pointer (Hamburger)
	cout << *ptr << "\n";
	// Output the new value of the food variable (Hamburger)
	cout << food << "\n";

	return 0;
}
