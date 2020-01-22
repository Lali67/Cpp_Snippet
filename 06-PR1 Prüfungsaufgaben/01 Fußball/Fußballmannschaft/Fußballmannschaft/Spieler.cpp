#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "Spieler.h"
using namespace std;

bool Spieler::operator==(const Spieler& sp) const {
	if (name.compare(sp.name) == 0)
		return true;
	else
		return false;
};

ostream& operator << (ostream& out, const Spieler& sp) {
	out << sp.name << ", " << sp.summe << " Mio Euro, ";
	switch (sp.pos)
	{
		case Position::Tor:
			out << "Tor" << endl;
			break;
		case Position::Abwehr:
			out << "Abwehr" << endl;
			break;
		case Position::Mitte:
			out << "Mitte" << endl;
			break;
		case Position::Sturm:
			out << "Sturm" << endl;
			break;
	}

	return out;
};