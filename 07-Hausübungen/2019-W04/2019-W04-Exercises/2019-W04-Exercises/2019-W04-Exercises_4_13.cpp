/* 2019-W02-Exercise_4_13.cpp :

Exercise 4.13
  Schreiben Sie zwei Funktionen zur Umwandlung von Zahlen vom Dezimal- ins Dualsystem und 
  umgekehrt. Eingangsparameter und Returnwerte sollen jeweils Strings sein, 
  die die Zahlendarsteilung der Werte in den entsprechenden Basen enthalten.

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

//function to convert decimal to binary 
string decimalToBinary(string n)
{
	long long number{ 0 }; int binaryNum{ 0 };
	string result;

	//convert n to number 
	for (int i = 0; i < n.length(); i++) {
		number = number * 10 + int(n[i]) - int('0');
	}
	//convert to binary 
	while (number > 0) {
		binaryNum = number % 2;
		number = number / 2;
		result = to_string(binaryNum) + result;
	}
	
	return result;
}

//function to convert decimal to binary 
string binaryToDecimal(string n)
{
	long long number{ 0 }, binaryNum{ 1 }; int decimalNum{ 0 };
	string result;

	//convert to decimal 
	for (int i = n.length()-1; i > -1; i--) {
		number += (int(n[i]) - int('0')) * binaryNum;
		binaryNum *= 2;
	}

	//convert to string 
	while (number > 0) {
		decimalNum = number % 10;
		number = number / 10;
		result = to_string(decimalNum) + result;
	}
	return result;
}

int main()
{
	string n;

	cout << "This program...\n";
	cout << "Get decimal value: ";  cin >> n;
	cout << "Convert decimal to binary: " << decimalToBinary(n) << endl << endl;

	cout << "Get binary value: ";  cin >> n;
	cout << "Convert binary to decimal: " << binaryToDecimal(n) << endl;
}
