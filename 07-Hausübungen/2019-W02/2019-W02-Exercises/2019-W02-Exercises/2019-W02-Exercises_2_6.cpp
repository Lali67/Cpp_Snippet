/* 2019-W02-Exercise_2_6.cpp :

Exercise 2.6
Berechnen Sie ax^2+bx+c mit Hilfe des Horner-Schemas für beliebige Eingaben von a,b,c und x.

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>

using namespace std;

// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
double horner(double *poly, double x, int n=2)
{
	double result = poly[0];  // Initialize result

	// Evaluate value of polynomial using Horner's method
	for (int i = 0; i < n; i++) {
		result = result * x + poly[i];
	}

	return result;
}

int main()
{
	double coeff[3] = { 1,2,3 }, x; 
	cout << "------------Test------------"  << endl;
	cout << "x:1   coeff:[1,2,3]     : " << horner(coeff, 1) << endl; //7
	coeff[0] = 4; coeff[1] = 4; coeff[2] = 4;
	cout << "x:2   coeff:[4,4,4]     : " << horner(coeff, 2) << endl; //4*4+4*2+4=28
	cout << endl;

	// Get from the data of user to function
	cout << "This program calculate...\n";
	cout << "Get x :"; cin >> x; 
	cout << "Get coeff :"; cin >> coeff[0] >> coeff[1] >> coeff[2];

	cout << "Result   : " << horner(coeff, x) << endl;

}
