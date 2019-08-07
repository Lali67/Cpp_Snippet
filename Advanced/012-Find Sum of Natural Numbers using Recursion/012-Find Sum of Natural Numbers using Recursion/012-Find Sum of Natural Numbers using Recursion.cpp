// 012-Find Sum of Natural Numbers using Recursion.cpp 

/*
	This program takes a positive integer from user( suppose user entered n ) then,
	this program displays the value of 1+2+3+....+n.
	https://www.programiz.com/cpp-programming/examples/sum-natural-number

	To understand this example, you should have the knowledge of following C++ programming topics:
		    C++ Functions (https://www.programiz.com/cpp-programming/function)
			Types of User-defined Functions in C++ (https://www.programiz.com/cpp-programming/user-defined-function-types)
			C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)
			C++ Recursion (https://www.programiz.com/cpp-programming/recursion)

	Standard library:
	https://www.programiz.com/cpp-programming/library-function
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
/*
	Suppose, 10 is entered by the user. Now, 10 is passed to the add() function. 
	This function adds 10 to the addition result of 9 (10 - 1 = 9).

	Next time, 9 is added to the addition result of 8 (9 - 1 = 8). 
	This goes on until the number reaches 0, when the function returns 0.

	Now, every function is returned to calculate the end result: 
		1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55.

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
