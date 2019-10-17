/* 2019-W01-Exercise_1_15.cpp: 


Exercise 1.15
Lesen Sie fünf Messwerte einer Versuchsreihe ein und bestimmen Sie den Mittelwert. 
Verwenden Sie dazu maximal 2 Variable mit fundamentalem Datentyp.


Dániel Szõke (11913915)
13.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	float a, Mittelwert = 0;
	
	cout << "Dieses Programm berechnet den Mittelwert der Messwerte einer Versuchsreihe" << endl;
	
	for(int i = 0; i < 5; i++){
		cout << "Wert " << i + 1 << ": "; cin >> a;
		Mittelwert += a / 5.0;
	}

	cout << "Mittelwert: " << Mittelwert << endl;
	

	return 0;
}

