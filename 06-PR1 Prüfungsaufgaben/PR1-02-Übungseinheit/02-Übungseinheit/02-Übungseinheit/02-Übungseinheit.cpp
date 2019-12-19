#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Die Variablen einlesen (E:Endguthaben, A:Anfangsbetrag, z:Zinssatz)
	double A{ 0 }, z{ 0 }, E{ 0 };

	cout << "Geben Sie bitte den Anfangsbetrag (>0) ein: "; cin >> A;
	cout << "Geben Sie bitte den Zinssatz (0-100) ein: "; cin >> z;
	cout << "Geben Sie bitte das Endguthaben (>0, >=Anfangsbetrag) ein: "; cin >> E;

	//Anzahl Jahren (n) berechnen (Der Aufruf log(x) liefert ln𝑥)
	double n = (log(E)-log(A))/log(1+z/100);

	//Wert ausschreiben
	cout << n << " Jahren brauchen Sie, um den Anfangsbetrag zu erreichen." << endl;

	return 0;
}

