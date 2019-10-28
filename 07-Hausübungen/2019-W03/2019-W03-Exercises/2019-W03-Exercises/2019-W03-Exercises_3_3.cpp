/* 2019-W02-Exercise_3_3.cpp :


Exercise 3.3
 Schreiben Sie ein Programm zur Lösung der quadratischen Gleichung x^2+px+q=0 
  (Achtung: eventuelle komplexe Lösungen beachten)

 Anmerkung: In der Klassenbibliothek cmath befindet sich die Funktion sqrt(), 
  die zur Berechnung der Quadratwurzel dient. Der übergebene Wert sollte nicht kleiner als 0 (Null) sein, 
  sonst wird ein Fehler ausgelöst.


Dániel Szöke (11913915)
24.10.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;

/***
 Calculate the roots of single-variable quadratic polynomial and print them 
 The complex roots can be calculated

***/
void printRoots(double a, double b, double c) {
	double x1, x2, Discriminant, realPart, imaginaryPart;
	
	// Calculate Discriminant
	Discriminant = b * b - 4 * a * c;

	if (Discriminant > 0) {
		x1 = (-b + sqrt(Discriminant)) / (2 * a);
		x2 = (-b - sqrt(Discriminant)) / (2 * a);
		cout << " Wurzeln sind real und unterschiedlich." << endl;
		cout << "  x1 = " << x1 << endl;
		cout << "  x2 = " << x2 << endl;
	}
	else if (Discriminant == 0) {
		cout << " Wurzeln sind real und gleich." << endl;
		x1 = (-b + sqrt(Discriminant)) / (2 * a);
		cout << "  x1 = x2 =" << x1 << endl;
	}
	else {
		realPart = -b / (2 * a);
		imaginaryPart = sqrt(-Discriminant) / (2 * a);
		cout << " Wurzeln sind komplex und unterschiedlich." << endl;
		cout << "  x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
		cout << "  x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
	}
}


int main()
{
	cout << "------------Test------------" << endl;
	cout << "a=1, b=-3, c=1      :  " << endl;
	printRoots(1, -3, 1); 
	cout << endl;
	cout << "a=5, b=6, c=1     :    " << endl;
	printRoots(5, 6, 1);
	cout << endl;
	cout << "a=5, b=2, c=1       :  " << endl;
	printRoots(5, 2, 1);
	cout << endl;
	cout << endl;

	// Get from the data from user to function
	double a, b, c;
	cout << "Dieses Programm dient zur Loesung der quadratischen Gleichung x^2+px+q=0\n";
	cout << "Bitte geben Sie hier a, b, c ein "; cin >> a >> b >> c;
	printRoots(a, b, c);
}
