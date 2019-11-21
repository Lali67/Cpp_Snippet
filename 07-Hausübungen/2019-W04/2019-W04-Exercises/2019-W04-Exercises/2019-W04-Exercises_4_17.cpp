/* 2019-W02-Exercise_4_16.cpp :

Exercise 4.17
  Schreiben Sie eine Funktion, die einen String und ein Zeichen als Parameter erhält. 
  Zu retournieren ist die Position, an der das Zeichen zum ersten Mal im String auftritt als int Wert. 
  Der String darf Teile in doppelten Hochkommatas enthalten, die bei der Suche nach dem Zeichen 
  zu ignorieren sind. Überlegen Sie sich Sonderfälle und wie Ihre Funktion darauf reagieren sollte.
  Zum Beispiel:

	Parameter: "Er sagte:\"ich habe keine Ahnung.\" und haute ab"  'h'
	Returnwert: 38

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

// Calculate sum of "large" numbers 
int getPosCharInString(string aString, char ch)
{
	bool QouteString{ false };

	for (unsigned i = 0; i < aString.length(); i++) {
		if (aString[i] == '\"') {
			if (QouteString) QouteString = false;
			else QouteString = true;
		}
		else{
			if (!QouteString && (ch == aString[i])) return i;
		}
	}
	
	return -1;
}

int main()
{
	string aString; char ch;

	cout << "This program...\n";
	cout << "-------- Test --------\n";
	cout << "Er sagte:\"ich habe keine Ahnung.\" und haute ab ->'h' : "
		<< getPosCharInString("Er sagte:\"ich habe keine Ahnung.\" und haute ab", 'h') << endl; 
	cout << "Er sagte: ich habe keine Ahnung.\" und haute ab ->'h' : "
		<< getPosCharInString("Er sagte: ich habe keine Ahnung.\" und haute ab", 'h') << endl;
	cout << "Er sagte:\"ich habe keine Ahnung. und haute ab ->'h' : "
		<< getPosCharInString("Er sagte:\"ich habe keine Ahnung. und haute ab", 'h') << endl;
	cout << endl;

	cout << "Get string     : "; cin >> aString;
	cout << "Get character  : "; cin >> ch;
	cout << "Character positon where it acts as Int: " 
		<< getPosCharInString(aString, ch) << endl << endl;
	
	return 0;
	
}
