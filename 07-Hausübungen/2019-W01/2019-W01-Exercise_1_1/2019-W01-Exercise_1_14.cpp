/* 2019-W01-Exercise_1_14.cpp: 

Lesen Sie einen Wert x, sowie die Koeffizienten eines Polynoms vierten Grades ein 
und berechnen Sie den Wert des Polynoms an der Stelle x. Verwenden Sie dazu maximal 3 Variable mit fundamentalem Datentyp. 
Außerdem sollen bei der Berechnung maximal 4 Multiplikationen durchgeführt werden.


Dániel Szõke (11913915)
13.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	float x, y, Resultat = 0;
	
	cout << "Dieses Programm berechnet den Wert eines Polynoms vierten Grades an der Stelle x." << endl;
	cout << "Stelle(x): "; cin >> x;
	cout << "Koeffizienten (5 Stueck):\n"; 
	for (int i = 4; i >= 0; i--) {
		cin >> y;
		Resultat += y * pow(x, i);
	}
	
	cout << "Resultat: " << Resultat; 

	return 0;
}

