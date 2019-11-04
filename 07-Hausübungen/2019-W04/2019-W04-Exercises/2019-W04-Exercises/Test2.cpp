#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;
double a, b, Y;

int main() {

	cout << "Dieses Programm verwendet den Kosinussatz," << endl;
	cout << "um die Laenge der dritten Seite eines Dreiecks zu berechnen." << endl;
	cout << "Dazu geben Sie bitte die anderen Seiten (a, b)," << endl;
	cout << "bzw. den von diesen geschlossenen Winkel (Y) ein:" << endl;

	cout << "Erste Seite (a): "; cin >> a;
	cout << "Zweite Seite (b): "; cin >> b;
	cout << "Winkel (in Grad): "; cin >> Y;

	double y;

	y = (Y * PI) / 180;

	cout << "Die Laenge der dritten Seite (c) ist " << sqrt((a * a) + (b * b) - 2 * a * b * cos(y)) << "." << endl;

	return 0;
}


