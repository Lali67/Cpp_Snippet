/*Schreiben Sie eine Funktion void repl(string& str1,string str2,string str3,???),
die drei Zeichenketten als Parameter erhält(beachten Sie, dass der erste Parameter eine Referenz ist)
und void retourniert. Alle Zeichen des ersten Strings,die im zweiten String vorkommen,
sollen durch das Zeichen im dritten String ersetzt werden, das an derselben Position wie 
das zu ersetzende Zeichen im zweiten String steht. Weiters soll die Funktion die Anzahl
der ersetzten Zeichen in einem zusätzlichen Referenzparameter(dessen Definition an Stelle der drei Fragezeichen 
einzufügen ist) zurückliefern. Werfen Sie einen Fehler vom Typ runtime_error, wenn str3 kürzer als str2 ist.
Parameter1: halloWelt
Parameter2: lae
Parameter3: ebr
Ergebnis: hbeeoWret 5 // hbeeoWret steht in der Referenz zu str1,5 wird im Referenzparameter zurückgeliefert
Hinweis: Verwendung von globalen Variablen und goto ist
		(soweit sie nicht in der Angabe explizit empfohlen wird) untersagt.
*/

#include <iostream>
#include <string>
#include <exception>
using namespace std;

//Die Funktion definieren
void repl(string& str1, string str2, string str3, int& i) {
	
	//Den zweiten und den dritten String vergleichen
	if (str3.size() < str2.size())
		throw("runtime_error: Der dritte String kann nicht kuerzer sein als der zweite! ");
	
	//Schleife: chars von str1
	int counter{ 0 };
	while (counter < str1.size()) {
		
		//char suchen in str2
		size_t found = str2.find(str1.at(counter));
		
		//wenn found, dann die entsprechende Position in found speichern
		if (found != str2.npos) {
			//replace mit dem char von str1
			str1.at(counter) = str3.at(found);
			//in i speichern wir die Anzahl von founds
			++i;
		}
		counter++;
	}
}

int main()
{
	string str1, str2, str3;
	int i{ 0 };

	//Strings einlesen
	cout << "Geben Sie hier den ersten  String ein: "; cin >> str1;
	cout << "Geben Sie hier den zweiten String ein: "; cin >> str2;
	cout << "Geben Sie hier den dritten String ein: "; cin >> str3;

	//Aufruf der Funktion und Ausgabewert ausschreiben
	repl(str1, str2, str3, i);

	cout << "Der veraenderte String: " << str1 << " " << i << endl;

}
