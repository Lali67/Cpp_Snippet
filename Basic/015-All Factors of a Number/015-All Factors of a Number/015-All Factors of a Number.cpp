// 015-All Factors of a Number.cpp

/*
		Example to check whether an integer (entered by the user) is a prime number or not
		using for loop and if...else statement.

		To understand this example, you should have the knowledge of following C++ programming topics:

			C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)
			C++ for Loop (https://www.programiz.com/cpp-programming/for-loop)
			C++ break and continue Statement (https://www.programiz.com/cpp-programming/break-continue)
*/

#include <iostream>
using namespace std;

int main()
{
	int n, i;
	cout << "Enter a positive integer: ";
	cin >> n;
	cout << "Factors of " << n << " are: " << endl;
	for (i = 1; i <= n; ++i)
	{
		if (n % i == 0)
			cout << i << endl;
	}
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
