// 018-Generate Multiplication Table.cpp 

/*
	Example to generate the multiplication table of a number (entered by the user) using for loop.  
	https://www.programiz.com/cpp-programming/examples/multiplication-table

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ for Loop (https://www.programiz.com/cpp-programming/for-loop)
		C++ while and do...while Loop (https://www.programiz.com/cpp-programming/do-while-loop)

	This program above computes the multiplication table up to 10 only.

	Standard library:
	https://www.programiz.com/cpp-programming/library-function

*/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter a positive integer: ";
	cin >> n;
	for (int i = 1; i <= 10; ++i) {
		cout << n << " * " << i << " = " << n * i << endl;
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
