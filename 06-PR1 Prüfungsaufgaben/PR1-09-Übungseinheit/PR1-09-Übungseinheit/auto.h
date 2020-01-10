#ifndef AUTO_H
#define AUTO_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <exception>

using namespace std;

class Auto {
	private:	
		double geschw_akt;
		double geschw_max;
		int nummer_gear;
		int gear_akt;
		string name;

	public:
		Auto(double tgeschw_akt, double tgeschw_max, int tnummer_gear, int tgear_akt, string tname) :
			geschw_akt(tgeschw_akt), geschw_max(tgeschw_max), nummer_gear(tnummer_gear), 
			gear_akt(tgear_akt), name(tname)
		{};
		bool operator < (Auto y) {
			if (geschw_max < y.geschw_max)
				return true;
			else
				return false;
		}
		bool operator > (Auto y) {
			if (geschw_max > y.geschw_max)
				return true;
			else
				return false;
		}
		Auto operator + (Auto y) {
			geschw_akt = y.geschw_akt + 5;
			
		}
		void print_data() {
			cout << "Aktuelle Geschwindigkeit: " << geschw_akt << endl;
			cout << "Maximale Geschwindigkeit: " << geschw_max << endl;
			cout << "Anzahl der Gaenge:        " << nummer_gear << endl;
			cout << "Aktueller Gang:           " << gear_akt << endl;
			cout << "Name des Autos:           " << name << endl;
		}
		void print_speed_gear() {
			cout << "Veraenderte  Geschwindigkeit: " << geschw_akt << endl;
			cout << "Veraenderter Gang:           " << gear_akt << endl;
		}
		void hochschalten() {
			gear_akt += 1;
			if (gear_akt > nummer_gear) {
				throw("Fehler! Der eingegebene Gang muss kleiner sein als" 
					  "der hoechste moegliche Gang, und groesser gleich sein als 0!");
			}
		}
		void zuruckschalten() {
			gear_akt -= 1;
			if (gear_akt < 0) {
				throw("Fehler! Der eingegebene Gang muss kleiner sein als"
					  "der hoechste moegliche Gang, und groesser gleich sein als 0!");
			}
		}
		void increase_speed(int num) {
			geschw_akt += abs(num);
			if (geschw_akt > geschw_max) {
				throw("Fehler! Die Geschwindigkeit muss groesser sein als 0"
					  "und kleiner sein als die hoechste moegliche Geschwindigkeit!");
			}
		}
		void decrease_speed(int num) {
			geschw_akt -= abs(num);
			if (geschw_akt < 0) {
				throw("Fehler! Die Geschwindigkeit muss groesser sein als 0"
					  "und kleiner sein als die hoechste moegliche Geschwindigkeit!");
			}
		}
};




#endif