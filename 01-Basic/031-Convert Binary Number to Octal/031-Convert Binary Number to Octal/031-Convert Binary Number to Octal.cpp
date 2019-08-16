// 031-Convert Binary Number to Octal.cpp 

/*
	In this example, you will learn to convert binary number to octal, 
	and octal number to binary manually by creating a user-defined function. 
		https://www.programiz.com/cpp-programming/examples/octal-binary-convert

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ Functions(https://www.programiz.com/cpp-programming/function)
		Types of User-defined Functions in C++(https://www.programiz.com/cpp-programming/user-defined-function-types)
		C++ if, if...else and Nested if...else(https://www.programiz.com/cpp-programming/if-else)
		C++ while and do...while Loop(https://www.programiz.com/cpp-programming/do-while-loop)

*/

#include <iostream>
#include <cmath>

using namespace std;

int convertBinarytoOctal(long long);
long long convertOctalToBinary(int octalNumber);

int main()
{
	long long binaryNumber;
	cout << "Enter a binary number: ";
	cin >> binaryNumber;
	cout << binaryNumber << " in binary = " << convertBinarytoOctal(binaryNumber) << " in octal ";

	int octalNumber;
	cout << "Enter an octal number: ";
	cin >> octalNumber;
	cout << octalNumber << " in octal = " << convertOctalToBinary(octalNumber) << "in binary";

	return 0;
}

int convertBinarytoOctal(long long binaryNumber)
{
	int octalNumber = 0, decimalNumber = 0, i = 0;
	while (binaryNumber != 0)
	{
		decimalNumber += (binaryNumber % 10) * pow(2, i);
		++i;
		binaryNumber /= 10;
	}
	i = 1;
	while (decimalNumber != 0)
	{
		octalNumber += (decimalNumber % 8) * i;
		decimalNumber /= 8;
		i *= 10;
	}
	return octalNumber;
}

long long convertOctalToBinary(int octalNumber)
{
	int decimalNumber = 0, i = 0;
	long long binaryNumber = 0;
	while (octalNumber != 0)
	{
		decimalNumber += (octalNumber % 10) * pow(8, i);
		++i;
		octalNumber /= 10;
	}
	i = 1;
	while (decimalNumber != 0)
	{
		binaryNumber += (decimalNumber % 2) * i;
		decimalNumber /= 2;
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
