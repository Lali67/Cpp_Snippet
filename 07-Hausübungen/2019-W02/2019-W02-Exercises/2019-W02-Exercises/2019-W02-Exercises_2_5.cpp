/* 2019-W02-Exercise_2_5.cpp :

Exercise 2.5
 Lesen Sie die Koordinaten zweier Punkte im R3 ein und berechnen Sie den Abstand 
 der beiden Punkte voneinander.

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>
#include <cmath>


using namespace std;

double distance2Points(	double x1, double y1, double z1,
						double x2, double y2, double z2)
{
	// Calculating distance 
	return sqrt(
		pow(x2 - x1, 2) +
		pow(y2 - y1, 2) +
		pow(z2 - z1, 2) );
}

int main()
{
	cout << "------------Test------------"  << endl;
	cout << "X1(1,2,3); X2(4,5,6)    : " << distance2Points(1,2,3,4,5,6) << endl;
	cout << "X1(0,0,0); X2(3,4,5)    : " << distance2Points(0, 0, 0, 3, 4, 5) << endl;
	cout << endl;

	// Get from the data from user to function
	double x1, x2, y1, y2, z1, z2;
	cout << "Dieses Programm berechnet...\n";
	cout << "Give X1 coordinates: "; cin >> x1 >> y1 >>z1;
	cout << "Give X2 coordinates: "; cin >> x2 >> y2 >> z2;
	cout << "Result      : " << distance2Points(x1, y1, z1, x2, y2, z2 ) << endl;
}
