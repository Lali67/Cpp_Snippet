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
	int count{ 0 };

		for (const Exemplar& e : this->exemplare)
		{
			count++;
			if (e.verfuegbar())
			{
				count--;
				break;
			}
		}
		if (count == this->exemplare.size() - 1 || this->exemplare.size() == 0)
			return false;

		this->exemplare.at(count).entleihen();
		return true;
	
}

void Werk::retournieren(int index, Zustand z)
{
	if(index < 0 || index >= this->exemplare.size())
		throw runtime_error("runtime error"); 

	if (!this->exemplare.at(0).entleihen() || z == Zustand::Unbrauchbar)
		throw runtime_error("runtime error");

	this->exemplare.at(0).retournieren(z);
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