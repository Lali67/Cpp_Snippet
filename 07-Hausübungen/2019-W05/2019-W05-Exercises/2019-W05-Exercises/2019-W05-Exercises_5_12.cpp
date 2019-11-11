/* 2019-W02-Exercise_5_12.cpp :

Exercise 5.12
 Schreiben Sie eine Funktion, die eine natürliche Zahl als Parameter erhält und 
 die Anzahl der möglichen Darstellungen der Zahl als eine Summe aufeinanderfolgender natürlicher Zahlen retourniert. 
 Für 15 würde z.B. 3 retourniert, da 15 dargestellt werden kann als 7+8, 4+5+6, 1+2+3+4+5.
 Verwenden Sie keine Schleife in der Funktion.

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

int vecSum(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (begin != end)
		return *begin + vecSum(++begin, end);
	return 0;
}

int vecSum(std::vector<int> list)
{
	return vecSum(list.begin(), list.end());
}

// Function to print all combination of numbers from i to n having sum n. 
//  Recursion: index denotes the next free slot in output array out
void allCombinationOfSum(vector<int> inVec, int n, unsigned int left=0, unsigned int middle=0, unsigned int right=0, 
							vector<int> outVec = {0,0} )
{
	
	if (left < inVec.size()) {
		if (middle < inVec.size()) {
			if (right <= middle) {
				outVec.push_back(inVec.at(right));
				allCombinationOfSum(inVec, n, left, middle, ++right, outVec);
			}
			else {
				if (vecSum(outVec) == n) printSumExpression(outVec);
				outVec.clear();
				allCombinationOfSum(inVec, n, left, ++middle, left, outVec);
			}
		}
		else {
			outVec.clear();
			allCombinationOfSum(inVec, n, ++left, left, right, outVec);
		}
	}
	else
		return;

}

// main function
int main(void)
{
	int n1{ 15 };
	vector<int> out1, out2;

	cout << "-------- Test --------\n";
	for (int i{ 0 }; i < n1/2+1; i++) out1.push_back(i+1);
	cout << "Alle Kombinationen printen von 1 bis 8 mit der Summe 15: \n";
	allCombinationOfSum(out1, 15);

	return 0;
}