/* 2019-W01-Exercise_1_4.cpp: 

Exercise 1.4
Lesen Sie einen Radius r und einen Winkel a ein und berechnen Sie die Fl�che des durch r und a definierten Kreissektors.

D�niel Sz�ke (11913915)
12.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265;


int main()
{
	double r, a;
	cout << "Dieses Programm berechnet die Fl�che eines Kreissektors\n";
	cout << "Radius: ";	cin >> r;
	cout << "Winkel (degrees): ";	cin >> a;
	
	double Fl�che = (r * r* PI*a)/360;
	

	cout << "Fl�che: " << Fl�che <<endl;
	return 0;
}

