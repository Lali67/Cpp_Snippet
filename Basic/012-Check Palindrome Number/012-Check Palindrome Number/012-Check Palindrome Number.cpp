// 012-Check Palindrome Number.cpp 

/*
	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ while and do...while Loop (https://www.programiz.com/cpp-programming/do-while-loop)
		C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)

	This program takes an integer from user and that integer is reversed.
*/

#include <iostream>
using namespace std;

int main()
{
	int n, num, digit, rev = 0;
	cout << "Enter a positive number: ";
	cin >> num;
	n = num;
	do
	{
		digit = num % 10;
		rev = (rev * 10) + digit;
		num = num / 10;
	} while (num != 0);
	cout << " The reverse of the number is: " << rev << endl;
	if (n == rev)
		cout << " The number is a palindrome.";
	else
		cout << " The number is not a palindrome.";
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
