/*Schreiben Sie eine Funktion string del(string str1, string str2, ???), 
die zwei Zeichenketten als Parameter erhält und eine Zeichenkette retourniert.
Im Ergebnis sollen alle Zeichen, die im zweiten Parameter auftreten, 
aus dem ersten gelöscht werden. Weiters soll die Funktion die Anzahl 
der gelöschten Zeichen in einem zusätzlichen Referenzparameter 
(dessen Definition an Stelle der drei Fragezeichen einzufügen ist) zurückliefern.
Parameter 1:     Parameter 2:       Ergebnis:
DiesisteinTest	 en					DisistiTst   4  //4 wird im Referenzparameter zurück geliefert
*/

#include <iostream>
#include <string>
//#include <algorithm>
using namespace std;

//Die Funktion definieren
string del(string str1, string str2, int& i) {

	
}

int main()
{
	string str1, str2;
	int i{ 0 };

	//Strings einlesen
	cout << "Geben Sie hier den ersten  String ein: "; cin >> str1;
	cout << "Geben Sie hier den zweiten String ein: "; cin >> str2;
	
	//Aufruf der Funktion und Ausgabewert ausschreiben
	cout << "Der veraenderte String: " << del(str1, str2, i) << i << endl;

}