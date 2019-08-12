// 024-Armstrong Number Between Two Intervals.cpp 

/*
	Example to find all Armstrong numbers between two integers 
	  (entered by the user) using loops and if...else statement. 
		https://www.programiz.com/cpp-programming/examples/armstrong-number-interval

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ if, if...else and Nested if...else(https://www.programiz.com/cpp-programming/if-else)
		C++ for Loop(https://www.programiz.com/cpp-programming/do-while-loop)

	A positive integer is called an Armstrong number if the sum of cubes of 
	individual digit is equal to that number itself. For example:

		153 = 1 * 1 * 1 + 5 * 5 * 5 + 3 * 3 * 3  // 153 is an Armstrong number.
		12 is not equal to 1 * 1 * 1 + 2 * 2 * 2  // 12 is not an Armstrong number.

	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/

#include <iostream>
using namespace std;
int main()
{
	int origNum, num, rem, sum = 0;
	cout << "Enter a positive  integer: ";
	cin >> origNum;
	num = origNum;
	while (num != 0)
	{
		rem = num % 10;
		sum += rem * rem * rem;
		num /= 10;
	}
	if (sum == origNum)
		cout << origNum << " is an Armstrong number.";
	else
		cout << origNum << " is not an Armstrong number.";
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
