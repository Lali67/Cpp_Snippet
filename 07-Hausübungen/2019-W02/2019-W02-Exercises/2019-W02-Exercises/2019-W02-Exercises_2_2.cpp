/* 2019-W02-Exercise_2_2.cpp :

Exercise 2.2
Schreiben Sie ein Programm, das eine dreistellige Zahl einliest und mit Hilfe der Ziffernsumme überprüft,
ob die eingegebene Zahl durch 3 teilbar ist.

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>
#include <assert.h> 

using namespace std;

string IsDivideby3(int m)
{
	//1. Check input parameters
	assert(-1000 < m && m < 1000); // m ist eine dreistellige Zahl

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
	if (sum_digits % 3 != 0) result = "False"; else result = "True";

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
	cout << "Dieses Programm berechnet...\n";
	cout << "Give m value: "; cin >> m;
	cout << "Result      : " << IsDivideby3(m) << endl;
}
