#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"wagon.h"
#include"train.h"

using namespace std;

//extern vector<string> feature_names;

int Train::total_load() const 
{
	int totale_summe{lok_masse};

	for (const Wagon& wg : wagons)
		totale_summe += wg.get_mass();

	return totale_summe;
}

bool Train::ready() const
{
	bool ready_load{false};
	bool ready_feature{ false };
	bool ready_toilet{ true };
	bool is_bar{ false };
	bool is_restaurant{ false };
	bool is_couchette{ false };
	bool is_standard{ false };
	bool is_toilet{ false };
	int count{ 0 };

	if (total_load() <= max_last)
		ready_load = true;

	for (const Wagon& wg : wagons)
	{
		if (wg.has_feature(Feature::Bar)) is_bar = true;
		if (wg.has_feature(Feature::Restaurant)) is_restaurant = true;
		if (wg.has_feature(Feature::Couchette)) is_couchette = true;
		if (wg.has_feature(Feature::Standard)) is_standard = true;
		if (wg.has_feature(Feature::Toilet)) is_toilet = true;
	}

	if (is_bar && is_restaurant && is_couchette && is_standard && is_toilet)
		ready_feature = true;

	for (const Wagon& wg : wagons) 
	{
		if (wg.has_feature(Feature::Toilet)) count = 0;
		else
		{
			count++;
			if(count > 3)
			{
				ready_toilet = false;
				break;
			}
		}
	}

	return ready_load && ready_feature && ready_toilet;
}

void Train::couple(vector<Wagon> wag)
{
	for (const Wagon& vg : wag)
		wagons.push_back(vg);
}

vector<Wagon> Train::uncouple(size_t from)
{
	vector<Wagon> temp;

	if (from < 0 || from >= wagons.size())
		throw runtime_error("runtime error");

	for (size_t i = from; i < wagons.size(); i++)
	{
		temp.push_back(wagons.at(i));
		wagons.erase(wagons.begin() + i);
		i--;
	}

	return temp;
}

ostream& operator << (ostream& out, const Train& zug) 
{
	out << "[" << zug.total_load() << "/" << zug.max_last << " tons, ";

	if (zug.ready())
		out << " ready {";

	else
		out << " not ready {";

	if (zug.wagons.size() > 0)
	{
		for (int i = 0; i < zug.wagons.size() - 1; i++)
			out << zug.wagons.at(i) << ", ";

		out << zug.wagons.at(zug.wagons.size() - 1) << "}]";
	}

	else
		out << "}]";

	return out;
}