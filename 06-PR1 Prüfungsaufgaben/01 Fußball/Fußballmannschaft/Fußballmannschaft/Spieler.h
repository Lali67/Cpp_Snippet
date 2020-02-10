#ifndef SPIELER_H
#define SPIELER_H

#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;

enum class Position {Tor, Abwehr, Mitte, Sturm};

class Spieler {
private:
	string name;
	int summe;
	Position pos;
public:
	Spieler (string tname, int tsumme, Position tpos = Position::Tor) : name(tname), summe(tsumme)
	{
		if (name.size() == 0)
			throw runtime_error("runtime error");
		if (summe < 10 || summe > 500)
			throw runtime_error("runtime error");
		pos = tpos;
	}
	friend bool operator == (const Spieler& ss, const Spieler& sk);
	friend ostream& operator << (ostream& out, const Spieler& sp);
};


#endif
