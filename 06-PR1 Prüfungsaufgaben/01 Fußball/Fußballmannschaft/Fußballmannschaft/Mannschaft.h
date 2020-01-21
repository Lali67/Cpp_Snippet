#ifndef MANNSCHAFT_H
#define MANNSCHAFT_H

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "Spieler.h"
using namespace std;

class Mannschaft {
	string name;
	vector<Spieler> spielerliste;

	public:
		Mannschaft(string tname) :name(tname) {
			if (tname.size() == 0)
				throw("runtime_error: Falsche Name");
		};
		Mannschaft(string tname, vector<Spieler> tspielerliste) :name(tname) {
			if (tname.size() == 0)
				throw("runtime_error: Falsche Name");
			if (tspielerliste.empty())
				throw("runtime_error:Falsche Liste");
			//Lista átmásolás!
		};
		vector<Spieler> engagieren(const vector<Spieler>&);
		friend ostream& operator << (ostream& out, const Mannschaft& sp);
};



#endif

