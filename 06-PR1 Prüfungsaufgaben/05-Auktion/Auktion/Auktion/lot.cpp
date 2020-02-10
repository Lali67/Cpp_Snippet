#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "gebot.h"
#include "lot.h"
using namespace std;

vector <string> kategorie_namen{ "Schmuck", "Moebel", "Kunst", "Sonstiges" };

bool Lot::ist_offen() const
{
	if (cat == Kategorie::Schmuck || cat == Kategorie::Kunst)
		return true;

	else
		return false;
}

bool Lot::bieten(const Gebot& gf)
{
	bool gefunden{ false };
	Gebot temp{"temp", min_erlös};

	if (ist_offen() && gf < temp)
		return false;

	for (const Gebot& geb : gebote)
		if (gf < geb && geb.selbe_bieterin(gf))
			gefunden = true;

	if(gefunden)
		throw runtime_error("runtime error");
		
	gebote.push_back(gf);
	return true;
	
}

ostream& operator << (ostream& out, const Lot& lt)
{
	out << "[" << lt.bezeichnung << ": " << lt.min_erlös << " Euro, ";
	
	switch (lt.cat)
	{
		case Kategorie::Schmuck:
			out << "Schmuck {";
			break;
		
		case Kategorie::Moebel:
			out << "Moebel {";
			break;
		
		case Kategorie::Kunst:
			out << "Kunst {";
			break;
		
		case Kategorie::Sonstiges:
			out << "Sonstiges {";
			break;
	}
	if (lt.gebote.size() > 0)
	{
		for (int i = 0; i < lt.gebote.size() - 1; i++)
			out << lt.gebote.at(i) << ", ";

		out << lt.gebote.at(lt.gebote.size() - 1) << "}]";
	}
	
	else
	{
		out << "}]";
	}

	return out;
}

