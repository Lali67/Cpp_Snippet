/* 2019-W02-Exercise_2_12.cpp :

Exercise 2.12
Lesen Sie zwei ganze Zahlen ein und ermitteln Sie, 
ob die zuletzt eingegebene Zahl ein Teiler der zuerst eingegebenen Zahl ist.

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x, y;

	// Get data
	cout << "Teiler oder nicht?" << endl;
	cout << "Geben Sie hier zwei Integers ein: "; cin >> x >> y;
	cout << endl;
	
	if(x % y == 0) // no reminder
		cout << y << " teilt" << x << endl;
	else
		cout << y << " teilt" << x << " nicht" << endl;

	return 0;
}
