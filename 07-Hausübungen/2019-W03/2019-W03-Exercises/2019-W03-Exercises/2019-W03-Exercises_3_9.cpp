/* 2019-W02-Exercise_3_9.cpp :

Exercise 3.9
Lesen Sie beliebig viele Zahlen (Abschluss mit EOF) ein, und geben Sie das Maximum, 
das Minimum und den Mittelwert der eingegebenen Werte aus.

Dániel Szöke (11913915)
26.10.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;


int main()
{
	double maximum{ 0.0 }, minimum{ 0.0 }, middle{ 0 }, value{ 0.0 };
	long counter{ 0 };

	cout << "This program...\n";
	cout << "Enter the number(s): \n";

	//On a Unix - based machine, signal EOF by typing Ctrl + D and Enter.
	//On a Windows machine, signal EOF by typing Ctrl + Z and Enter.
	while (cin >> value) {
		++counter;
		if (counter == 1) {
			maximum = value;
			minimum = value;
		}
		if (value > maximum) maximum = value;
		else
			if (value < minimum) minimum = value;
		middle += value;
	}
	
	if (counter == 0)
		throw("You should enter a number at least");
	else {
		middle = middle / counter;
		cout << endl;
		cout << "Maximum    : " << maximum << endl;
		cout << "Mittelwert : " << middle << endl;
		cout << "Minimum    : " << minimum << endl;
	}

	return 0;
}
