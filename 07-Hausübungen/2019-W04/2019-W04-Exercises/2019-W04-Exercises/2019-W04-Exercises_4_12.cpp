/* 2019-W02-Exercise_4_12.cpp :


Exercise 4.12
  (*) Schreiben Sie eine Funktion, die eine natürliche Zahl n als Parameter erhält und 
  die expandierte Form des Ausdrucks (a+b)n als String retourniert. Also 
  z.B.:
  Parameter: 3
  Returnwert: "a^3+3a^2b+3ab^2+b^3"

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

/* 
getBinomialCoeff(int n, int k)
  The value of C(n, k) can be recursively calculated using following standard formula:
  C(n, k) = C(n-1, k-1) + C(n-1, k)
  C(n, 0) = C(n, n) = 1
*/
int getBinomialCoeff(int n, int k)
{
	// Base Cases  
	if (k == 0 || k == n)
		return 1;

	// Recursion  
	return getBinomialCoeff(n - 1, k - 1) +	getBinomialCoeff(n - 1, k);
}

string getBinomialString(int n) {
	string result{ "" }, coeffString{ "" };
	string a_i{ "" }, b_i{ "" }, plusSign{ "+" };
	int k{ 0 };

	for (int k = 0; k < n + 1; k++) {
		coeffString = std::to_string(getBinomialCoeff(n, k));
		if (coeffString == "1") coeffString = "";

		//Calculate a_i
		if (n-k > 1) 
			a_i = "a^" + std::to_string(n - k);
		else if (n - k == 1)
			a_i = "a";
			else
				a_i = "";
		//Calculate b_i
		if (k > 1)
			b_i = "b^" + std::to_string(k);
		else if (k == 1)
			b_i = "b";
		else
			b_i = "";
		//Calculate whether adding plusSign
		if (k == 0) plusSign = "";
		else plusSign = "+";

		result = result + plusSign + coeffString + a_i + b_i;
	}

	return result;
}

int main()
{
	int n;

	cout << "This program...\n";
	cout << "Get parameter: ";  cin >> n;

	cout << "Expression (a+b)^n = " << getBinomialString( n ) << endl;
}
