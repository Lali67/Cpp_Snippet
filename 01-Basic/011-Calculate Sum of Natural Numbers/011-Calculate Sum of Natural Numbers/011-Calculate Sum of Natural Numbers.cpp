// 011-Calculate Sum of Natural Numbers.cpp 

/*
	This program takes a positive integer from user( suppose user entered n ) then, 
	this program displays the value of 1+2+3+....+n.
		https://www.programiz.com/cpp-programming/examples/sum-natural-number

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ for Loop (https://www.programiz.com/cpp-programming/for-loop)

	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/

#include <iostream>
using namespace std;

// This program assumes that user always enters positive number.
// If user enters negative number, Sum = 0 is displayed and program is terminated.

int main()
{
	int n, sum = 0;
	cout << "Enter a positive integer: ";
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		sum += i;
	}
	cout << "Sum = " << sum;
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
