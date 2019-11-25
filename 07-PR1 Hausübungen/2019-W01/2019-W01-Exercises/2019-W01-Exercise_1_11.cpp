/* 2019-W01-Exercise_1_11.cpp: 


Exercise 1.11
Lesen Sie fünf Messwerte einer Versuchsreihe ein und bestimmen Sie den Mittelwert.


Dániel Szõke (11913915)
13.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	float a, b, c, d, e;
	
	cout << "Dieses Programm berechnet den Mittelwert der Messwerte einer Versuchsreihe" << endl;
	
	cout << "Wert 1: "; cin >> a; 
	cout << "Wert 2: "; cin >> b; 
	cout << "Wert 3: "; cin >> c; 
	cout << "Wert 4: "; cin >> d; 
	cout << "Wert 5: "; cin >> e; 
	
	float Mittelwert = (a + b + c + d + e) / 5;
	cout << "Mittelwert: " << Mittelwert;
	

	return 0;
}

