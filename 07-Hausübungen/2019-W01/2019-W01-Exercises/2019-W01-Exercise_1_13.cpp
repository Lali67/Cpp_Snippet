/* 2019-W01-Exercise_1_13.cpp: 


Exercise 1.13
Lesen Sie beliebig viele Werte ein (das Einlesen weiterer Werte soll durch Eingabe des Wertes 0 beendet werden. 
Geben Sie dann aus, wieviele der eingegebenen Zahlen gerade waren, 
wieviele ungerade und wieviele Zahlen insgesamt eingelesen wurden.


Dániel Szõke (11913915)
13.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int Num = 1;
	int Gerade = 0; int Ungerade = 0; int Counter = 0;

	cout << "Dieses Programm berechnet die Anzahl der geraden und ungeraden Zahlen,";
	cout <<	"sowie die Anzahl der eingelesenen Zahlen." << endl;
	cout << "Geben Sie beliebige Anzahl von Nummer,"; 
	cout << "danach schreiben Sie einen Null ein, um das Eingeben zu beenden." << endl;

	while (Num > 0) {
		cin >> Num;
		if (Num != 0) {
			if (Num % 2 == 0) Gerade++;
			else Ungerade++;
			Counter++;
		}
	}
	cout << "Anzahl der Nummer:       " << Counter << endl;
	cout << "Anzahl gerader Nummer:   " << Gerade << endl;
	cout << "Anzahl ungerader Nummer: " << Ungerade << endl;
	
	return 0;
}

