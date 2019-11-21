/* 2019-W05-Exercise_5_05.cpp :


Exercise 5.5
 Wie Beispiel 4, unterschiedliche Darstellungen, die sich durch Anwendung der Kommutativität der Addition ergeben 
 (z.B. 2+1 und 1+2), sind dabei aber nicht als verschieden anzusehen. Z.B für 4:
	4
	3+1
	2+2
	2+1+1

Dániel Szöke (11913915)
08.11.2019

*/

#include <iostream>
#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <exception>

using namespace std;

void printSumExpression(vector<int> out) {
	bool plus_sign{ false };
	for (auto i = out.begin(); i != out.end(); ++i) {
		if (plus_sign) {
			if (*i)	std::cout << '+' << *i;
		}
		else {
			if (*i)	std::cout << *i;
			plus_sign = true;
		}
	}
	cout << endl;
}


// Function to print all combination of numbers from i to n having sum n. 
//  Recursion: index denotes the next free slot in output array out
void allCombinationOfSum(int i, int n, vector<int> out, int index)
{
	// if sum becomes n, print the combination
	if (n == 0) {
			printSumExpression(out);
	}

	// start from previous element in the combination till n
	for (int j{ i }; j <= n; j++)
	{
		// place current element at current index
		out.at(index)= j;
		// recur with reduced sum
		allCombinationOfSum(j, n - j, out, index + 1);
	}
}

// main function
int main(void)
{
	int n1{ 4 }, n2{ 8 };
	vector<int> out1, out2;

	for (int i{ 0 }; i < n1; i++) out1.push_back(0);
	cout << "Alle Kombinationen printen von 1 bis 4 mit der Summe 4: \n";
	allCombinationOfSum(1, n1, out1, 0);

	for (int i{ 0 }; i < n2; i++) out2.push_back(0);
	cout << "Alle Kombinationen printen von 1 bis 8 mit der Summe 8: \n";
	allCombinationOfSum(1, n2, out2, 0);

	return 0;
}


