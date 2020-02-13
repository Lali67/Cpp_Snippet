#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"wagon.h"

using namespace std;

//vector<string> feature_names{ "bar", "restaurant", "couchette", "standard", "toilet" };

int Wagon::get_mass() const 
{
	return masse;
}

bool Wagon::has_feature(Feature f) const 
{
	if (einrichtung == f)
		return true;

	else
		return false;
}

ostream& operator << (ostream& out, const Wagon& wg) 
{
	out << "[mass: " << wg.masse << " tons ";
	
	switch (wg.einrichtung)
	{
		case Feature::Bar:
			out << "bar-wagon]";
			break;

		case Feature::Restaurant:
			out << "restaurant-wagon]";
			break;

		case Feature::Couchette:
			out << "couchette-wagon]";
			break;

		case Feature::Standard:
			out << "standard-wagon]";
			break;

		case Feature::Toilet:
			out << "toilet-wagon]";
			break;
	}

	return out;
}