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
	cout << "Ganze Zahl oder nicht (Integer oder nicht)?" << endl;
	cout << "Geben Sie hier die Nummer ein (n) : "; cin >> x;
	cout << endl;
	
	if(abs(x) == floor(abs(x))) // no reminder
		cout << "Eine ganze Zahl"<< endl;
	else
		cout << "Keine ganze Zahl"<< endl;

	return 0;
}
