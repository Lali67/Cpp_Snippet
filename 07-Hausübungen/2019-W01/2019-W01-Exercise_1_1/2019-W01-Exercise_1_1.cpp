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
	double Länge, Breite;
	cout << "Dieses Programm berechnet den Umfang und die Fläche eines Rechtecks\n";
	cout << "Länge: ";	cin >> Länge;
	cout << "Breite: ";	cin >> Breite;

	double Umfang = 2 * (Länge + Breite);
	double Fläche = Länge * Breite;

	cout << "Umfang: " << Umfang << "\nFläche: " << Fläche <<endl;
	return 0;
}

