/* 2019-W01-Exercise_1_8.cpp: 

Exercise 1.8
Ein Raumschiff startet von der Erde und bewegt sich gleichförmig mit x Prozent der Lichtgeschwindigkeit. 
Lesen Sie den Prozentsatz x ein und berechnen Sie, wie lange eine Reise zum Alpha Centauri für den Piloten dauert. 
Wieviel Zeit ist auf der Erde vergangen?


Dániel Szõke (11913915)
12.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;

const float DISTANZ = 4.36; // Lichtjahr

int main()
{
	float x;
	cout << "Dieses Programm berechnet die Länge der Reise zum Alpha Centauri mit x Prozent der Lichtgeschwindigkeit.\n";
	cout << "Prozentsatz(0-100): ";	cin >> x;
	float Result = DISTANZ / (x / 100);
	cout << Result << " Jahr(en) ist/sind auf der Erde vergangen." << endl;

	return 0;
}

