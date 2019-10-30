/* 2019-W02-Exercise_4_14.cpp :

Exercise 4.14
  (*) Schreiben Sie eine Funktion, die einen String und zwei ganze Zahlen (basis1 und basis2) als 
  Parameter erhält und den String retourniert, der sich ergibt, wenn man den Eingangsstring als 
  eine ganze Zahl zur Basis basis1 interptretiert und in die basis2 umrechnet. 
  Die möglichen Basiswerte sind natürliche Zahlen von 1 bis 30.

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

//function a number in base1 to base2 
string convertBase1ToBase2(string n, int base1, int base2)
{
	long long number{ 0 }; int binaryNum{ 0 };
	string result;

	return result;
}

int main()
{
	string number; int base1, base2;

	cout << "This program...\n";
	cout << "Get value: ";  cin >> number;
	cout << "Get base1 and base2 (<30): "; cin >> base1 >> base2;
	cout << "Convert base1 to base2: " << convertBase1ToBase2(number, base1, base2) << endl << endl;
}
