/* 2019-W02-Exercise_4_10.cpp :

Exercise 4.10
  Schreiben Sie eine Funktion, die eine nat�rliche Zahl als Parameter enth�lt und 
  einen String retourniert, der zun�chst alle Ziffern der Zahl von rechts nach links gelesen und
  jeweils durch ein Leerzeichen voneinander getrennt enth�lt, dann einen Stern und 
  alle Ziffern der Eingangszahl von links nach rechts gelesen und jeweils durch ein Leerzeichen getrennt. 
  Z.B.:
	Parameterwert: 12345
    Returnwert: "5 4 3 2 1 * 1 2 3 4 5"

D�niel Sz�ke (11913915)
29.10.2019

*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

string copyLongtoStringAndReverse(long n) {
	string result_left{ "" }, result_right{ "" }; int digit;
	
	while (n != 0) {
		digit = n % 10;
		n = n / 10;
		result_left   = result_left + " " + std::to_string(digit);
		result_right  = std::to_string(digit) + " "  + result_right;
	}

	return result_left + " * " + result_right;
}

int main()
{
	long n;

	cout << "This program...\n";
	cout << "Get parameter: ";  cin >> n;

	cout << "Expression: " << copyLongtoStringAndReverse(n) << endl;
}
