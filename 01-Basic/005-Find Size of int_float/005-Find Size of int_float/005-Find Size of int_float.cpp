// 005-Find Size of int_float.cpp 
/*
	The program declares 4 variables of type int, float, double and char. 
	Then, the size of each variable is evaluated using sizeof operator. 
	https://www.programiz.com/cpp-programming/examples/sizeof-operator
	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/

#include <iostream>
using namespace std;

int main()
{
	cout << "Size of char: " << sizeof(char) << " byte" << endl;
	cout << "Size of int: " << sizeof(int) << " bytes" << endl;
	cout << "Size of float: " << sizeof(float) << " bytes" << endl;
	cout << "Size of double: " << sizeof(double) << " bytes" << endl;
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
