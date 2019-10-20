/* 2019-W02-Exercise_2_8.cpp :

Exercise 2.8
Schreiben Sie ein Programm zur Umrechnung von Sekunden in die entsprechende Anzahl von Jahren, Tagen, 
Stunden, Minuten und Sekunden und umgekehrt. 
(Gehen Sie davon aus, dass ein Jahr immer 365 Tage hat. Schaltjahre bleiben also unberücksichtigt.


Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>

using namespace std;

const long long MIN_TO_SEC  = 60;
const long long HOUR_TO_SEC = 60 * MIN_TO_SEC;
const long long DAY_TO_SEC  = 24 * HOUR_TO_SEC;
const long long YEAR_TO_SEC = 365 * DAY_TO_SEC;

int main()
{
	long long sec=0;
	int calc_type = 0;
	
	// Get from the data to decide the type of calculation
	cout << "Get calculation type: \n(0): SEC -> Year, day, hour, min. sec \n";
	cout << "(1): Year, day, hour, min. sec -> SEC \n "; cin >> calc_type;

	if (calc_type == 0) {
		cout << "Get Seconds : "; cin >> sec;
		cout << "Result: " << sec / YEAR_TO_SEC <<" year(s) ";
		cout << (sec % YEAR_TO_SEC ) / DAY_TO_SEC << " day(s) ";
		cout << ((sec % YEAR_TO_SEC) % DAY_TO_SEC) / HOUR_TO_SEC << " hour(s) ";
		cout << (((sec % YEAR_TO_SEC) % DAY_TO_SEC) % HOUR_TO_SEC) / MIN_TO_SEC << " min(s) ";
		cout << (((sec % YEAR_TO_SEC) % DAY_TO_SEC) % HOUR_TO_SEC) % MIN_TO_SEC << " sec(s) " << endl;
	}
	else {
		long long values[5] = {0,0,0,0,0};
		cout << "Get Years   : "; cin >> values[0];
		cout << "Get Days    : "; cin >> values[1];
		cout << "Get Hours   : "; cin >> values[2];
		cout << "Get Minutes : "; cin >> values[3];
		cout << "Get Seconds : "; cin >> values[4];
		cout << "Result:       ";
		cout << values[0] * YEAR_TO_SEC + values[1] * DAY_TO_SEC + values[2] * HOUR_TO_SEC
			+ values[3] * MIN_TO_SEC + values[4];
		cout << " sec(s)" <<endl;
	}

	return 0;
}
