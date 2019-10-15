/* 2019-W01-Exercise_1_4.cpp: 

Exercise 1.4
Lesen Sie einen Radius r und einen Winkel a ein und berechnen Sie die Fläche des durch r und a definierten Kreissektors.

Dániel Szõke (11913915)
12.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265;


int main()
{
	double r, a;
	cout << "Dieses Programm berechnet die Fläche eines Kreissektors\n";
	cout << "Radius: ";	cin >> r;
	cout << "Winkel (degrees): ";	cin >> a;
	
	double Fläche = (r * r* PI*a)/360;
	

	cout << "Fläche: " << Fläche <<endl;
	return 0;
}

