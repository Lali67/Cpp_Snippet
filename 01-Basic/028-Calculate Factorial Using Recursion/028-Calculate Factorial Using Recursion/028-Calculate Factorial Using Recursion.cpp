// 028-Calculate Factorial Using Recursion.cpp 

/*
	Example to find factorial of a non-negative integer (entered by the user) using recursion.
		https://www.programiz.com/cpp-programming/examples/factorial-recursion

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ Functions (https://www.programiz.com/cpp-programming/function)
		Types of User-defined Functions in C++ (https://www.programiz.com/cpp-programming/user-defined-function-types)
		C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)
		C++ Recursion (https://www.programiz.com/cpp-programming/recursion)

	This program takes a positive integer from user and calculates the factorial of that number. 
	Suppose, user enters 6 then, Factorial will be equal to 1*2*3*4*5*6 = 720

	You'll learn to find the factorial of a number using a recursive function in this example.
*/

#include<iostream>
using namespace std;
int factorial(int n);
int main()
{
	int n;
	cout << "Enter a positive integer: ";
	cin >> n;
	cout << "Factorial of " << n << " = " << factorial(n);
	return 0;
}
int factorial(int n)
{
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
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
