/* 2019-W02-Exercise_2_9.cpp :

Exercise 2.9
Eine etwas verbissene Roulettespielerin setzt immer einen fixen Betrag auf die Zahl 0. 
Das macht sie so lange, bis diese Zahl endlich geworfen wird. 
Schreiben Sie ein Programm, das den Betrag und die Anzahl der benötigten Versuche einliest und 
daraus den Gewinn bzw. den Verlust der Roulettespielerin berechnet.


Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_ROULETTE_NUMBER = 36;
const int FAVORITE_NUM = 0;

int main()
{
	int random_Roulette_value;
	int trials = 0; long bet = 0, loss = 0, prize=0;

	// Get data
	cout << "This game..." << endl;
	cout << "Get the number of trials : "; cin >> trials;
	cout << "Get the amount of fix bet: "; cin >> bet;
	cout << endl;

	while (trials > 0) {
		//generate random number between 0 and 36
		random_Roulette_value = std::rand() / (RAND_MAX / MAX_ROULETTE_NUMBER);
		if (random_Roulette_value == FAVORITE_NUM)
			prize += bet;
		else
			loss += bet;

		--trials;
	};
	
	cout << "Total Prize: " << prize << "  Total Loss: " << loss << endl;

	return 0;
}
