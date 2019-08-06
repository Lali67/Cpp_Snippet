// 007-Check Whether Number is Even.cpp 
/*
	In this example, if...else statement is used to check whether a number 
	entered by the user is even or odd. 
	https://www.programiz.com/cpp-programming/examples/even-odd

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)

	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/

#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter an integer: ";
	cin >> n;
	if (n % 2 == 0)
		cout << n << " is even.";
	else
		cout << n << " is odd.";
	return 0;
}

/*
	#include <iostream>
	using namespace std;
	int main()
	{
		int n;
		cout << "Enter an integer: ";
		cin >> n;

		(n % 2 == 0) ? cout << n << " is even." :  cout << n << " is odd.";

		return 0;
	}

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
