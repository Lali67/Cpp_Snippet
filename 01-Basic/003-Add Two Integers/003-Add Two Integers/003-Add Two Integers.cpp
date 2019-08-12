// 003-Add Two Integers.cpp 
/*
	The user is asked to enter two integers. 
	Then, the sum of those two integers is stored in a variable and displayed on the screen.
	https://www.programiz.com/cpp-programming/examples/add-numbers
	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/

#include <iostream>
using namespace std;

int main()
{
	int firstNumber, secondNumber, sumOfTwoNumbers;

	cout << "Enter two integers: ";
	cin >> firstNumber >> secondNumber;
	// sum of two numbers in stored in variable sumOfTwoNumbers
	sumOfTwoNumbers = firstNumber + secondNumber;
	// Prints sum 
	cout << firstNumber << " + " << secondNumber << " = " << sumOfTwoNumbers << "\n\n";
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
