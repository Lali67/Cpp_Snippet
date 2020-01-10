/* Schreiben Sie eine Klasse Auto. Der Zustand eines Autos wird 
durch aktuelle und maximale Geschwindigkeit, 
Anzahl der Gänge und aktuell gewählter Gang beschrieben.
Schreiben Sie notwendige Konstruktoren, sowie Methoden, 
um einen bestimmten Gang auswählen zu können, 
um jeweils einen Gang hoch-, bzw. zurückzuschalten, 
um die Geschwindigkeit zu erhöhen („gasgeben“) und 
zu vermindern („bremsen“) und den aktuellen Zustand auf dem Bildschirm auszugeben.
Testen Sie die Funktionalität Ihrer Klasse mit einem entsprechenden Hauptprogramm. 

Zusatzaufgabe (etwa 15 bis 30 Minuten extra): Schreiben Sie eine globale Funktion, 
die alle notwendigen Werte einliest,um ein neues Auto-Objekt zu erstellen 
und dieses neue Objekt an die aufrufende Funktion retourniert.
*/

#include <iostream>
#include "auto.h"
using namespace std;

int main()
{
	char setting{ 'j' };
	double speed{ 0 };
	int gear{ 0 };
	Auto x(0, 240, 6, 0, "Lambo");
	Auto y(7, 180, 5, 0, "Ferrari");
	Auto z(0, 290, 7, 0, "Maserati");
	bool slower = x < y;
	bool faster = x > y;

	cout << slower << endl;
	cout << faster << endl;
	x.print_data();
	y.print_data();
	z.print_data();
	
	while (setting == 'j') {
		cout << "Wollen Sie die Geschwindigkeit/den Gear aendern? (j/n): "; cin >> setting;
		if (setting == 'j') {
			cout << "Geben Sie hier die Hoehe der Aenderung der Geschwindigkeit ein "
				    "(wenn hoeher als 0: gasgeben, wenn kleiner: bremsen): "; cin >> speed;
			cout << "Geben Sie hier die Hoehe der Aenderung des aktuellen Ganges ein "
				    "(wenn hoeher als 0: gasgeben, wenn kleiner: bremsen): "; cin >> gear;
			if (speed > 0)  x.increase_speed(speed);
			if (speed < 0)  x.decrease_speed(speed);
			if (gear > 0)   x.hochschalten();
			if (gear < 0)   x.zuruckschalten();

			x.print_speed_gear();
		}
	}

}


