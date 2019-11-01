/* 2019-W02-Exercise_4_7.cpp :

Exercise 4.7
  Schreiben Sie eine Funktion int binomial(int n, int k), die den Binomialkoeffizienten n über k berechnet.

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

/*
 int binomial(int n, int k)
  The value of C(n, k) can be recursively calculated using following standard formula:
  C(n, k) = C(n-1, k-1) + C(n-1, k)
  C(n, 0) = C(n, n) = 1
*/
long binomial(int n, int k)
{
	// Base Cases  
	if (k == 0 || k == n)
		return 1;

	// Recursion  
	return binomial(n - 1, k - 1) + binomial(n - 1, k);
}


int main()
{
	int n,k;

	cout << "This program...\n";
	cout << "-------- Test --------\n";
	cout << "n=1 k=1      : " << binomial(1, 1) << endl;
	cout << "n=10 k=3     : " << binomial(10,3) << endl;
	cout << "n=90 k=5     : " << binomial(90,5) << endl;
	cout << endl;

	cout << "Get n (n>0)       : "; cin >> n;
	cout << "Get k (k>0, k<n)  : "; cin >> k;
	cout << "Binomial value    : " << binomial(n,k) << endl << endl;
	
	return 0;
	
}
