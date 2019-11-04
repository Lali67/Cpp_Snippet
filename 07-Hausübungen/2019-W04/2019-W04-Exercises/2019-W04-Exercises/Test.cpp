#include <iostream>
#include <cmath>
using namespace std;

double A, E, z;

int main() {
	
		cout << "Dieses Program gibt aus, wie viel man auf das gewuenschte Endguthaben warten muss." << endl;
	
		cout << "Geben Sie hier den Anfangsbetrag ein: "; cin >> A;
		cout << "Geben Sie hier das gewuenschte Endguthaben ein: "; cin >> E;
		cout << "Geben Sie hier den Zinssatz (0 <= z <= 100) ein: "; cin >> z;
	
		cout << "Die eingelesenen Werte: " << endl;
		cout << "Anfangsbetrag: "; cout << A << endl;
		cout << "Endguthaben: "; cout << E << endl;
		cout << "Zinssatz: "; cout << z << endl;
	
	double a, b;

	a = log(E) - log(A);
	b = log(1 + z / 100);

		cout << "Wartungszeit, bevor Sie das Endguthaben aufnehmen koennen: " << a / b << " Jahren" << endl;
		

	return 0;
}