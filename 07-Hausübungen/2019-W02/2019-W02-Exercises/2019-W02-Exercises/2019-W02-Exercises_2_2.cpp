/* 2019-W02-Exercise_2_2.cpp :

Exercise 2.2
Schreiben Sie ein Programm, das eine dreistellige Zahl einliest und mit Hilfe der Ziffernsumme überprüft,
ob die eingegebene Zahl durch 3 teilbar ist.

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>
#include <cmath>
#include <assert.h> 

using namespace std;

string IsDivideby3(long long m)
{
	//1. Check input parameters
	//assert(m > 0);				// n must be positive

	//2. Run subprogram
	int count = 0, digit = 0, sum_digits = 0;
	while (m != 0 ) {
		digit = m - (m / 10) * 10;	//Z.B:  7 = 187-(187/10)*10 = 187-(18)*10=187-180 
		m = m / 10;					//Z.B: 18 = 187/10
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
	cout << "m=1111 : " << IsDivideby3(1111) << endl;
	cout << endl;

	// Get from the data from user to function
	long long m; int n;
	cout << "Dieses Programm berechnet...\n";
	cout << "Give m value: "; cin >> m;
	cout << "Result      : " << IsDivideby3(m) << endl;
}
