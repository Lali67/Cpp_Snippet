/*Schreiben Sie eine Klasse Uhr. 
Der Zustand einer Uhr wird durch die aktuellen Werte für Stunden, 
Minuten und Sekunden beschrieben. Schreiben Sie notwendige Konstruktoren, 
sowie Methoden, um die aktuelle Uhrzeit zu setzen, 
die Uhrzeit um eine Sekunde weiter zu setzen, 
sowie den aktuellen Zustand aufdem Bildschirm auszugeben 
(wahlweise im 12 oder 24 Stunden Format).
Testen Sie die Funktionalität Ihrer Klasse mit einem entsprechenden Hauptprogramm.
Zusatzaufgabe (etwa 15 bis 30 Minuten extra):Schreiben Sie eine globale Funktion, 
die alle notwendigen Werte einliest,um ein neues Uhren-Objekt zu erstellen 
und dieses neue Objekt an die aufrufende Funktion retourniert.
*/

#include <iostream>
#include "Uhr.h"

using namespace std;

int main()
{
	Uhr x(12,23,34);
	x.print();
}

