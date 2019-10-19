/* 2019-W01-Exercise_1_9.cpp: 


Exercise 1.9
x Gramm Wasserstoff sollen verbrannt werden. 
Lesen Sie x ein und berechnen Sie,
Wieviel Gramm Sauerstoff für die Reaktion erforderlich sind 
und wieviel Milliliter Wasser entstehen.



Dániel Szõke (11913915)
12.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;

const int MOL_H_2 = 2;
const int MOL_O_2 = 32;
const int MOL_H_2O = 18;

int main()
{
	int x;
	cout << "Dieses Programm berechnet, wie viel Sauerstoff erforderlich ist.\n";
	cout << "Wasserstoff(g, > 4): "; cin >> x;
	
	// 2H_2 + O_2 = 2H_2O
	int Sauerstoff = x/(2*MOL_H_2)*MOL_O_2;
	cout << "Sauerstoff(g): " << Sauerstoff << endl;

	int Wasser = x / (2*MOL_H_2) * (2*MOL_H_2O);
	cout << "Dieses Programm berechnet, wie viel Wasser bei der Reaktion entsteht." << endl;
	cout << "Wasser(ml): " << Wasser <<endl;

	return 0;
}

