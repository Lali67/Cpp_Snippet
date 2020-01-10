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
		Uhr(const Uhr& u) :
			stunde(u.stunde), minute(u.minute), sekunde(u.sekunde), format_24(u.format_24)
		{};

		bool operator > (Uhr p) {
			
			return 60*60*stunde+60*minute+sekunde > 60 * 60 * p.stunde + 60 * p.minute + p.sekunde;
		}
		bool operator < (Uhr p) {

			return 60 * 60 * stunde + 60 * minute + sekunde < 60 * 60 * p.stunde + 60 * p.minute + p.sekunde;
		}

		Uhr operator + (int q) {
			Uhr temp(stunde, minute, sekunde);
			temp.sec_plus(q);

			return temp;
		}

		void print() {
			int t_stunde = stunde % 12;
			if (format_24) t_stunde = stunde;
			cout << "Aktuelle Uhrzeit: " << t_stunde << " Stunden, " << minute << " Minuten, und " << sekunde 
				 << " Sekunden." << endl;
		};
		//Stunde einstellen
		void set_stunde(int st) {
			if (st < 0 || st > 24)
				throw("Fehler! Falsche Uhrzeit!");
			stunde = st;
		}
		//Minute einstellen
		void set_minute(int min) {
			if (min < 0 || min > 59)
				throw("Fehler! Falsche Uhrzeit!");
			minute = min;
		}
		//Sekunde einstellen
		void set_sekunde(int sec) {
			if (sec < 0 || sec > 59)
				throw("Fehler! Falsche Uhrzeit!");
			sekunde = sec;
		}
		//Ganze aktuelle Uhrzeit einstellen
		void set_ganze(int st, int min, int sec) {
			set_stunde(st);
			set_minute(min);
			set_sekunde(sec);
		}
		void set_format12() {
			format_24 = false;
		}
		void set_format24() {
			format_24 = true;
		}
		//Eine Sekunde "addieren"
		void sec_plus(int num = 1) {
			int temp_sec = 60 * 60 * stunde + 60 * minute + sekunde + num;
			stunde		= temp_sec / (60 * 60);
			stunde		= stunde % 24; // if it is more than 24 hours
			temp_sec	= temp_sec % (60 * 60);

			minute		= temp_sec / 60;
			minute		= minute % 60; // if it is more than 60 mins
			temp_sec	= temp_sec %  60;

			sekunde		= temp_sec;
		}

};

#endif
