/* 2019-W02-Exercise_2_1.cpp :
Schreiben Sie ein Programm, das zwei Zahlen m und n einliest und die n-te Ziffer der Zahl m ausgibt.
Z.B.: m=1358 n=2 Ausgabe: 5 (Die Ziffern werden ausgehend vom Dezimalpunkt gezählt).

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>
#include <cmath>
#include <exception> 

using namespace std;

int countDigit(long long m, const int n)
{
	//1. Check input parameters
	if(n < 1) 
		throw("n muss groesser sein als 0");				 
	if(m<=pow(10,n-1))
		throw("checken ob die Nummer von den Ziffern von m <= n");		

	//2. Run subprogram
	int count = 0, digit = -1;
	while ((m != 0) && (count!=n) ) {
		//digit = m - (m / 10) * 10;	//Z.B:  7 = 187-(187/10)*10 = 187-(18)*10=187-180 
		digit = m % 10;					//Z.B:  7 = 187 % 10
		m = m / 10;						//Z.B: 18 = 187/10
		++count;
	}
	return digit;
}

int main()
{
	cout << "------------Test------------" << endl;
	cout << "m=8, n=1:        " << countDigit(8,1) <<endl;	// 8
	cout << "m=1358, n=2:     " << countDigit(1358, 2) << endl; //5
	cout << "m=11913915, n=6: " << countDigit(11913915, 6) << endl; //9
	cout << endl;

	// Get from the data from user to function
	long long m; int n;
	cout << "Dieses Programm gibt die n-te Ziffer der Zahl m aus.\n";
	cout << "Bitte geben Sie hier m ein: "; cin >> m;
	cout << "Bitte geben Sie hier n ein: "; cin >> n;
	cout << "Ergebnis: " << countDigit(m, n) << endl;
}
