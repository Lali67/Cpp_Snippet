// Schreiben Sie ein Programm, das die Laengen zweier Dreiecksseiten a und b, 
//sowie den von diesen eingeschlossenen Winkel Y (in Grad) einliest 
//und die Laenge der dritten Seite c mit Hilfe des Kosinussatzes berechnet und ausgibt.
//Hinweise: cos(x), sqrt(x) !!

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159;

int main()
{
	double a, b, Y;
	//Die zwei Dreieckseiten (a, b) und den Winkel (Y) einlesen
	cout << "Geben Sie bitte die erste Seite (a >= 0) ein: "; cin >> a;
	cout << "Geben Sie bitte die zweite Seite (b >= 0) ein: "; cin >> b;
	cout << "Geben Sie bitte den Winkel (Y, in Grad) ein: "; cin >> Y;

	//Von Grad in Bogenmaﬂ umwandeln ((PI*Y)/180)
	Y = (Y * PI) / 180;

	//Kosinussatz berechnen ( c = a*a+b*b+2*a*b*cosY)
	double c;
	c = sqrt(a * a + b * b + 2 * a * b * cos(Y));
	
	//Ergebnis ausschreiben
	cout << "Der Wert der dritten Seite: " << c << endl;

	return 0;
}