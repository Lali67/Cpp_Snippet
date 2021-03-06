// 006-Swap Numbers.cpp 
/*
	This example contains two different techniques to swap numbers in C programming. 
	The first program uses temporary variable to swap numbers, 
	whereas the second program doesn't use temporary variables. 
	https://www.programiz.com/cpp-programming/examples/swapping
	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/
#include <iostream>
using namespace std;

int main()
{
	int a = 5, b = 10, temp;
	cout << "Before swapping." << endl;
	cout << "a = " << a << ", b = " << b << endl;
	temp = a;
	a = b;
	b = temp;
	cout << "\nAfter swapping." << endl;
	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}

/*

int main()
{

	int a = 5, b = 10;
	cout << "Before swapping." << endl;
	cout << "a = " << a << ", b = " << b << endl;
	a = a + b;
	b = a - b;
	a = a - b;
	cout << "\nAfter swapping." << endl;
	cout << "a = " << a << ", b = " << b << endl;
	return 0;
}
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
