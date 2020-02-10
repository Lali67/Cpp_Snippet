#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"gemaelde.h"
#include "galerie.h"

using namespace std;

int Galerie::gesamtwert() const
{
	int summe{0};

	for (const Gemaelde& gem : gemaelde)
		summe += gem.get_wert();

	return summe;
}

ostream& operator << (ostream& out, const Galerie& gal)
{
	//[Bezeichnung, Gesamtwert{ Liste der Gemälde }]
	
	out << "[" << gal.bezeichnung << ", " << gal.gesamtwert() << " {";
	
		for (int i = 0; i < gal.gemaelde.size() - 1; i++)
			out << gal.gemaelde.at(i) << ", ";

		out << gal.gemaelde.at(gal.gemaelde.size() - 1) << "}]";
	
	return out;
}