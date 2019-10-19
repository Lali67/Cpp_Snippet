/* 2019-W02-Exercise_2_3.cpp :

Exercise 2.3
Schreiben Sie ein Programm, das eine dreistellige Zahl einliest und die Zahl ausgibt, die durch Umkehrung der Ziffernfolge entsteht.
Z.B.: Eingabe: 123 Ausgabe: 321

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>
#include <assert.h> 

using namespace std;

int ReverseNumber(int m)
{
	//1. Check input parameters
	assert( -1000 < m && m < 1000); // m ist eine dreistellige Zahl
	

	//2. Run subprogram
	int count = 0, reversedNumber = 0, remainder;
	while (m != 0 ) {
		remainder = m % 10;		//Z.B:  7 = 187 % 10 
		reversedNumber = reversedNumber * 10 + remainder; //Z.B:  78 = 7*10 + 8 
		m = m / 10; //Z.B: 18 = 187/10
		++count;
	}

	return reversedNumber;
}

int main()
{
	cout << "------------Test------------"  << endl;
	cout << "m=9    : " << ReverseNumber(9)   << endl;
	cout << "m=123  : " << ReverseNumber(123) << endl;
	cout << "m=19   : " << ReverseNumber(19)  << endl;
	cout << endl;

	// Get from the data from user to function
	int m, n;
	cout << "Dieses Programm berechnet...\n";
	cout << "Give m value: "; cin >> m;
	cout << "Result      : " << ReverseNumber(m) << endl;
}
