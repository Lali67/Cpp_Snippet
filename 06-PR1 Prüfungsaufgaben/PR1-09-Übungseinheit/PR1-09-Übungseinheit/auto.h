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
		void print_data() {
			
		}
		void hochschalten(int num_schal) {

		}
		void zurückschalten(int num_schal) {

		}
		void increase_speed(int num) {

		}
		void decrease_speed(int num) {

		}
};




#endif