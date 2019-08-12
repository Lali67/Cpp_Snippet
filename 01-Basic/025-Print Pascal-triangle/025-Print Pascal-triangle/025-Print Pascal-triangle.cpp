// 025-Print Pascal-triangle.cpp 

/*
	https://www.programiz.com/cpp-programming/examples/pyramid-pattern

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ if, if...else and Nested if...else(https://www.programiz.com/cpp-programming/if-else)
		C++ for Loop(https://www.programiz.com/cpp-programming/do-while-loop)

	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/

#include <iostream>
using namespace std;

int main()
{
	int rows, coef = 1;
	cout << "Enter number of rows: ";
	cin >> rows;
	for (int i = 0; i < rows; i++)
	{
		for (int space = 1; space <= rows - i; space++)
			cout << "  ";
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || i == 0)
				coef = 1;
			else
				coef = coef * (i - j + 1) / j;
			cout << coef << "   ";
		}
		cout << endl;
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
