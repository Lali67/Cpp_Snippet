/* //Schreiben Sie eine rekursive Funktion string_replace(string in, char from, char to), 
die als Ergebnis eine Zeichenkette liefert, die aus der 
als Parameter übergebenen Zeichenkette 
durch Ersetzung des Zeichens „from“ durch das Zeichen „to“ entsteht. 
Verwenden Sie in der Funktion keine Schleifen. z.B.:
cout << replace("MOTOR",'O','E') //gibt METER aus 
Hinweis: Für die Manipulation von string Objekten ist 
nur die Verwendung der Methoden at und length(bzw. size) sowie des Operators +erlaubt.*/

#include <iostream>
using namespace std;

//Die Funktion definieren, mit einer Hilfsvariable int i
string replace(string& in, char from, char to, int i = 0) {
	
	if (i == in.size())
		return in;
	else
		if (in.at(i) == from) 
			in.at(i) = to;
		
	return replace(in, from ,to, ++i);
}

int main() {

	string in;
	char from, to;
	
	//Einlesen des Strings und der Chars
	cout << "Dieses Programm ersetzt die a chars durch b chars im eingegebenen String. " << endl;
	cout << "Geben Sie hier den String ein: ";			cin >> in;
	cout << "Geben Sie hier den ersten Char(a) ein: ";	cin >> from;
	cout << "Geben Sie hier den zweiten Char(b) ein: "; cin >> to;

	//Aufruf der Funktion und Ausgabewert ausschreiben
	cout << "Der veraenderte String: " << replace(in, from, to) << endl;
}