// 034-Add Two Matrix Using Multi-dimensional Arrays.cpp 

/*
	This program takes two matrices of order r*c and stores it in two-dimensional array. 
	Then, the program adds these two matrices and displays it on the screen.
		https://www.programiz.com/cpp-programming/examples/add-matrix

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ Multidimensional Arrays(https://www.programiz.com/cpp-programming/multidimensional-arrays)
		C++ Arrays(https://www.programiz.com/cpp-programming/arrays)

	In this program, user is asked to entered the number of rows r and columns c. 
	The value of r and c should be less than 100 in this program.
*/

#include <iostream>
#include <cmath>

using namespace std;

int convertBinaryToDecimal(long long);

int main()
{
	long long n;
	cout << "Enter a binary number: ";
	cin >> n;

	cout << n << " in binary = " << convertBinaryToDecimal(n) << "in decimal";
	return 0;
}
int convertBinaryToDecimal(long long n)
{
	int decimalNumber = 0, i = 0, remainder;
	while (n != 0)
	{
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder * pow(2, i);
		++i;
	}
	return decimalNumber;
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
