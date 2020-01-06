#ifndef UHR_H
#define UHR_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Uhr {
	int stunde;
	int minute;
	int sekunde;
	bool format_24;

	public:
		//Konstruktor definieren
		Uhr(int st, int min, int sec, bool format=true) :
			stunde(st), minute(min), sekunde(sec), format_24(format)
		{};

		void print() {
			cout << "Aktuelle Uhrzeit: " << stunde << " Stunden, " << minute << " Minuten, und " << sekunde 
				 << " Sekunden." << endl;
		};
		//Stunde einstellen
		//Minute einstellen
		//Sekunde einstellen

};

#endif
