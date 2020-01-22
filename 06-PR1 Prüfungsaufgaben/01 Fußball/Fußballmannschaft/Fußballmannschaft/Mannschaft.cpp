#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "Mannschaft.h"
using namespace std;

vector<Spieler> Mannschaft::engagieren(const vector<Spieler>& sp) {
	vector<Spieler> temp;
	for (Spieler v1 : sp) {
		bool gefunden = false;
		Spieler gefunden_sp("noname", 10);
		for (Spieler v2 : spielerliste) {
			if (v1 == v2) {
				gefunden = true;
				gefunden_sp = v2;
			}
		}
		if (gefunden)
			temp.push_back(gefunden_sp);
		else
			spielerliste.push_back(v1);
	}

	return temp;
};

ostream& operator << (ostream& out, const Mannschaft& sp) {
	
	return out;
};