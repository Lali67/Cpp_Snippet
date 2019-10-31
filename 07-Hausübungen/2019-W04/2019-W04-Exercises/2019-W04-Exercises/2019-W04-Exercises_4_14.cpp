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

int charPositionIn(string aString, char c) {
	int pos = std::string(aString).find(c);
	return pos;
}

//function a number in base1 to base2 
string convertBase1ToBase2(string n, int base1, int base2)
{
	static char base36[]{ "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	long long number{ 0 }, coeff10{ 1 }; int value;
	string result{""};

	if (base1 < 2 || base2 < 2)
		throw("The base must be bigger than 1!");

	//convert n to number(base 10)
	for (int i = n.length()-1; i > -1; i--) {
		value = charPositionIn(base36, n[i]);
		if(value == -1 || value > base1)
			throw("This character is not fit to base1:" + n[i]);
		number  += value * coeff10;
		coeff10 *= base1;
	}

	//convert number to the numeral system of base2 
	while (number > 0) {
		value   = number % base2;
		number  = number / base2;
		result  = base36[value] + result;
	}

	return result;
}

int main()
{
	string numberString; int base1, base2;

	cout << "This program...\n";
	cout << "Get value: ";  cin >> numberString;
	cout << "Get base1 and base2 (<30): "; cin >> base1 >> base2;
	cout << "Convert base1 to base2: " << convertBase1ToBase2(numberString, base1, base2) << endl << endl;
}
