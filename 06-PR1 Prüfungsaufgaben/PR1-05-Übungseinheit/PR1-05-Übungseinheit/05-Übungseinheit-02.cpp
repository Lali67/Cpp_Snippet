/* Schreiben Sie eine rekursive Funktion int anz_gleiche(int wert1, int wert2), 
die die Anzahl der �bereinstimmenden Stellen  in den 
als Parameter �bergebenen ganzen Zahlen (diese m�ssen ungleich 0 sein) retourniert.
Verwenden Sie in der Funktion keine Schleifen.
L�sen Sie das Problem iterativ. z.B.:
cout << anz_gleiche(1234, 4321) gibt 0 aus
cout << anz_gleiche(1234,5264) gibt 2 aus */

#include <iostream>
using namespace std;

//Die Funktion definieren
int anz_gleiche(int a, int b) {

	if (a,b == 0) return 0;
	else
		if (a % 10 == b % 10)
			return anz_gleiche(a / 10, b / 10) + 1;
}


int main() {

	int a, b;

	//Einlesen der ganzen Zahlen 
	cout << "Geben Sie hier die erste ganze Zahl ein: "; cin >> a;
	cout << "Geben Sie hier die zweite ganze Zahl ein: "; cin >> b;

	//Aufruf der Funktion und Ausgabewert ausschreiben
	cout << "Anzahl der uebereinstimmenden Stellen in den eingelesenen Zahlen: " << anz_gleiche(a, b) << endl;
}