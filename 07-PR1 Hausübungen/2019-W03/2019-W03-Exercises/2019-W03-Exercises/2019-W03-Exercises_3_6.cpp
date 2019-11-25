/* 2019-W02-Exercise_3_6.cpp :

Exercise 3.6
 Lesen Sie 2 Intervallgrenzen und danach beliebig viele Zahlen (Abschluss mit EOF) ein, 
 und geben Sie aus, wie viele Zahlen kleiner als die untere Intervallgrenze, 
 wie viele im Intervall und wie viele groesser als die obere Intervallgrenze waren.

Dániel Szöke (11913915)
24.10.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;


int main()
{
	double lower_limit{ 0.0 }, upper_limit{ 0.0 }, value{0.0};
	long below_range{ 0 }, in_range{ 0 }, over_range{ 0 };

	cout << "Dieses Programm gibt aus, wie viele Zahlen sich im Intervall befinden.\n";
	cout << "Geben Sie hier die untere Grenze, danach die obere Grenze ein: ";	cin >> lower_limit >> upper_limit;
	//Check limits
	cout << "Geben Sie die Nummern ein(s): \n";
	if (lower_limit > upper_limit)
		throw("Obere Grenze muss hoeher sein als die untere Grenze.");

	//On a Unix - based machine, signal EOF by typing Ctrl + D and Enter.
	//On a Windows machine, signal EOF by typing Ctrl + Z and Enter.
	while (cin >> value) {
		if (value > upper_limit) over_range++;
		else
			if (value < lower_limit) below_range++;
			else in_range++;
	}
	cout << endl;
	cout << "Kleiner als die untere Intervallgrenze : " << below_range << endl;
	cout << "im Intervall                           : " << in_range << endl;
	cout << "Groesser als die obere Intervallgrenze : " << over_range << endl;

	return 0;
}
