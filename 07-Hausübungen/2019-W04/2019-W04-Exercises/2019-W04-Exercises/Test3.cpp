#include <iostream>
using namespace std;

int a, b, c;
double d, e;

int main() {
	bool weiter{ true };
	char antwort{ 'n' };

	cout << "Dieses Programm berechnet das harmonische Mittel von drei Zahlen." << endl;
	while (weiter) {
		cout << "Geben Sie hier die erste Zahl ein: "; cin >> a;
		cout << "Geben Sie hier die zweite Zahl ein: "; cin >> b;
		cout << "Geben Sie hier die dritte Zahl ein: "; cin >> c;

		if (a == 0 || b == 0 || c == 0)
			cout << "Fehler: Division durch 0 ist nicht moeglich!" << endl;
		else
			d = (1.0 / a) + (1.0 / b) + (1.0 / c);
		e = 3 / d;

		// andere Loesung: d = (1 / double(a)) + (1 / double(b)) + (1 / double(c));

		cout << "Das harmonische Mittel der eingegebenen Zahlen ist: " << e << endl;
		cout << "Wollen Sie eine andere Berechnung durchfuehren? (j/n): "; cin >> antwort;
		if (antwort == 'n') weiter = false;
}
	return 0;
}