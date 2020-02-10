#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"gemaelde.h"

using namespace std;

int Gemaelde::get_wert() const
{
	return wert;
}

string Gemaelde::get_name() const
{
	return name;
}

bool Gemaelde::hat_interessent() const
{
	if (interessenten.size() > 0)
		return true;

	else
		return false;
}

void Gemaelde::add_interessent(const string& interessent)
{
	if (interessent.size() == 0)
		throw runtime_error("runtime error");

	else
		interessenten.push_back(interessent);
}

ostream& operator << (ostream& out, const Gemaelde& gem)
{
	//[Name:Stil, Wert{ Interessentenliste }]

	out << "[" << gem.name << ": ";

	switch (gem.st)
	{
		case Stil::Abstrakt:
			out << "abstrakt, ";
			break;

		case Stil::Klassisch:
			out << "klassisch, ";
			break;

		case Stil::Surreal:
			out << "surreal, ";
			break;
	}

	out << gem.wert << " {";

	if (gem.interessenten.size() > 0)
	{
		for (int i = 0; i < gem.interessenten.size() - 1; i++)
			out << gem.interessenten.at(i) << ", ";

		out << gem.interessenten.at(gem.interessenten.size() - 1) << "}]";
	}

	else
		out << "}]";

	return out;
}