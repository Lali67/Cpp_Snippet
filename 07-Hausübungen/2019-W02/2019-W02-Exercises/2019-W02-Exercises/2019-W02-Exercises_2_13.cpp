/* 2019-W02-Exercise_2_13.cpp :

Exercise 2.13
(*) Schreiben Sie einen Ausdruck (also keine Anweisung oder �hnliches), 
der eine positive Zahl x kaufm�nnisch korrekt rundet (also aufrunden ab 0.5 und abrunden darunter).

D�niel Sz�ke (11913915)
16.10.2019

*/

#include <iostream>

using namespace std;

int main()
{
	double x;

	// Get data
	cout << "This game..." << endl;
	cout << "Get number : "; cin >> x;
	cout << endl;
	cout << "Result (rounded): " <<(int)(x+0.5) << endl;
	
	return 0;
}
