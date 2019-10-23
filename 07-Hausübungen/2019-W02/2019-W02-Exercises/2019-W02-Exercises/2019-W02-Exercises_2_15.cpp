/* 2019-W02-Exercise_2_15.cpp :


Exercise 2.15
(*) Ein Bierversand verkauft Fässer mit jeweils n Liter Fassungsvermögen. 
Die Kunden können beliebige Mengen in ganzen Litern bestellen. Schreiben Sie ein Programm, 
das n und eine Bestellmenge einliest und die Anzahl der benötigten Fässer mit einem Ausdruck berechnet. 
(Verwendung einer anderen Anweisung (if, switch, Schleife) oder einer bedingten Auswertung ist nicht erlaubt.

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>

using namespace std;

int main()
{
	int n=1, ordered_beer=0;
	// Get data
	cout << "Dieses Programm berechnet die Anzahl der benoetigten Faesser.\n";
	cout << "n: "; cin >> n;
	cout << "Geben Sie hier die Bestellmenge ein: "; cin >> ordered_beer;

	cout << "Sie bekommen " << ordered_beer / n + (int)(double((ordered_beer % n)) / double(n) + 3 * (1.0 / 3.0));
	cout << " Faesser.\n\n";

	return 0;
}
