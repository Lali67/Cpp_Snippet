#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"kleidst.h"

using namespace std;

bool KleidSt::vertraeglich(Programm p) const 
{
	if(pflegehinweis == Programm::Koch)
		return true;

	if (pflegehinweis == Programm::Normal && p != Programm::Koch)
		return true;

	if (pflegehinweis == Programm::Bunt)
		if(p != Programm::Koch && p != Programm::Normal)
		return true;

	if (pflegehinweis == Programm::Fein && p == Programm::Fein)
		return true;

	return false;
}

int KleidSt::getgewicht() const { return gewicht; }
Programm KleidSt::getprogramm() const { return pflegehinweis; }

ostream& operator << (ostream& out, const KleidSt& k) 
{
	out << "[" << k.bezeichnung << ", " << k.gewicht << " g, ";

	switch (k.pflegehinweis)
	{
		case Programm::Koch:
			out << "Kochwaesche]";
			break;

		case Programm::Normal:
			out << "Normalwaesche]";
			break;

		case Programm::Bunt:
			out << "Buntwaesche]";
			break;

		case Programm::Fein:
			out << "Feinwaesche]";
			break;
	}

	return out;
}