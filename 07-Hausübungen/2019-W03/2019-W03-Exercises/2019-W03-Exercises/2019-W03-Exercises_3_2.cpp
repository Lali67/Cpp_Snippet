/* 2019-W02-Exercise_3_2.cpp :

Exercise 3.2
Schreiben Sie ein Programm, das eine vierstellige ganze Zahl einliest und 
ihre sprachliche Repräsentation ausgibt.
Z.B.
Eingabe 1723
Ausgabe eins-sieben-zwei-drei

Dániel Szöke (11913915)
24.10.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;


string toWords(int a)
{
	const string digitWord[] = { "null", "eins", "zwei", "drei", "vier", "fuenf", "sechs", "sieben", "acht", "neun" };
	string digitsToWords{""};
	int digit{0};

	if (a < 1000 || a > 9999)
		throw("Die Nummer muss zwischen 1000 und 9999 sein");

	while (a != 0) {
		digit = a % 10;
		a = a / 10;
		digitsToWords = digitWord[digit] + digitsToWords;
		if (a != 0) digitsToWords = "-" + digitsToWords;
	}

	return digitsToWords;
}


int main()
{
	cout << "------------Test------------" << endl;
	cout << "a=1940     :  " << toWords(1940) << endl;
	cout << "a=7061     :  " << toWords(7061) << endl;
	cout << endl;

	// Get from the data from user to function
	int a;
	cout << "Dieses Programm gibt die sprachliche Repraesentation einer vierstelligen Zahl.\n";
	cout << "Bitte geben Sie hier a ein (a>999 und a<10000, a ist vierstellig): "; cin >> a;
	cout << "Resultat: " << toWords(a);
}
