/* 2019-W02-Exercise_4_4.cpp :

Exercise 4.4
  Schreiben Sie eine Funktion, die einen String (nur Kleinbuchstaben) als Parameter erh�lt und 
  einen String retourniert, in der das erste Zeichen der Eingangszeichenkette alphabetisch korrekt einsortiert ist. 
  Das hei�t im Ergebnis sollen zun�chst alle Zeichen, die kleiner als das urspr�nglich erste Zeichen sind, 
  dann dieses erste Zeichen und schlie�lich die Zeichen, die gr��er als (oder gleich wie) 
  das urspr�nglich erste Zeichen sind, auftreten, 
	z.B.:
		Eingangsstring: keinblasserschimmer
		retournierter String (auch andere L�sungen sind m�glich): eibaechieknlssrsmmr

D�niel Sz�ke (11913915)
29.10.2019

*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

void divideStringByFirstChar(string aString) {
	string leftString{ "" }, rightString{ "" };
	
	rightString.push_back(aString[0]);
	for (int i = 1; i < aString.length(); i++) {
		if(aString[0]< aString[i]) rightString.push_back(aString[i]);
		else
			leftString.push_back(aString[i]);
	}
	
	cout << leftString << rightString << endl;

	return;
}


int main()
{
	cout << "This program...\n";

	cout << "-------- Test --------\n";
	cout << "keinblasserschimmer: "; 
	divideStringByFirstChar("keinblasserschimmer");
	cout << "donaudampfschiffahrtselektrizitaetenhauptbetriebswerkbauunterbeamtengesellschaft: ";
	divideStringByFirstChar("donaudampfschiffahrtselektrizitaetenhauptbetriebswerkbauunterbeamtengesellschaft");
	cout << "rindfleischetikettierungsueberwachungsaufgabenuebertragungsgesetz: ";
	divideStringByFirstChar("betaeubungsmittelverschreibungsverordnung");
	cout << endl;
	
	string aString;
	cout << "Get string      : "; cin >> aString;
	divideStringByFirstChar(aString);

	return 0;
	
}
