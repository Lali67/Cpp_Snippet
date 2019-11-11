/* 2019-W02-Exercise_5_04.cpp :

Exercise 5.4
  Schreiben Sie eine Funktion, die eine positive Zahl n als Parameter erhält und alle unterschiedlichen Möglichkeiten ausgibt, 
 die Zahl als eine Summe von positiven Zahlen darzustellen. Für die Eingabe 4 soll z.B. Folgendes ausgegeben werden:
	4
	3+1
	2+2
	2+1+1
	1+3
	1+2+1
	1+1+2
	1+1+1+1
Hinweis: 
  Als ersten Summanden kann man jede positive Zahl kleiner als n wählen. Die möglichen Summendarstellungen 
  mit diesem ersten Summanden sind genau die möglichen Summendarstellungen der verbliebenen Differenz. 
  Z.B.: 
    Ist n gleich 4 und man wählt den ersten Summanden 1, so ist die Differenz 3. 
	Für 3 gibt es die Möglichkeiten 3, 2+1, 1+2 und 1+1+1.
	4 kann also mit 1 als erstem Summanden auf die vier Arten 1+3, 1+2+1, 1+1+2 und 1+1+1+1 dargestellt werden.

Dániel Szöke (11913915)
08.11.2019

*/

#include <iostream>
#include <vector>
#include <algorithm>
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
void allCombinationWithPermutationOfSum(int i, int n, vector<int> out, int index)
{
	// if sum becomes n, print the combination
	if (n == 0) {
		vector<int> temp;
		for (auto i = out.begin(); i != out.end(); ++i) if(*i) temp.push_back(*i);
		//Rearranges the elements in the range [first,last) into the next lexicographically greater permutation
		do {
			printSumExpression(temp);
		} while (std::next_permutation(temp.begin(), temp.end()));
	}

	// start from previous element in the combination till n
	for (int j{ i }; j <= n; j++)
	{
		// place current element at current index
		out.at(index)= j;
		// recur with reduced sum
		allCombinationWithPermutationOfSum(j, n - j, out, index + 1);
	}
}

// main function
int main(void)
{
	int n1{ 4 }, n2{ 8 };
	vector<int> out1, out2;

	for (int i{ 0 }; i < n1; i++) out1.push_back(0);
	cout << "Alle Kombinationen printen von 1 bis 4 mit der Summe 4: \n";
	allCombinationWithPermutationOfSum(1, n1, out1, 0);

	for (int i{ 0 }; i < n2; i++) out2.push_back(0);
	cout << "Alle Kombinationen printen von 1 bis 8 mit der Summe 8: \n";
	allCombinationWithPermutationOfSum(1, n2, out2, 0);

	return 0;
}


