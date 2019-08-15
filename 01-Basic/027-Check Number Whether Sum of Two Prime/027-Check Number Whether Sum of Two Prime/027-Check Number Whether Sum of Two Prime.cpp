// 027-Check Number Whether Sum of Two Prime.cpp

/*
	Example to check if an integer (entered by the user) can be expressed 
	as the sum of two prime numbers of all possible combinations with the use of functions. 
		https://www.programiz.com/cpp-programming/examples/sum-prime-numbers

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ for Loop (https://www.programiz.com/cpp-programming/for-loop)
		C++ if, if...else and Nested if...else(https://www.programiz.com/cpp-programming/if-else)
		C++ Functions(https://www.programiz.com/cpp-programming/function)
		Types of User-defined Functions in C++(https://www.programiz.com/cpp-programming/user-defined-function-types)

	This program takes a positive integer from user and checks whether that number can be expressed 
	as the sum of two prime numbers.
	If the number can be expressed as sum of two prime numbers, the output shows the combination of 
	the prime numbers.
*/

#include <iostream>
using namespace std;

bool checkPrime(int n);

int main()
{
	int n, i;
	bool flag = false;
	cout << "Enter a positive  integer: ";
	cin >> n;
	for (i = 2; i <= n / 2; ++i)
	{
		if (checkPrime(i))
		{
			if (checkPrime(n - i))
			{
				cout << n << " = " << i << " + " << n - i << endl;
				flag = true;
			}
		}
	}
	if (!flag)
		cout << n << " can't be expressed as sum of two prime numbers.";
	return 0;
}

// Check prime number
bool checkPrime(int n)
{
	int i;
	bool isPrime = true;
	for (i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
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
