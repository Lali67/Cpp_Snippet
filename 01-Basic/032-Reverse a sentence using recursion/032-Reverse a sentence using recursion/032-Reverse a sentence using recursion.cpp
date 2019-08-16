// 032-Reverse a sentence using recursion.cpp 

/*
	This program takes a sentence from user and reverses that sentence using recursion. 
	This program does not use string to reverse the sentence or store the sentence. 
		https://www.programiz.com/cpp-programming/examples/reverse-sentence-recursion

	To understand this example, you should have the knowledge of following C++ programming topics:

	C++ Functions(https://www.programiz.com/cpp-programming/function)
	Types of User-defined Functions in C++(https://www.programiz.com/cpp-programming/user-defined-function-types)
	C++ Recursion(https://www.programiz.com/cpp-programming/recursion)
	C++ if, if...else and Nested if...else(https://www.programiz.com/cpp-programming/if-else)

	Then, the reverse() function is called which is a recursive function. 
	In the first function call, reverse() prints the last character of the string (numOfChars - 1), 
	-1 because array starts with 0.

*/

#include <iostream>
#include <string>

using namespace std;

void reverse(const string& a);

int main()
{
	string str;
	std::cout << " Please enter a string " << endl;
	std::getline (std::cin, str);
	reverse(str);
	return 0;
}

void reverse(const string& str)
{
	size_t numOfChars = str.size();
	if (numOfChars == 1)
		std::cout << str << endl;
	else
	{
		std::cout << str[numOfChars - 1];
		reverse(str.substr(0, numOfChars - 1));
	}
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
