#include "miniatur.h"
#include "vector.h"
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<algorithm>
#include<numeric>		//accumulate

using namespace std;

Miniatur::Miniatur(std::string aName, Fraktion aFraktion, int aPoints, std::vector<int> aStats)
{
	name = aName; points = aPoints; stats = aStats;
}

std::ostream& Miniatur::to_s(Fraktion type, std::ostream& out) const{
	switch (type) {
		case Fraktion::Tyraniden:			out<< "Tyraniden"; break;
		case Fraktion::SM:					out << "SM"; break;
		case Fraktion::CSM:					out << "CSM"; break;
		case Fraktion::Orks:				out << "Orks"; break;
		case Fraktion::AstraMilitarum:		out << "AstraMilitarum"; break;
		case Fraktion::GreyKnights:			out << "GreyKnights"; break;
		case Fraktion::Demons:				out << "Demons"; break;
		case Fraktion::Harlequins:			out << "Harlequins"; break;
		case Fraktion::ThousandSons:		out << "ThousandSons"; break;
		case Fraktion::AdeptusMechanicus:	out << "AdeptusMechanicus"; break;
		case Fraktion::Craftworlds:			out << "Craftworlds"; break;
		case Fraktion::Drukhari:			out << "Drukhari"; break;
	}

	return out;
}

void Miniatur::add_points(int pt_num) 
	{ points += pt_num; };
const std::string& Miniatur::get_name() const 
	{ return name; };
Fraktion Miniatur::get_fraktion() const 
	{ return f; };
int Miniatur::get_points() const 
	{ return points; };
const std::vector<int>& Miniatur::get_stats() const 
	{ return stats; }; 

std::ostream& Miniatur::print(std::ostream& out) const 
	{ return out; };
std::ostream& Miniatur::write(std::ostream& out) const
	{ return out; };
std::istream& Miniatur::read(std::istream& in) 
{
	in >> name; return in;
};

std::ostream& Spezial_Miniatur::print(std::ostream& out) const{
	return out;
}

std::istream& operator>>(std::istream& o, Miniatur& s) 
	{ return o; };
