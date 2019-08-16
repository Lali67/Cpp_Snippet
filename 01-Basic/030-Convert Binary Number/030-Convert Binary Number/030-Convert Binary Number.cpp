// 030-Convert Binary Number.cpp 

/*
		In this example, you will learn to convert binary number to decimal,
		and decimal number to binary manually by creating user-defined functions.
			https://www.programiz.com/cpp-programming/examples/binary-decimal-convert

		To understand this example, you should have the knowledge of following C++ programming topics:

			C++ Functions(https://www.programiz.com/cpp-programming/function)
			Types of User-defined Functions in C++(https://www.programiz.com/cpp-programming/user-defined-function-types)
			C++ Recursion(https://www.programiz.com/cpp-programming/recursion)
			C++ if, if...else and Nested if...else(https://www.programiz.com/cpp-programming/if-else)
			C++ while and do...while Loop(https://www.programiz.com/cpp-programming/do-while-loop)
*/


#include <iostream>
#include <cmath>
using namespace std;

int convertBinaryToDecimal(long long);
long long convertDecimalToBinary(int);

int main()
{
	long long n;
	cout << "Enter a binary number: ";
	cin >> n;
	cout << n << " in binary = " << convertBinaryToDecimal(n) << "in decimal";

	int n1, binaryNumber;
	cout << "Enter a decimal number: ";
	cin >> n1;
	binaryNumber = convertDecimalToBinary(n1);
	cout << n1 << " in decimal = " << binaryNumber << " in binary" << endl;

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

long long convertDecimalToBinary(int n)
{
	long long binaryNumber = 0;
	int remainder, i = 1, step = 1;
	while (n != 0)
	{
		remainder = n % 2;
		cout << "Step " << step++ << ": " << n << "/2, Remainder = " << remainder << ", Quotient = " << n / 2 << endl;
		n /= 2;
		binaryNumber += remainder * i;
		i *= 10;
	}
	return binaryNumber;
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
