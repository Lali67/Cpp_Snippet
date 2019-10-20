/* 2019-W02-Exercise_2_10.cpp :

Exercise 2.10
Ein Bierversand verkauft Fässer mit jeweils n Liter Fassungsvermögen. 
Die Kunden können beliebige Mengen in ganzen Litern bestellen. 
Schreiben Sie ein Programm, das n und eine Bestellmenge einliest und 
die Anzahl der benötigten Fässer berechnet. (Verwendung einer if-Anweisung ist erlaubt.)

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int n = 0; long amount_beer = 0;

	// Get data
	cout << "This game..." << endl;
	cout << "Get the volume of beer barrel (n) : "; cin >> n;
	cout << "Get the amount of beer (liter): "; cin >> amount_beer;
	cout << endl;
	
	if(amount_beer % n == 0) // no reminder
		cout << "Total Number of barrel: " << amount_beer / n << endl;
	else
		cout << "Total Number of barrel: " << amount_beer / n + 1 << endl;

	return 0;
}
