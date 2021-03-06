/*Definieren Sie eine Struktur zur Darstellung von Punkten im R3(drei double Werte für die x-, y-und z-Komponente). 
Definieren Sie eine Funktion, die einen Vektor von Punkten als Parameter, sowie einen weiteren Punkt P 
als Parameter erhält und jenen Punkt aus dem Vektor retourniert, der am weitesten von P entfernt ist
(sollte es mehrere Punkte im Vektor gegeben,die alle den maximalen Abstand haben,so ist ein beliebiger dieser Punkte
zu retournieren).Ist der Vektor leer,so gibt es kein Maximum und somit ist folgerichtig eine Exception vom Typ 
runtime_error zu werfen.
Hinweis: Für die Berechnung des Abstandes zweier Punkte wird die euklidische Distanz verwendet.

Zusatzaufgabe (etwa 15 bis 30 Minuten extra):Die Funktion soll so abgeändert werden, dass ein double Wert
als dritter Parameter übergeben wird. Retourniert werden soll ein Vektor mit allen Punkten aus dem Eingangsvektor,
die vom Eingangspunkt nicht weiter entfernt sind, als der double Wert.Die geänderte Funktion soll keine Exception werfen,
sondern gegebenenfalls einen leeren Vektor retournieren.
*/

#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
//#include <algorithm>
using namespace std;

//Die Struktur definieren
struct Punkt {
	double x, y, z;
	void print() {
		cout << "Die Koordinaten des am weitesten entferntes Punktes: "<< x << ", " << y << ", " << z << endl;
	}
};

//Die Funktion definieren
Punkt max_entfernung(vector<Punkt> punkte, Punkt p) {
	Punkt max_entfernung_punkt{ 0, 0, 0 };
	double distanz{ 0 };

	if (punkte.empty())
		throw("runtime_error: Der Vektor ist leer!");

	for (Punkt p1 : punkte) {
		double distanz2 = sqrt(pow(p1.x - p.x, 2) + pow(p1.y - p.y, 2) + pow(p1.z - p.z, 2));
		if (distanz2 > distanz) {
			distanz = distanz2;
			max_entfernung_punkt.x = p1.x;
			max_entfernung_punkt.y = p1.y;
			max_entfernung_punkt.z = p1.z;
		}
	}

	return max_entfernung_punkt;
}

int main() {
	Punkt p;

	//Die Koordinaten von P einlesen
	cout << "Geben Sie hier die x, y, z Koordinaten von P ein: "; cin >> p.x >> p.y >> p.z;

	//Weitere Punkte einlesen und in einem Vektor zyklisch speichern
	vector<Punkt> punkte; 
	Punkt p1;
	char weiter{ 'j' };

	while (weiter == 'j') {
		cout << "Geben Sie hier die x, y, z Koordinaten vom naechsten Punkt ein: "; cin >> p1.x >> p1.y >> p1.z;
		punkte.push_back(p1);
		cout << "Wollen Sie weitere Punkte einlesen? (j/n): "; cin >> weiter;
	}
	
	//Berechnung der grössten Entfernung mit Funktionaufruf
	max_entfernung(punkte, p).print();

}