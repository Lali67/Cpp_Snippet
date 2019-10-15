/* 2019-W01-Exercise_1_2.cpp : 

Exercise 1.2
Lesen Sie Artikelpreis, Anzahl und Mehrwertsteuersatz ein und geben Sie den Gesamtpreis aus.

Dániel Szõke (11913915)
12.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	double Artikelpreis, Anzahl, Mehrwertsteuersatz;
	cout << "Dieses Programm berechnet den Gesamtpreis\n";
	cout << "Artikelpreis: ";	cin >> Artikelpreis;
	cout << "Anzahl: ";	cin >> Anzahl;
	cout << "Mehrwertsteuersatz (in Prozent): ";	cin >> Mehrwertsteuersatz;
	

	double Gesamtpreis = Anzahl * Artikelpreis * (1 + Mehrwertsteuersatz/100);
	

	cout << "Gesamtpreis: " << Gesamtpreis <<endl;
	return 0;
}

