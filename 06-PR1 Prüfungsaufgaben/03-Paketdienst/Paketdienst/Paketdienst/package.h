#ifndef PACKAGE_H
#define PACKAGE_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

enum class Region {EU, US, SA, AFR, AUS, OTHER};
extern vector <string> region_names; 

class Package {
private:
	int weight;
	Region destination;
public:
	Package(int tweight, Region tdestination = Region::EU) : weight(tweight), destination(tdestination) 
	{
		if (weight < 5 || weight > 20000)
			throw runtime_error("runtime error");
	}

	bool destination_in(const vector <Region>& v) const;
	friend ostream& operator << (ostream& out, const Package& pp);

};


#endif