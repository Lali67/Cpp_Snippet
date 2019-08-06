// 004-Find Quotient and Remainder.cpp 
/*
	The user is asked to enter two integers (divisor and dividend) and 
	computes the quotient and remainder.
	https://www.programiz.com/cpp-programming/examples/quotient-remainder
	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/
#include <iostream>

using namespace std;

int main()
{
	int divisor, dividend, quotient, remainder;
	cout << "Enter dividend: ";
	cin >> dividend;
	cout << "Enter divisor: ";
	cin >> divisor;

	//division operator / is computes the quotient
	quotient  = dividend / divisor;
	//modulus operator % computes the remainder; modulus operator cannot be used for floating-type variables
	remainder = dividend % divisor;


	cout << "Quotient  = " << quotient << endl;
	cout << "Remainder = " << remainder << endl << endl;
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
