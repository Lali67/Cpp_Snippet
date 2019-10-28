/* 2019-W02-Exercise_3_11.cpp :

Exercise 3.11
	Schreiben Sie ein Programm, das eine natürliche Zahl einliest und die größte Zweierpotenz ausgibt, 
	die die eingelesene Zahl teilt.
	Eingabe       Ausgabe
	17              1
	48              16
	1024            1024

Dániel Szöke (11913915)
26.10.2019

*/

#include <iostream>

using namespace std;

unsigned long SimpleCalculator2(unsigned long n) {
	unsigned long result{ 0 }, temp{ n }, exp2{1};
	while (temp != 0) {
		temp = temp / 2;
		exp2 *= 2;
	}
	
	if (n % (exp2 / 2) == 0)
		result = exp2 / 2;
	else
		result = n % (exp2 / 2);
	
	return result;
}

int main()
{
	
	
	cout << "------------Test------------" << endl;
	cout << "17    :  " << SimpleCalculator2(17) << endl;
	cout << "48    :  " << SimpleCalculator2(48) << endl;
	cout << "1024  :  " << SimpleCalculator2(1024) << endl;
	cout << "99999 :  " << SimpleCalculator2(99999) << endl;
	cout << endl;
	
	// Get from the data from user to function
	unsigned long n;
	cout << "This program...\n";
	cout << "Bitte geben Sie hier ein ...: "; cin >> n;
	cout << "Resultat: " << SimpleCalculator2(n) << endl;
	
	return 0;
}
