// 009-Find Largest Number Among Three Numbers.cpp 
/*
	to find the largest number among three numbers using if, if else and nested if else statements.
		https://www.programiz.com/cpp-programming/examples/largest-number-among-three

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)

	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/
#include <iostream>
using namespace std;

int main()
{
	//Find Largest Number Using if Statement
	float n1, n2, n3;
	cout << "Enter three numbers: ";
	cin >> n1 >> n2 >> n3;
	if (n1 >= n2 && n1 >= n3)
	{
		cout << "Largest number: " << n1;
	}
	if (n2 >= n1 && n2 >= n3)
	{
		cout << "Largest number: " << n2;
	}
	if (n3 >= n1 && n3 >= n2) {
		cout << "Largest number: " << n3;
	}
	return 0;
}

/*
int main()
{
	float n1, n2, n3;
	cout << "Enter three numbers: ";
	cin >> n1 >> n2 >> n3;
	if((n1 >= n2) && (n1 >= n3))
		cout << "Largest number: " << n1;
	else if ((n2 >= n1) && (n2 >= n3))
		cout << "Largest number: " << n2;
	else
		cout << "Largest number: " << n3;

	return 0;
}

int main()
{
	//Find Largest Number Using Nested if...else statement
	float n1, n2, n3;
	cout << "Enter three numbers: ";
	cin >> n1 >> n2 >> n3;
	if (n1 >= n2)
	{
		if (n1 >= n3)
			cout << "Largest number: " << n1;
		else
			cout << "Largest number: " << n3;
	}
	else
	{
		if (n2 >= n3)
			cout << "Largest number: " << n2;
		else
			cout << "Largest number: " << n3;
	}
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
