/* 2019-W02-Exercise_2_13.cpp :

Exercise 2.13
(*) Schreiben Sie einen Ausdruck (also keine Anweisung oder Ähnliches), 
der eine positive Zahl x kaufmännisch korrekt rundet (also aufrunden ab 0.5 und abrunden darunter).

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>

using namespace std;

int main()
{
	double x;

	// Get data
	cout << "Dieses Programm rundet eine positive Zahl x kaufmaennisch korrekt." << endl;
	cout << "x : "; cin >> x;
	cout << endl;
	cout << "Ergebnis (gerundet): " <<(int)(x+0.5) << endl;
	
	return 0;
}
