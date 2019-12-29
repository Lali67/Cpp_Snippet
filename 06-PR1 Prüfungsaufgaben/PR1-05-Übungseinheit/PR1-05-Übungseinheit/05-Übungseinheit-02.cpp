 /* //Schreiben Sie eine rekursive Funktion int anz_gleiche(int wert1, int wert2), 
die die Anzahl der übereinstimmenden Stellen  in den 
als Parameter übergebenen ganzen Zahlen (diese müssen ungleich 0 sein) retourniert.
Verwenden Sie in der Funktion keine Schleifen.
Lösen Sie das Problem iterativ. z.B.:
cout << anz_gleiche(1234, 4321) gibt 0 aus
cout << anz_gleiche(1234,5264) gibt 2 aus */

#include <iostream>
using namespace std;

//Die Funktionen definieren
int anz_gleiche(int a, int b) {
	//Wenn a = 0 oder b = 0, dann return 0
	//ansonsten wenn a % 10 = b % 10, dann return anz_gleiche(a / 10, b / 10)+1
	//ansonsten rufen wir wieder die Funktion auf, ohne 1 dazu zu addieren
	
	if (a == 0 || b == 0) return 0;
	else
		if (a % 10 == b % 10)
			return anz_gleiche(a / 10, b / 10) + 1;
		else 
			return anz_gleiche(a / 10, b / 10);
}


int main() {

	int a, b;

	//Einlesen der ganzen Zahlen 
	cout << "Geben Sie hier die erste ganze Zahl ein: "; cin >> a;
	cout << "Geben Sie hier die zweite ganze Zahl ein: "; cin >> b;

	//Aufruf der Funktion und Ausgabewert ausschreiben
	cout << "Anzahl der uebereinstimmenden Stellen in den zwei Zahlen: " << anz_gleiche(a, b) << endl;
}