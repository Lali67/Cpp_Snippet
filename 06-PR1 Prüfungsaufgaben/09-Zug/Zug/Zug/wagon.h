#ifndef WAGON_H
#define WAGON_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

enum class Feature { Bar, Restaurant, Couchette, Standard, Toilet };

//extern vector<string> feature_names;

class Wagon {
private:
	int masse;
	Feature einrichtung;
public:
	Wagon(int tmasse, Feature teinrichtung = Feature::Standard) : masse(tmasse) 
	{
		einrichtung = teinrichtung;

		if (masse < 5 || masse > 100) throw runtime_error("runtime error");
	}

	int get_mass() const;
	bool has_feature(Feature f) const;
	friend ostream& operator << (ostream& out, const Wagon& wg);
};

#endif