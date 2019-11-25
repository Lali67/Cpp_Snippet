/* 2019-W01-Exercise_1_1.cpp : 
Exercise 1.1 
Lesen Sie die Länge und die Breite eines Rechtecks ein und berechnen Sie daraus den Umfang 
und die Fläche des Rechtecks. 

Dániel Szõke (11913915)
12.10.2019

*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	double Laenge, Breite;
	cout << "Dieses Programm berechnet den Umfang und die Flaeche eines Rechtecks\n";
	cout << "Laenge: ";	cin >> Laenge;
	cout << "Breite: ";	cin >> Breite;

	double Umfang = 2 * (Laenge + Breite);
	double Flaeche = Laenge * Breite;

	cout << "Umfang: " << Umfang << "\nFlaeche: " << Flaeche <<endl;
	return 0;
}

