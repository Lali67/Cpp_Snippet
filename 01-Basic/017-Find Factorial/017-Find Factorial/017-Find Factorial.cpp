
// 017-Find Factorial.cpp 

/*
	The factorial of a positive integer n is equal to 1*2*3*...n. You will learn to calculate the factorial of 
	a number using for loop in this example.
		https://www.programiz.com/cpp-programming/examples/factorial

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ for Loop (https://www.programiz.com/cpp-programming/for-loop)
	
	For any positive number n, it's factorial is given by:
		factorial = 1*2*3...*n
	Factorial of negative number cannot be found and factorial of 0 is 1

	Standard library:
	https://www.programiz.com/cpp-programming/library-function

*/

#include <iostream>
using namespace std;

int main()
{
	unsigned int n;
	unsigned long long factorial = 1;
	cout << "Enter a positive integer: ";
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		factorial *= i;
	}
	cout << "Factorial of " << n << " = " << factorial;
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
