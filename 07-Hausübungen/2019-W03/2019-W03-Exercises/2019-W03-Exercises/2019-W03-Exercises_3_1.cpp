/* 2019-W02-Exercise_3_1.cpp :

Exercise 3.1
Sortieren Sie 3 eingelesene double Zahlen ohne Verwendung von logischen Operatoren.

Dániel Szöke (11913915)
24.10.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;


double max(double a, double b) 
{ 
	return (a + b + abs(a - b)) / 2; 
}

void printSorted_3Double(double a, double b, double c)
{
	// Find maximum from two elements 
	double get_max = max(a, max(b, c));

	// Find minimum from two elements 
	double get_min = -max(-a, max(-b, -c));

	double get_mid = (a + b + c)
		- (get_max + get_min);

	cout << "Sortiere elemente: " << get_min << " " << get_mid
		<< " " << get_max << endl;
}


int main()
{
	cout << "------------Test------------" << endl;
	cout << "a= 8.01, b= -1,  c= 0     :  "; printSorted_3Double(8.01, -1, 0);
	cout << "a= 0.99  b= 0.99 c= 8 0.1 :  "; printSorted_3Double(0.99, 0.998, 0.1);
	cout << endl;

	// Get from the data from user to function
	double a, b, c;
	cout << "Dieses Programm gibt die Sortieren 3 eingelesene double Zahlen ohne Verwendung von logischen Operatoren.\n";
	cout << "Bitte geben Sie hier a,b,c ein: "; cin >> a >> b >> c;
	printSorted_3Double(a, b, c);
}
