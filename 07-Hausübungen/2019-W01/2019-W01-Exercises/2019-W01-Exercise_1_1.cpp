/* 2019-W01-Exercise_1_1.cpp : 
Exercise 1.1 
Lesen Sie die L�nge und die Breite eines Rechtecks ein und berechnen Sie daraus den Umfang 
und die Fl�che des Rechtecks. 

D�niel Sz�ke (11913915)
12.10.2019

*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	double L�nge, Breite;
	cout << "Dieses Programm berechnet den Umfang und die Fl�che eines Rechtecks\n";
	cout << "L�nge: ";	cin >> L�nge;
	cout << "Breite: ";	cin >> Breite;

	double Umfang = 2 * (L�nge + Breite);
	double Fl�che = L�nge * Breite;

	cout << "Umfang: " << Umfang << "\nFl�che: " << Fl�che <<endl;
	return 0;
}

