#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "Mannschaft.h"
using namespace std;

vector<Spieler> Mannschaft::engagieren(const vector<Spieler>& vecs) {
	vector<Spieler>temp;
	bool gefunden = false;

	for (Spieler v1 : vecs) {
		for (Spieler v2 : spielerliste) {
			if (v1 == v2)
				gefunden = true;
		}
		if (gefunden) 
			temp.push_back(v1);
		else 
			spielerliste.push_back(v1);
		gefunden = false;
		
	}

	return temp;
}

ostream& operator << (ostream& out, const Mannschaft& ms) {

	out << "[" << ms.mname << ", {";
	for (int i = 0; i < ms.spielerliste.size(); i++ ) 
	{
		out << ms.spielerliste.at(i) << ", ";
	}
	out << "}]";
	return out;
}