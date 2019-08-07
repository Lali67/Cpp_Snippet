// 018-Generate Multiplication Table.cpp 

/*
	In this article, you will learn to print fibonacci series in C++ programming 
	(up to nth term, and up to a certain number). 
	https://www.programiz.com/cpp-programming/examples/fibonacci-series

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ for Loop (https://www.programiz.com/cpp-programming/for-loop)
		C++ while and do...while Loop (https://www.programiz.com/cpp-programming/do-while-loop)

	The Fibonacci sequence is a series where the next term is the sum of pervious two terms. 
	The first two terms of the Fibonacci sequence is 0 followed by 1.
	The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21

	Standard library:
	https://www.programiz.com/cpp-programming/library-function

*/

#include <iostream>
using namespace std;

int main()
{
	int n, t1 = 0, t2 = 1, nextTerm = 0;
	cout << "Enter the number of terms: ";
	cin >> n;
	cout << "Fibonacci Series: ";
	for (int i = 1; i <= n; ++i)
	{
		// Prints the first two terms.
		if (i == 1)
		{
			cout << " " << t1;
			continue;
		}
		if (i == 2)
		{
			cout << t2 << " ";
			continue;
		}
		nextTerm = t1 + t2;
		t1 = t2;
		t2 = nextTerm;

		cout << nextTerm << " ";
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
