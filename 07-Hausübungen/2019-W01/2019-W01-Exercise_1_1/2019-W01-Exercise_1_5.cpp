/* 2019-W01-Exercise_1_5.cpp: 

Exercise 1.5
Rechnen Sie von Celsius in Fahrenheit um.

Dániel Szõke (11913915)
12.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	double Celsius, Fahrenheit;
	cout << "Dieses Programm rechnet von Celsius in Fahrenheit um\n";
	cout << "Celsius (degrees): ";	cin >> Celsius;
	Fahrenheit = 1.8*Celsius+32;
	cout << "Fahrenheit (degrees): "<<Fahrenheit<<endl;

	return 0;
}

