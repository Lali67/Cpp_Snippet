/*Schreiben Sie ein Programm, das zwei ganze Zahlen einliest 
und ein Ergebnis aus den Ziffern der ersten Zahl bestimmt.
Dabei sind die Ziffern der zweiten Zahl(von rechts nach links) 
als Nummer der jeweils nächsten zu verwendenden Ziffer der ersten Zahl 
zu interpretieren.
Eingabe:5921 2314 Ergebnis: 5192
	Anmerkungen:Treten in der zweiten Zahl Positionen auf, 
	die in der ersten Zahl nicht vorkommen, 
	ist die entsprechende Stelle im Ergebnis 0.
	Das Ergebnis soll wieder in Form einer ganzen Zahl ermittelt werden.
	Anleitung : Sei  n die erste Zahl und m die zweite.
	Setzen Sie eine Summe auf 0. Durchlaufen Sie alle Ziffern der Zahl m.
	Für jede Ziffer z entfernen Sie aus einer Kopie von n die letzten z - 1 Ziffern.
	Setzen Sie die Summe auf das Zehnfache der bisherigen Summe plus der letzten Ziffer der so ermittelten Zahl.*/

#include <iostream>
//#include <cmath>
using namespace std;

int main()
{
	//Zwei Int-Werte definieren und einlesen (int=eingegebene Zahl)
	long n, m;

	cout << "Dieses Programm berechnet ein Ergebnis aus den Ziffern der ersten Zahl (bei 2 ganze Zahlen). " << endl;
	cout << "Geben Sie hier die erste Zahl ein: "; cin >> n;
	cout << "Geben Sie hier die zweite Zahl ein: "; cin >> m;
	
	//Schleife, die die zweite Zahl ziffernweise duchlaeuft
	while (m % 10 != 0) {
		//Position der Ziffer (z) bestimmen
		//Wenn diese Position in n existiert, nehmen wir die Zahl auf dieser Position aus, n(z)
		//und Summe = Summe * 10 + n(z)
		//Ansonsten Summe = Summe * 10 + 0
		//Schleifenvariable aendern
		m = m / 10;
	}
	//Ergebnis ausschreiben (Summe)
			

}