/*Definieren Sie eine Struktur, die zwei Strings enthalten kann (geordnetes Paar von Strings).
Schreiben Sie eine Funktion, die einen Vektor von Stringpaaren als Parameter erhält, und einen Vektor 
von Stringpaaren retourniert.Im Retourwert sollen alle Stringpaare in umgekehrter Ordnung enthalten sein, 
bei denen im Eingangsvektor der erste String kürzer ist, als der zweite (ist z.B. im Eingangsvektor 
das Paar("A", "ABC") enthalten, so muss im Ergebnis ("ABC", "A") enthalten sein).

Zusatzaufgabe (etwa 15 bis 30 Minuten extra) :Die Funktion soll so abgeändert werden, dass nur jenes 
Stringpaar retourniert wird, für das die Länge des ersten Strings minimal ist und der Wert 
des zweiten Strings(bei lexikalischer Ordnung) maximal(von allen Paaren, bei denen der erste String 
minimale Länge hat, wird jenes gewählt, dessen zweiter String bei alphabetischer Anordnung der letzte ist).
Ist der Eingangsvektor leer, so ist eine Exception vom Typ runtime_error zu werfen.*/

#include <iostream>
#include <vector>
#include <string>
//#include <cmath>
//#include <algorithm>
using namespace std;

struct StringPaar {
	string x, y;
	void print() {
		cout << "Erster String: " << x << " Zweiter String: " << y << endl;
	};
};

vector<StringPaar> wechseln(vector<StringPaar> strings) {
	string temp;
	vector<StringPaar> ergebnis;

	for (StringPaar v : strings) {
		if (v.x.size() < v.y.size()) {
			temp = v.x;
			v.x = v.y;
			v.y = temp;
		}
		ergebnis.push_back(v);
	}
	
	return ergebnis;
}


int main() {
	StringPaar S;
	char weiter{ 'j' };
	vector<StringPaar> strings;

	while (weiter == 'j') {
		cout << "Geben Sie hier den ersten  String ein: "; cin >> S.x;
		cout << "Geben Sie hier den zweiten String ein: "; cin >> S.y;
		cout << "Wollen Sie noch weitere Stringpaaren einlesen (j/n)?: "; cin >> weiter;
		
		strings.push_back(S);
	}
	 
	strings = wechseln(strings);
	
	for (StringPaar v : strings) {
		v.print();
	}

}