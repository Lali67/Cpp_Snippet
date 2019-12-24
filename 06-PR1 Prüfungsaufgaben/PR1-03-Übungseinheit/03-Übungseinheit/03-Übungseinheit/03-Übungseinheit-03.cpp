//Schreiben Sie ein Programm, das eine ganze Zahl einliest und 
//eine Aggregatfunktion der Ziffern der Zahl bestimmt, 
//die folgendermassen definiert ist : 
//Die Ziffern der Zahl werden von rechts nach links durchlaufen.
//Gerade Ziffern werden zum Ergebnis addiert.
//Ungerade Ziffern werden zum Ergebnis multipliziert.
//Der Startwert ist 0 oder 1, je nachdem, 
//ob die erste Ziffer gerade(0) oder ungerade(1) ist.
//Die Berechnung soll beliebig oft wiederholbar sein, 
//ohne das Programm neuerlich zu starten.
//Eingabe 7236143 Ergebnis 287

#include <iostream>
//#include <cmath>
using namespace std;

int main() 
{
	//Int definieren und einlesen (int=eingegebene Zahl)
	long a;

	cout << "Dieses Programm berechnet eine vordefinierte Aggregatfunktion der eingegebenen Zahl. " << endl;
	cout << "Geben Sie hier eine ganze Zahl ein: "; 

	//Schleife, "a" cyklisch einlesen
	while (cin >> a) {
		int ergebnis{ 0 };
		if ((a % 10) % 2 == 1) ergebnis = 1;

		//Schleife, Trennen der letzten Ziffer bis 0 erreicht
		while (a != 0) {

			//Überprüfen der Ziffern mit %10
			int rest = a % 10;
			a = a / 10;

			//Kondition: wenn Ziffer gerade, Ziffer+Ergebnis
								//ansonsten: Ziffer mal Ergebnis
			if (rest % 2 == 0) 
				ergebnis = ergebnis + rest;
			
			else 
				ergebnis = ergebnis * rest;
		}
		//Ergebnis ausschreiben
		cout << ergebnis << endl;
		cout << endl << "Geben Sie hier eine ganze Zahl ein: ";
	}
}