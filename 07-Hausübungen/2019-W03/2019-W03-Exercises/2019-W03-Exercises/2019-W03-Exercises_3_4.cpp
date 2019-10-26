/* 2019-W02-Exercise_3_4.cpp :

Exercise 3.4
Berechnen Sie die Fakultät von n (n!) mit Hilfe einer Schleife

Dániel Szöke (11913915)
24.10.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;




int main()
{
	unsigned int n;
	unsigned long long factorial = 1;

	cout << "This program...\n";
	cout << "Enter a positive integer (n>1): ";	cin >> n;
	//Check n value
	if (n < 1)
		throw("n must be a positive integer (n>1)");
	
	for (int i = 1; i <= n; ++i)
	{
		factorial *= i;
	}
	
	cout << "Factorial of " << n << " = " << factorial << endl;

	return 0;
}
