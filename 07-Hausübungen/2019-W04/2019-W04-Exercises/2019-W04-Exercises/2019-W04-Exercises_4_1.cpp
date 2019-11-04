/* 2019-W02-Exercise_4_1.cpp :

Exercise 4.1
  Schreiben Sie eine Funktion, die einen String und ein Zeichen als Parameter erhält und 
  den String retourniert, der entsteht, wenn das Zeichen aus dem String entfernt wird 
  (man muss das Zeichen nicht explizit aus dem String löschen. 
  Es ist vielleicht einfacher, einen neuen String als Kopie des Eingangsstrings - Zeichen für Zeichen - 
  anzulegen und beim Kopieren das zu "löschende" Zeichen einfach zu ignorieren). 
  
  Schreiben Sie zum Testen ein Hauptprogramm, das zunächst einen String einliest und 
  dann immer wieder ein einzelnes Zeichen und das Ergebnis ausgibt,
  wenn das zuletzt eingegebene Zeichen aus dem String entfernt wird. 
  Das Programm soll durch Eingabe von EOF beendet werden, 
  
  z.B.:
	Eingabe: KrankeSchwestern
	Eingabe: K
	Ausgabe: rankeSchwestern
	Eingabe: e
	Ausgabe: KrankSchwstrn
	Eingabe: Ctrl-D
	Programmende

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;

string copyStringExcept(string aString, char deletedChar) {
	string result; int counter{0};

	while (counter < aString.length()) {
		if (aString[counter] != deletedChar) result += aString[counter];
		counter++;
	}

	return result;
}

int main()
{
	char deletedChar{ '_' }; string aString;

	cout << "Geben Sie hier einen String ein: ";  cin >> aString;

	//On a Unix - based machine, signal EOF by typing Ctrl + D and Enter.
	//On a Windows machine, signal EOF by typing Ctrl + Z and Enter.
	while (cin>>deletedChar) {
		cout << "Zurueckgebliebener String: " << copyStringExcept(aString, deletedChar) << endl;
	}
}
