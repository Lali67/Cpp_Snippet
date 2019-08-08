// 022-Reverse an Integer.cpp 

/*
	Example to reverse an integer entered by the user in C++ programming. 
	This problem is solved by using while loop in this example.
	https://www.programiz.com/cpp-programming/examples/reverse-number

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ while and do...while Loop (https://www.programiz.com/cpp-programming/do-while-loop)
	
	This program takes an integer input from the user and stores it in variable n.
	Then the while loop is iterated until n != 0 is false.

	Standard library:
	https://www.programiz.com/cpp-programming/library-function

*/

#include <iostream>
using namespace std;

int main()
{
	int n, reversedNumber = 0, remainder;
	cout << "Enter an integer: ";
	cin >> n;
	while (n != 0)
	{
		remainder = n % 10;
		reversedNumber = reversedNumber * 10 + remainder;
		n /= 10;
	}
	cout << "Reversed Number = " << reversedNumber;
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
