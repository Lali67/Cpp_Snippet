/* 2019-W02-Exercise_4_8.cpp :


Exercise 4.8
  Schreiben Sie die Funktionen int mult(int m, int n) und int power(int m, unsigned int n), 
  die das Produkt m*n bzw. die Exponentialfunktion mn der ganzen Zahlen m und n berechnen. 
  Verwenden Sie dazu nicht den Operator * (Multiplikation). 
  Auch das Verwenden irgendwelcher externer Routinen (z.B. Mathematikbibliotheken) ist nicht erlaubt! 
  Beachten Sie, dass int-Werte auch negativ oder gleich 0 sein können.
  Hinweis: m*n = m+m*(n-1) für n>0

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
//#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

int multi(int m, int n)
{
	//0 multiplied with anything gives 0
	if (n == 0)
		return 0;

	//Add m one by one
	if (n > 0)
		return (m + multi(m, n - 1));

	/* the case where y is negative */
	if (n < 0)
		return -multi(m, -n);
}

int power(int m, unsigned int n)
{
	if (n)
		return multi(m, power(m, n - 1));
	else
		return 1;
}


int main()
{
	string aString;

	cout << "This program...\n";
	cout << "-------- Test --------\n";
	cout << "multi(m=8, n=6)        : " << multi( 8, 6) << endl;
	cout << "multi(m=105, n=30)     : " << multi(105, 30) << endl;
	cout << "power(m=2 b=8)         : " << power(2, 8) << endl;
	cout << endl;
	
	return 0;
	
}
