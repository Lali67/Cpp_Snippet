/* 2019-W02-Exercise_4_6.cpp :

Exercise 4.6
  Schreiben Sie eine Funktion int ggt(int a, int b), die den größten gemeinsamen Teiler der beiden natürlichen Zahlen
  a und b berechnet. Verwenden Sie die Funktion zum Testen in einem Hauptprogramm, das jeweils den Zähler und 
  den Nenner eines Bruches einliest und die gekürzte Version des Bruches ausgibt.

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
//#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

int ggt(int a, int b) {
	if (b == 0)
		return a;
	return ggt(b, a % b);
}


int main()
{
	string aString;

	cout << "This program...\n";
	cout << "-------- Test --------\n";
	cout << "a=8 b=6        : " << ggt(8,6) << endl;
	cout << "a=105 b=30     : " << ggt(105, 30) << endl;
	cout << "a=1024 b=128   : " << ggt(1024, 128) << endl;
	cout << endl;
	
	int a, b;
	cout << "Get a (a>0 integer)  : "; cin >> a;
	cout << "Get b (b>0 integer)  : "; cin >> b;
	cout << ggt(a, b);
	return 0;
	
}
