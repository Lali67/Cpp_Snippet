#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "Spieler.h"
using namespace std;

bool operator==(const Spieler& sp, const Spieler& sk) {
	
	if (sp.name == sk.name)
		return true;
	else
		return false;
}
ostream& operator << (ostream& out, const Spieler& sp) {
	out << "[" << sp.name << ", " << sp.summe << " Mio Euro, ";
	
	switch(sp.pos)
	{
	case Position::Tor :
		out << "Tor" << "]";
		break;
	case Position::Abwehr:
		out << "Abwehr" << "]";
		break;
	case Position::Mitte:
		out << "Mitte" << "]";
		break;
	case Position::Sturm:
		out << "Sturm" << "]";
		break;
	}
	return out;
}