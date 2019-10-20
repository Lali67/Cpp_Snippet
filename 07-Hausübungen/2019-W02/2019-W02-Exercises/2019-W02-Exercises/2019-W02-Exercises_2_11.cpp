/* 2019-W02-Exercise_2_11.cpp :


Exercise 2.11
Lesen Sie eine double Zahl ein und bestimmen Sie, ob der Benutzer eine ganze Zahl eingegeben hat oder nicht.

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x = 0;

	// Get data
	cout << "This game..." << endl;
	cout << "Get the number (n) : "; cin >> x;
	cout << endl;
	
	if(x == floor(abs(x))) // no reminder
		cout << "Integer value is given: " << x<< endl;
	else
		cout << "Integer value is NOT given: " << x << endl;

	return 0;
}
