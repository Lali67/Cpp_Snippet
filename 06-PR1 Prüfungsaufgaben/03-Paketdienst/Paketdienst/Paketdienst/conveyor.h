#ifndef CONVEYOR_H
#define CONVEYOR_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"package.h"

using namespace std;
extern vector <string> region_names;

class Conveyor {
private:
	vector<Region> regions;
	vector<Package> packages;
public:
	Conveyor(vector<Region> tregions) 
	{
		for (int i = 0; i < tregions.size(); i++)
			regions.push_back(tregions.at(i));

		if (regions.size() == 0)
			throw runtime_error("runtime error");
	}
	Conveyor(vector<Region> tregions, vector<Package> tpackages) 
	{
		for (int i = 0; i < tregions.size(); i++)
			regions.push_back(tregions.at(i));

		if (regions.size() == 0)
			throw runtime_error("runtime error");
		
		for (int i = 0; i < tpackages.size(); i++)
			packages.push_back(tpackages.at(i));
		
		for (const Package& p : packages)
		{
			bool found = p.destination_in(regions);
			if (!found)
				throw runtime_error("runtime error");
		}
	}

	vector<Package> add_packages(const vector<Package>& v);
	bool overlap(const Conveyor& c) const;
	friend ostream& operator << (ostream& out, const Conveyor& cc);
};

#endif