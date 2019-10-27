/* 2019-W02-Exercise_3_15.cpp :

Exercise 3.15 
(*) Wie Beispiel 2, allerdings für beliebige reelle Zahlen. Z.B.:  
	Eingabe 17.23
	Ausgabe: eins-sieben-komma-zwei-drei.
Dániel Szöke (11913915)
24.10.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;

inline bool IsEnabledChar(string aString, char c) {
	return std::string(aString).find(c) != std::string::npos;
}

string toWords(string realString)
{
	const string EnabledFirstCharList = "+-.0123456789";
	const string EnabledOtherCharList = ".0123456789";
	const string digitWord[] = { "plus", "minus", "komma", "null", "eins", "zwei", "drei", "vier", "fuenf",
									"sechs", "sieben", "acht", "neun" };

	string digitsToWords{""};
	int digit{0};

	if (!IsEnabledChar(EnabledFirstCharList, realString[0]))
		throw("The number must be a regular real number");
	else
		digitsToWords = digitWord[string(EnabledFirstCharList).find(realString[0])] + "-";
	
	for (int i = 1; i < realString.length(); i++) {
		if (!IsEnabledChar(EnabledOtherCharList, realString[i]))
			throw("The number must be a regular real number");
		else {		
			if (i != realString.length() - 1)
				digitsToWords = digitsToWords + 
									digitWord[string(EnabledFirstCharList).find(realString[i])] + "-";
			else
			// do not add - sign behind last word
				digitsToWords = digitsToWords +
									digitWord[string(EnabledFirstCharList).find(realString[i])];
		}
	}
	
	return digitsToWords;
}


int main()
{
	cout << "------------Test------------" << endl;
	cout << "a=-1940.2     :  " << toWords("-1940.2") << endl;
	cout << "a=+7061       :  " << toWords("+7061") << endl;
	cout << "a=.0123       :  " << toWords(".0123") << endl;
	cout << endl;

	// Get from the data from user to function
	string realString;
	cout << "This program...\n";
	cout << "Bitte geben Sie hier reelle Zahlen ein: "; cin >> realString;
	cout << "Resultat: " << toWords(realString) << endl;
}
