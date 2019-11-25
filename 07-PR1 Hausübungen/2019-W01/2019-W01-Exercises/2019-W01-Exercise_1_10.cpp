/* 2019-W01-Exercise_1_10.cpp: 

Exercise 1.10
Lesen Sie einen Wert x, sowie die Koeffizienten eines Polynoms vierten Grades ein 
und berechnen Sie den Wert des Polynoms an der Stelle x.


Dániel Szõke (11913915)
12.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	float x, a, b, c, d, e;
	
	cout << "Dieses Programm berechnet den Wert eines Polynoms vierten Grades an der Stelle x." << endl;
	cout << "Stelle(x): "; cin >> x;
	cout << "Koeffizienten (5 Stueck):"; cin >> a >> b >> c >> d >> e;

	float Resultat = a * pow(x, 4) + b * pow(x, 3) + c * pow(x, 2) + d * x + e;

	cout << "Resultat: " << Resultat; 

	return 0;
}

