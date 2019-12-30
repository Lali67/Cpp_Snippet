/*Schreiben Sie eine Funktion string del(string str1, string str2, ???), 
die zwei Zeichenketten als Parameter erh�lt und eine Zeichenkette retourniert.
Im Ergebnis sollen alle Zeichen, die im zweiten Parameter auftreten, 
aus dem ersten gel�scht werden. Weiters soll die Funktion die Anzahl 
der gel�schten Zeichen in einem zus�tzlichen Referenzparameter 
(dessen Definition an Stelle der drei Fragezeichen einzuf�gen ist) zur�ckliefern.
Parameter 1:     Parameter 2:       Ergebnis:
DiesisteinTest	 en					DisistiTst   4  //4 wird im Referenzparameter zur�ck geliefert

Zusatzaufgabe (etwa 15 bis 30 Minuten extra):Die Funktion soll so erweitert werden, 
dass am Ende des retournierten Strings die gel�schten Zeichen angeh�ngt werden.

Ergebnis f�r obiges Beispiel:
DisistiTsteene     4
*/

#include <iostream>
#include <string>
//#include <algorithm>
using namespace std;

//Die Funktion definieren
string del(string str1, string str2, int& i) {
	
	//Schleife: chars von str1
	int counter{ 0 };
	while (counter < str2.size()) {

		//char suchen in str1
		size_t found = str1.find(str2.at(counter));
		
		//wenn found, dann die entsprechende Position in found speichern
		while (found != str1.npos) {
			str1.erase(found, 1);
			//char suchen in str1
			found = str1.find(str2.at(counter));
			++i;
			cout << i << endl;
		}
		counter++;
	}
	return str1;
}

int main()
{
	string str1, str2;
	int i = 0;

	//Strings einlesen
	cout << "Geben Sie hier den ersten  String ein: "; cin >> str1;
	cout << "Geben Sie hier den zweiten String ein: "; cin >> str2;
	string hihi = del(str1, str2, i);
	//Aufruf der Funktion und Ausgabewert ausschreiben
	cout << "Der veraenderte String: " << hihi << " " << i << endl;

}