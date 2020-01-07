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
	Auto x(80, 240, 6, 3, "Lambo");

}


