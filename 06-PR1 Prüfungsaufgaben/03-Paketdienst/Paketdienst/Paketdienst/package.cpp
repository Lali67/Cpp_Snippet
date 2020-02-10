#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"package.h"

using namespace std;

vector <string> region_names {"EU", "USA", "South America", "Africa", "Australia", "Other"};

bool Package::destination_in(const vector <Region>& v) const 
{
	bool gefunden{ false };
	
	for (int i = 0; i < v.size(); i++) 
	//for(const Region& item: v )
	{
		if (destination == v.at(i))
			gefunden = true;
	}
	
	return gefunden;
}

ostream& operator << (ostream& out, const Package& pp) 
{
		out << "[";
		/*switch (pp.destination) 
		{
			case Region::EU: 
				out << "EU ";
				break;
			case Region::US:
				out << "USA ";
				break;
			case Region::SA:
				out << "South America ";
				break;
			case Region::AFR:
				out << "Africa ";
				break;
			case Region::AUS:
				out << "Australia ";
				break;
			case Region::OTHER:
				out << "Other ";
				break;
		}
		*/
		out << region_names.at(int(pp.destination)) << " ";

		if(pp.weight > 10000)
			out << pp.weight << " g heavy]";
		else
			out << pp.weight << " g]";

	return out;
}