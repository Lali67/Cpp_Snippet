#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"kleidst.h"
#include"waschm.h"

using namespace std;

void WaschM::zuladen(const vector<KleidSt>& z) 
{
	for (const KleidSt& k : z)
		(this->kleidungsstuecke).push_back(k);
}

void WaschM::waschen(Programm pr) 
{
	int summe{ 0 };

	for (const auto& k : kleidungsstuecke)
	{
		if(!k.vertraeglich(pr)) throw runtime_error("runtime error");
		summe += k.getgewicht();
	}

	if(summe > this->max_lad_gewicht) throw runtime_error("runtime error");
	this->kleidungsstuecke = {};
}

ostream& operator << (ostream& out, const WaschM& w) 
{
	out << "[" << w.max_lad_gewicht << " g {";

	if (w.kleidungsstuecke.size() == 0)
		out << "}]";

	else
	{
		for (int i = 0; i < w.kleidungsstuecke.size() - 1; i++)
			out << w.kleidungsstuecke.at(i) << ", ";
		out << w.kleidungsstuecke.at(w.kleidungsstuecke.size() - 1) << "}]";
	}

	return out;
}

vector<KleidSt> WaschM::aussortieren(Programm p) 
{
	vector<KleidSt> retour;
	vector<KleidSt> neuwasch;

	for (const auto& k : kleidungsstuecke)
	{
		if (!k.vertraeglich(p))
			retour.push_back(k);
		else
			neuwasch.push_back(k);
	}

	this->kleidungsstuecke = neuwasch;

	return retour;
}