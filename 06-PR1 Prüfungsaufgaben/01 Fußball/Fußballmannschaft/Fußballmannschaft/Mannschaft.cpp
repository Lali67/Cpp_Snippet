#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "Spieler.h"
#include "Mannschaft.h"
using namespace std;

vector<Spieler> Mannschaft::engagieren(const vector<Spieler>& vecs) 
{
	vector<Spieler> temp;
	
	for (Spieler v1 : vecs) 
	{
		bool gefunden = false;

		for (Spieler v2 : spielerliste) 
			if (v1 == v2) { gefunden = true; break; }
				
		if (gefunden)  temp.push_back(v1);
		if (!gefunden) spielerliste.push_back(v1);
	}

	return temp;
}

ostream& operator << (ostream& out, const Mannschaft& ms) 
{
	out << "[" << ms.mname << ", {";

	if (ms.spielerliste.size() > 0)
	{
		for (int i = 0; i < ms.spielerliste.size() - 1; i++)
			out << ms.spielerliste.at(i) << ", ";

		out << ms.spielerliste.at(ms.spielerliste.size() - 1) << "}]";
	}
	else
		out << "}]";

	return out;
}