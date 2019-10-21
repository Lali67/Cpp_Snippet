/* 2019-W02-Exercise_2_7.cpp :

Exercise 2.7
Schreiben Sie ein Programm zur Umrechnung von Euro in Dollar und umgekehrt. 
Geben Sie das Ergebnis formatiert in Euro und Cent bzw. Dollar und Cent aus. 
(Betragsteile kleiner als ein Cent können Sie ignorieren.

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>
#include <cmath>

const double EUR_USD_KURS = 1.1039;
const double USD_EUR_KURS = 1 / EUR_USD_KURS;

using namespace std;

int main()
{
	int USD, EUR, cent, value;
	int exchange_type = 0;
	// Euro cents: 1, 2, 5, 10, 20, 50
	// Dollar cents: 1, 5, 10, 25, 50
	
	// Get from the data to decide the type of exchanging money
	cout << "Umrechnungstyp (0)-EUR_USD (1)-USD_EUR : "; cin >> exchange_type;
	if (exchange_type == 0) {
		cout << "Euro : "; cin >> value;
		USD = value / EUR_USD_KURS;
		cent = round((value / EUR_USD_KURS - USD) * 100);
		cout << "Ergebnis : " << USD << " dollar(s) " << cent << " cent(s)" << endl;
	}
	else {
		cout << "Dollar : "; cin >> value;
		EUR = value / USD_EUR_KURS;
		cent = round((value / USD_EUR_KURS - EUR) * 100);
		cout << "Ergebnis : " << EUR << " euro(s) " << cent << " cent(s)" << endl;
	}

}
