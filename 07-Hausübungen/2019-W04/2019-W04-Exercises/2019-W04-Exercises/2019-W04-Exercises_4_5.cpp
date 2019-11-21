/* 2019-W02-Exercise_4_5.cpp :

Exercise 4.5
  Schreiben Sei eine Funktion, die einen String als Parameter erhält und als Ergebnis den reversierten Eingangsstring 
  (also von hinten nach vorne gelesen) retourniert.

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
#include <string>
//#include <vector>
//#include <cmath>
//#include <exception> 

using namespace std;


string getReverse(string str)
{
	string result;
	for (int i = str.length() - 1; i >= 0; i--) {
		result.push_back(str[i]);
	}
	return result;
}



int main()
{
	string aString;

	cout << "This program...\n";
	cout << "-------- Test --------\n";
	cout << "Test 1         : " << getReverse("Test 1         ") << endl;
	cout << "Zar 2          : " << getReverse("Zar 2          ") << endl;
	cout << "DanielSzoke 3  : " << getReverse("DanielSzoke 3  ") << endl;
	cout << endl;
	cout << "Get string     : ";
	
	while (cin >> aString) {
		cout << " " << getReverse(aString) << endl;
		cout << "Get string      : ";
	}

	return 0;
	
}
