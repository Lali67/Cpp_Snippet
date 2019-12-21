// 1 Yard ist 3 Fuss und ein Fuss 12 Inch lang.
//Schreiben Sie ein Programm, das eine reelle Anzahl von Inch (double) einliest, 
//in Yard, Fuss und Inch umrechnet und das Ergebnis ausgibt.
//Beispiel: 200.5 Inch sind 5 Yard, 1 Fuss und 8.5 Inch.

#include <iostream>
//#include <cmath>
using namespace std;

const int Yard_in_Inch { 36 };
const int Fuss_in_Inch { 12 };

int main()
{
	
	//Eingabe als double-Wert einlesen
	double a;

		cout << "Dieses Programm gibt aus dem Eingabewert (Inch) einen Ausgabewert (Yard, Fuss, Inch) aus." << endl;
		cout << "Geben Sie hier den Eingabewert (Inch) ein: "; cin >> a;

	//Umwandlungsvariablen definieren und berechnen
	double yard{ 0 }, fuss{ 0 }, rest{ 0 };
	yard = int(a / Yard_in_Inch);
	rest = a - (yard * Yard_in_Inch);
	fuss = int(rest / Fuss_in_Inch);
	rest = rest - fuss * Fuss_in_Inch;

	//Ergebnis ausschreiben
		cout << a << " Inches sind " << yard << " Yard, " << fuss << " Fuss und " << rest << " Inch." << endl;

}