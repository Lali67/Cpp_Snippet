#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"conveyor.h"

using namespace std;

vector<Package> Conveyor::add_packages(const vector<Package>& v) {
	vector<Package> temp;

	for (const Package& p : v)
	{
		bool found = p.destination_in(regions);
		if (found)
			packages.push_back(p);
		else
			temp.push_back(p);
	}

	return temp;
}

bool Conveyor::overlap(const Conveyor& c) const {
	bool stimmt{false};
	
	for (const Region& r : regions)
	{
		for (const Region& cr : c.regions)
		{
			stimmt = cr == r;
			if (stimmt)
				break;
		}
		
		if (stimmt)
			break;
	}
	
	return stimmt;
}

ostream& operator << (ostream& out, const Conveyor& cc) {
	
	out << "[{";
	
	for (const Region& r : cc.regions)
	{
		switch (r)
		{
		case Region::EU:
			out << "EU, ";
			break;
		case Region::US:
			out << "USA, ";
			break;
		case Region::SA:
			out << "South America, ";
			break;
		case Region::AFR:
			out << "Africa, ";
			break;
		case Region::AUS:
			out << "Australia, ";
			break;
		case Region::OTHER:
			out << "Other, ";
			break;
		}
	}
	out << "}, {";
	for (const Package& p : cc.packages)
		out << p << ", ";

	out << "}]";

	return out;
}