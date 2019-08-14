// 008-Whether a character is Vowel or Consonant.cpp 
/*
	if...else statement is used to check whether an alphabet entered by the user is a vowel or a constant. 
		https://www.programiz.com/cpp-programming/examples/vowel-consonant

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)

	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/

#include <iostream>
using namespace std;

int main()
{
	char c;
	int isLowercaseVowel, isUppercaseVowel;
	std:cout << "Enter an alphabet: ";
	std:cin >> c;
	// evaluates to 1 (true) if c is a lowercase vowel
	isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	// evaluates to 1 (true) if c is an uppercase vowel
	isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	// evaluates to 1 (true) if either isLowercaseVowel or isUppercaseVowel is true
	if (isLowercaseVowel || isUppercaseVowel)
		std:cout << c << " is a vowel.";
	else
		std:cout << c << " is a consonant.";
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
