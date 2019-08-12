// 002-Print Number Entered by User
/*
	you'll learn to print the number entered by a user using C++ cout statement. 
	https://www.programiz.com/cpp-programming/examples/read-print-integer
	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/
//

#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "Enter an integer: ";
	cin >> number;
	cout << "You entered " << number << "\n";
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
