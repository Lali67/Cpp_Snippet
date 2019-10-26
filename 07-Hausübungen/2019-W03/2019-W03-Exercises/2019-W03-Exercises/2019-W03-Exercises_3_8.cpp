/* 2019-W02-Exercise_3_8.cpp :

Bestimmen Sie den Wert
sum(i=1,n){i^i}
(also 1^1+2^2+3^3+…+n^n für eine beliebige natürliche Zahl n).
Die Verwendung von mathematischen Funktionen (wie z.B. pow aus cmath) ist nicht erlaubt.

Dániel Szöke (11913915)
26.10.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;


int main()
{
	long n{ 0 }, result{ 0 };

	cout << "This program...\n";
	cout << "Enter the  (positive integer) value: ";	cin >> n;
	//Check n
	if (n < 1)
		throw("n must be positive");


	for (long i = 1; i <= n; i++) {
		result = result + i * i;
	}
	cout << "Result : " << result;
	cout << endl;
	

	return 0;
}
