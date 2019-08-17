// 041-Pointers Basic.cpp 

/*
	You'll learn how values are stored in the computer and how to access them using pointers.
		https://www.programiz.com/cpp-programming/pointers

	---- Common mistakes when working with pointers ----
	Suppose, you want pointer pc to point to the address of c. Then,

	int c, *pc;
	pc=c;			// Wrong! pc is address whereas, c is not an address.
	* pc = &c;		// Wrong! *pc is the value pointed by address whereas, %amp;c is an address.
	pc = &c;		// Correct! pc is an address and, %amp;pc is also an address.
	*pc = c;		// Correct! *pc is the value pointed by address and, c is also a value.

	You should also check out these pointer related tutorials:
		How to use generic data type pointer using void pointer?(https://www.programiz.com/cpp-programming/pointer-void)
		How to represent array using pointer?(https://www.programiz.com/cpp-programming/pointers-arrays)
		How to use pointers with functions?(https://www.programiz.com/cpp-programming/pointers-function)
		How to use pointers with structures?(https://www.programiz.com/cpp-programming/structure-pointer)

	
*/

#include <iostream>
using namespace std;
const int MAX = 4;

int main() {
	int* pc, c;

	c = 5;
	cout << "Address of c (&c): " << &c << endl;
	cout << "Value of c (c): " << c << endl << endl;
	pc = &c;    // Pointer pc holds the memory address of variable c
	cout << "Address that pointer pc holds (pc): " << pc << endl;
	cout << "Content of the address pointer pc holds (*pc): " << *pc << endl << endl;

	c = 11;    // The content inside memory address &c is changed from 5 to 11.
	cout << "Address pointer pc holds (pc): " << pc << endl;
	cout << "Content of the address pointer pc holds (*pc): " << *pc << endl << endl;
	*pc = 2;
	cout << "Address of c (&c): " << &c << endl;
	cout << "Value of c (c): " << c << endl << endl;

	const char* names[MAX] = { "Zara Ali", "Hina Ali", "Nuha Ali", "Sara Ali" };

	for (int i = 0; i < MAX; i++) {
		cout << "Value of names[" << i << "] = ";
		cout << *(names + i) << endl;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
