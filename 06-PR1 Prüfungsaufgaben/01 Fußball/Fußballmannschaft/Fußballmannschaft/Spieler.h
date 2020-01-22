#ifndef SPIELER_H
#define SPIELER_H

#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;

enum class Position {Tor, Abwehr, Mitte, Sturm};

class Spieler {
	string name;
	int summe;
	Position pos;

	public:
		Spieler(string tname, int tsumme, Position tpos = Position::Tor): name(tname), summe(tsumme)
		{
			if (tname.size() == 0)
				throw("runtime_error: Falsche Name");
			if (tsumme < 10 || tsumme > 500)
				throw("runtime_error: Falsche Summe");
			pos = tpos;
		};
		bool operator==(const Spieler& sp) const;
		friend ostream& operator << (ostream& out, const Spieler& sp);
};


#endif
