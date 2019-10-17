/* 2019-W01-Exercise_1_12.cpp: 


Exercise 1.12
Schreiben Sie ein Programm, 
das die Wahrscheinlichkeit für einen Lottosechser beim österreichischen System (6 aus 45) berechnet.


Dániel Szõke (11913915)
13.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	float Resultat;
	
	cout << "Dieses Programm berechnet die Wahrscheinlichkeit fuer einen Lottosechser. (6 aus 45)" << endl;
	
	Resultat = (6 * 5 * 4 * 3 * 2 * 1.0) / (45 * 44 * 43 * 42 * 41 * 40);
	
	cout << "Resultat: " << Resultat << endl;

	return 0;
}

