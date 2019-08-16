// 029-Find GCD Using Recursion.cpp 

/*
	Example to find the GCD of two positive integers (entered by the user) 
	using recursion in C++ programming.
		https://www.programiz.com/cpp-programming/examples/hcf-recursion

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ Functions (https://www.programiz.com/cpp-programming/function)
		Types of User-defined Functions in C++ (https://www.programiz.com/cpp-programming/user-defined-function-types)
		C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)
		C++ Recursion (https://www.programiz.com/cpp-programming/recursion)

	This program takes two positive integers from user and calculates GCD using recursion.
*/

#include <iostream>
using namespace std;

int hcf(int n1, int n2);

int main()
{
	int n1, n2;
	cout << "Enter two positive integers: ";
	cin >> n1 >> n2;
	cout << "H.C.F of " << n1 << " & " << n2 << " is: " << hcf(n1, n2);
	return 0;
}

int hcf(int n1, int n2)
{
	if (n2 != 0)
		return hcf(n2, n1 % n2);
	else
		return n1;
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
