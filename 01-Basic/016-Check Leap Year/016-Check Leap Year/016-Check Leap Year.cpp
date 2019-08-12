// 016-Check Leap Year.cpp 

/*
	This program checks whether an year (integer) entered by the user is a leap year or not. 
	https://www.programiz.com/cpp-programming/examples/leap-year

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)

	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/

#include <iostream>
using namespace std;

int main()
{
	int year;
	cout << "Enter a year: ";
	cin >> year;
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				cout << year << " is a leap year.";
			else
				cout << year << " is not a leap year.";
		}
		else
			cout << year << " is a leap year.";
	}
	else
		cout << year << " is not a leap year.";
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
