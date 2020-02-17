#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include"exemplar.h"
#include"werk.h"

using namespace std;

void Werk::erwerben(int nr, Zustand z) 
{
	Exemplar temp{nr, z};

	if (z == Zustand::Unbrauchbar)
		throw runtime_error("runtime error");

	else
		this->exemplare.push_back(temp);
}

bool Werk::entleihen()
{
	for (int i = 0; i < this->exemplare.size(); i++)
		if (this->exemplare.at(i).verfuegbar())
		{
			this->exemplare.erase(this->exemplare.begin() + i);
			return true;
		}
	
	return false;
}

void Werk::retournieren(int index, Zustand z)
{
	if(index >= exemplare.size())
		throw runtime_error("runtime error");
	if(exemplare.at(index).verfuegbar()) 
		throw runtime_error("runtime error");
	
	exemplare.at(index).retournieren(z);
}

ostream& operator << (ostream& out, const Werk& w) 
{
	out << "[" << w.autor << ", " << w.name << ", " << w.ersch_jahr << " {";

	if (w.exemplare.size() == 0)
		out << "}]";

	else
	{
		for (int i = 0; i < w.exemplare.size() - 1; i++)
			out << w.exemplare.at(i) << ", ";
		out << w.exemplare.at(w.exemplare.size() - 1) << "}]";
	}

	return out;
}