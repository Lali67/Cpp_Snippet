/* 2019-W05-Exercise_5_06.cpp :

Exercise 5.6
  Schreiben Sie eine Funktion int ggt(int a, int b), die den größten gemeinsamen Teiler der beiden natürlichen Zahlen a und 
  b berechnet. Verwenden Sie keine Schleifen in der Funktion und testen Sie Ihre Funktion in einem Hauptprogramm, 
  das jeweils den Zähler und den Nenner eines Bruches einliest und die gekürzte Version des Bruches ausgibt.

Dániel Szöke (11913915)
08.11.2019

*/

#include <iostream>
//#include <vector>
//#include <cmath>
//#include <exception>

using namespace std;

int ggt(int a, int b) {
	if (b == 0)
		return a;
	return ggt(b, a % b);
}
// main function
int main(void)
{
	int a{ 105 }, b{ 35 };
	cout << "GGT von " << a << " und " << b << " ist " << ggt(a, b);
	cout << endl;

	a = 98; b = 56;
	cout << "GGT von " << a << " und " << b << " ist " << ggt(a, b);
	cout << endl;

	return 0;
}


