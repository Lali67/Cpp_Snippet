/* 2019-W01-Exercise_1_7.cpp: 

Exercise 1.7
Rechnen Sie Euro in Dollar um, bzw. umgekehrt.

Dániel Szõke (11913915)
12.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;

const float EUR_D_KURS = 1.1039;
const float D_EUR_KURS = 1/ EUR_D_KURS;

int main()
{
	int Euro, Dollar;
	cout << "Dieses Programm rechnet Euro in Dollar um.\n";
	cout << "Euro(ganze Zahl): ";	cin >> Euro;
	Dollar = Euro*EUR_D_KURS;
	cout << "Dollar(ganze Zahl): "<< Dollar <<endl;

	cout << "Dieses Programm rechnet Dollar in Euro um.\n";
	cout << "Dollar(ganze Zahl): ";	cin >> Euro;
	Dollar = Euro * D_EUR_KURS;
	cout << "Euro(ganze Zahl): " << Dollar << endl;

	return 0;
}

