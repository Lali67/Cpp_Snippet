
/*
	Description: c-tutorial-conditional-if-else-English.pdf
	Link: https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem

	Sample Input: 
		44
	Sample Output: 
		Greater than 9
*/
#include <iostream>

using namespace std;



int main()
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Write Your Code Here
	switch (n) {
	case 1: cout << "one";
		break;
	case 2: cout << "two";
		break;
	case 3: cout << "three";
		break;
	case 4: cout << "four";
		break;
	case 5: cout << "five";
		break;
	case 6: cout << "six";
		break;
	case 7: cout << "seven";
		break;
	case 8: cout << "eight";
		break;
	case 9: cout << "nine";
		break;
	default: cout << "Greater than 9";
		break;
	}

	return 0;
}
