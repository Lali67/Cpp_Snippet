/* 2019-W02-Exercise_3_13.cpp :

Exercise 3.13
Eine natürliche Zahl heißt fast perfekt, wenn die Summe ihrer echten Teiler 
(das sind alle Teiler, die kleiner als die Zahl selbst sind) um eins kleiner ist, als die Zahl. 
Zum Beispiel ist 4 fast perfekt, da 4=1*2*2 und 1+2=3=4-1. 
Ermitteln Sie alle fast perfekten Zahlen im Bereich 0 bis 10^7.

Dániel Szöke (11913915)
26.10.2019

*/

#include <iostream>

using namespace std;

bool IsFastPerfectNumber(unsigned long n) {
	unsigned long divisor{ 1 }, sumDivisors{ 0 };
	bool result{ false };

	while (divisor < n ) {
		if (n % divisor == 0) sumDivisors += divisor;
		divisor++;
	}
	
	if (n-1 == sumDivisors) result = true;
	
	return result;
}

int main()
{
	unsigned long n{1};
	cout << "Dieses Programm ermittelt alle fast perfekten Zahlen im Bereich 0 bis 10^7.\n";
	while (n < 1e+7) {
		if (IsFastPerfectNumber(n)) cout << n << " ";
		n++;
	}
	cout << endl;

	return 0;
}
