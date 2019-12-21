// Schreiben Sie in Programm, das drei ganze Zahlen (int) einliest und 
//das harmonische Mittel dieser Zahlen berechnet und ausgibt. 
//Beachten Sie, dass das Ergebnis in der Regel keine ganze Zahl ist.
//Geben Sie eine geeignete Fehlermeldung aus, falls die Berechnung (wegen Division durch 0) nicht durchführbar ist.
//Formel zum harmonischen Mittel: 3/(1/a+1/b+1/c)

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//Die drei integer-Werte als double (a, b, c) einlesen und definieren
	int a, b, c;

	cout << "Dieses Programm berechnet das harmonische Mittel dreier ganzen Zahlen." << endl;
	cout << "Geben Sie hier die erste ganze Zahl ein: "; cin >> a;
	cout << "Geben Sie hier die zweite ganze Zahl ein: "; cin >> b;
	cout << "Geben Sie hier die dritte ganze Zahl ein: "; cin >> c;

	//Ergebnis berechnen
	double e, E;

	e = (1.0 / a + 1.0 / b + 1.0 / c);

	//Fehlerkorrektur durch If-Else Statement (und Ergebnis ausschreiben)
	if (e == 0)
		cout << "Die Operation kann nicht durchgefuehrt werden! (Wegen Division durch 0)" << endl;
	else {
		E = (3 / e);
		cout << "Das harmonische Mittel: " << E << endl;
	}
}

