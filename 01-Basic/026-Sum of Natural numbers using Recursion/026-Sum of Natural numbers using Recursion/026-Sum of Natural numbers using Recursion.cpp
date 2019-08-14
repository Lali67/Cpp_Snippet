// 026-Sum of Natural numbers using Recursion.cpp 

/*

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ Functions (https://www.programiz.com/cpp-programming/function)
		Types of User-defined Functions in C++ (https://www.programiz.com/cpp-programming/user-defined-function-types)
		C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)
		C++ Recursion (https://www.programiz.com/cpp-programming/recursion)

	The positive numbers 1, 2, 3... are known as natural numbers. 
	The program below takes a positive integer from the user and 
	calculates the sum up to the given number.

*/

#include<iostream>
using namespace std;

int add(int n);
int main()
{
	int n;
	cout << "Enter a positive integer: ";
	cin >> n;
	cout << "Sum =  " << add(n);
	return 0;
}
int add(int n)
{
	if (n != 0)
		return n + add(n - 1);
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
