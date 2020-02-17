#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include"exemplar.h"

using namespace std;

bool Exemplar::verfuegbar() const 
{
	return (this->zus != Zustand::Unbrauchbar && !this->verliehen);
}

bool Exemplar::entleihen()
{
	if (this->verfuegbar())
	{
		this->verliehen = true;
		return true;
	}

	return false;
}

//Zustand Exemplar::getzus() const { return this->zus; }

void Exemplar::retournieren(Zustand z) 
{
	bool besser{ true };

	if (zus == Zustand::Neuwertig) 
		besser = false;
	
	if (zus == Zustand::Gut && z != Zustand::Neuwertig)
		besser = false;
	
	if (zus == Zustand::Abgegriffen && z != Zustand::Neuwertig && z != Zustand::Gut)
		besser = false;
	
	if (zus == Zustand::Unbrauchbar && z == Zustand::Unbrauchbar) 
		besser = false;

	if (verliehen && !besser)
	{
		verliehen = false;
		zus = z;
	}

	else
		throw runtime_error("runtime error");
}

ostream& operator << (ostream& out, const Exemplar& e) 
{
	out << "[Auflage: " << e.num_auflag << ", Zustand: ";

	switch (e.zus) 
	{
		case Zustand::Neuwertig:
			out << "neuwertig";
			break;

		case Zustand::Gut:
			out << "gut";
			break;

		case Zustand::Abgegriffen:
			out << "abgegriffen";
			break;

		case Zustand::Unbrauchbar:
			out << "unbrauchbar";
			break;

	}

	if (e.verliehen)
		out << ", verliehen]";

	if(!e.verliehen)
		out << "]";

	return out;
}
