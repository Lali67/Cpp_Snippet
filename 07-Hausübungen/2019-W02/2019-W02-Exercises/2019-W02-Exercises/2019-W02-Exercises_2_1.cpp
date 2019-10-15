/* 2019-W02-Exercise_2_1.cpp :
Schreiben Sie ein Programm, das zwei Zahlen m und n einliest und die n-te Ziffer der Zahl m ausgibt.
Z.B.: m=1358 n=2 Ausgabe: 5 (Die Ziffern werden ausgehend vom Dezimalpunkt gezählt).

Dániel Szõke (11913915)
12.10.2019

*/

#include <iostream>
#include <cmath>
#include <assert.h> 

using namespace std;

int countDigit(long long m, const int n)
{
	assert(n > 0);				// n must be positive
	assert(m>=pow(10,n-1));		//check whether m>=10^(n-1)

	int count = 0, digit = -1;
	while ((m != 0) && (count!=n) ) {
		digit = m - (m / 10) * 10;	//Z.B:  7 = 187-(187/10)*10 = 187-(18)*10=187-180 
		m = m / 10;					//Z.B: 18 = 187/10
		++count;
	}
	return digit;
}

int main()
{
	cout << "------------Test------------" << endl;
	cout << "m=8, n=1:        " << countDigit(8,1) <<endl;
	cout << "m=1358, n=2:     " << countDigit(1358, 2) << endl;
	cout << "m=11913915, n=6: " << countDigit(11913915, 6) << endl;
	cout << endl;
}
