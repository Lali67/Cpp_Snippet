/* 2019-W02-Exercise_4_11.cpp :

Exercise 4.11
  Schreiben Sie eine Funktion, die einen String als Parameter erhält und einen "vermixten" String retourniert.
  Dabei sollen im Ergebnis zunächst alle Zeichen mit ungeradem Index im Parameter 
  in der ursprünglichen Reihenfolge enthalten sein und daran anschließend alle Zeichen 
  mit geradem Index im Parameter in umgekehrter Reihenfolge, 
  z.B.:
	Parameter: "abcdefghi"
	Returnwert: "bdfhigeca"

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;

string copyStringRemix(string aString) {
	string result_even{""}, result_odd{ "" }; 
	int counter{ 0 };

	while (counter < aString.length()) {
		//evaluation from right to left direction
		if (counter % 2 == 0) 
			result_even = aString[counter] + result_even;
		else 
			result_odd += aString[counter];
		counter++;
	}
	
	//evaluation from right to left direction
	return result_odd + result_even;
}

int main()
{
	string aString;

	cout << "This program...\n";
	cout << "Get a string: ";  cin >> aString;
	
	cout << "Remixed string: " << copyStringRemix( aString) << endl;
}
