/* 2019-W02-Exercise_2_2.cpp :

Exercise 2.2
Schreiben Sie ein Programm, das eine dreistellige Zahl einliest und mit Hilfe der Ziffernsumme überprüft,
ob die eingegebene Zahl durch 3 teilbar ist.

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>
#include <exception> 

using namespace std;

string IsDivideby3(int m)
{
	//1. Check input parameters
	if (-999 > m || m > 999)
		throw("m muss dreistellig sein"); // m ist eine dreistellige Zahl

	//2. Run subprogram
	int count = 0, digit = 0, sum_digits = 0;
	while (m != 0 ) {
		//digit = m - (m / 10) * 10;	//Z.B:  7 = 187-(187/10)*10 = 187-(18)*10=187-180 
		digit = m % 10;					//Z.B:  7 = 187 % 10
		m = m / 10;						//Z.B: 18 = 187/10
		++count;

		sum_digits += digit;
	}
	string result = "";
	if (sum_digits % 3 != 0) result = "m is durch 3 nicht teilbar"; else result = "m ist durch 3 teilbar";

	return result;
}

int main()
{
	cout << "------------Test------------"  << endl;
	cout << "m=9    : " << IsDivideby3(9)    <<endl;
	cout << "m=123  : " << IsDivideby3(123)  << endl;
	cout << "m=311 :  " << IsDivideby3(311) << endl;
	cout << endl;

	// Get from the data from user to function
	int m, n;
	cout << "Dieses Programm ueberprueft, ob m durch 3 teilbar ist.\n";
	cout << "Geben Sie hier m ein: "; cin >> m;
	cout << "Ergebnis: " << IsDivideby3(m) << endl;
}
