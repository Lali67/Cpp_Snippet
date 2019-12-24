/*Schreiben Sie eine rekursive Funktion int anz_gerade(int wert), 
die die Anzahl der geraden Ziffern in der als Parameter übergebenen ganzen Zahl
(diese muss ungleich 0 sein) retourniert.
Verwenden Sie in der Funktion keine Schleifen. z.B.:
cout << anz_gerade(123) gibt 1 aus
cout << anz_gerade(278) gibt 2 aus*/

#include <iostream>
using namespace std;


//Die Funktion definieren
int anz_gerade(int a) {


}


int main() {

	int a;

	//Einlesen der ganzen Zahl 
	cout << "Geben Sie hier eine ganze Zahl ein: "; cin >> a;

	//Aufruf der Funktion und Ausgabewert ausschreiben
	cout << "Anzahl der geraden Ziffern in der eingelesenen Zahl: " << anz_gerade(a) << endl;
}
