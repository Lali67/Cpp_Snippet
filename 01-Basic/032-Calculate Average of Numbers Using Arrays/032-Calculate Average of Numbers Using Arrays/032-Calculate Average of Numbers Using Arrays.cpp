// 032-Calculate Average of Numbers Using Arrays.cpp

/*
	This program takes n number of element from user (where, n is specified by user), 
	stores data in an array and calculates the average of those numbers.
		https://www.programiz.com/cpp-programming/examples/average-arrays

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ Arrays(https://www.programiz.com/cpp-programming/arrays)
		C++ for Loop(https://www.programiz.com/cpp-programming/for-loop)
		C++ while and do...while Loop(https://www.programiz.com/cpp-programming/do-while-loop)

	This program calculates the average if the number of data are from 1 to 100.
	If user enters value of n above 100 or below 100 then, while loop is executed 
	which asks user to enter value of n until it is between 1 and 100.
*/

#include <iostream>
using namespace std;

int main()
{
	int n, i;
	float num[100], sum = 0.0, average;

	cout << "Enter the numbers of data: ";
	cin >> n;
	while (n > 100 || n <= 0)
	{
		cout << "Error! number should in range of (1 to 100)." << endl;
		cout << "Enter the number again: ";
		cin >> n;
	}
	for (i = 0; i < n; ++i)
	{
		cout << i + 1 << ". Enter number: ";
		cin >> num[i];
		sum += num[i];
	}
	average = sum / n;
	cout << "Average = " << average;
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
