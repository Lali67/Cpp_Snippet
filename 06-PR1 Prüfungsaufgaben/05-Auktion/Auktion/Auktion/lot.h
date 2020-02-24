#ifndef LOT_H
#define LOT_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

enum class Kategorie { Schmuck, Moebel, Kunst, Sonstiges };

extern vector <string> kategorie_namen;

class Lot {
private:
	string bezeichnung;
	int min_erl�s;
	Kategorie cat;
	vector<Gebot> gebote;
public:
	Lot(string tbezeichnung, int min_terl�s, Kategorie tcat = Kategorie::Sonstiges) : 
		bezeichnung(tbezeichnung), min_erl�s(min_terl�s), cat(tcat) 
	{
		if (bezeichnung.size() == 0 || min_erl�s <= 0 || min_erl�s > 10000000)
			throw runtime_error("runtime error");
	}
	
	bool ist_offen() const;
	bool bieten(const Gebot& gf);
	friend ostream& operator << (ostream& out, const Lot& lt);

};

#endif 
