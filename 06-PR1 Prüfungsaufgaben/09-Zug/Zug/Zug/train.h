#ifndef TRAIN_H
#define TRAIN_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

class Train {
private:
	int lok_masse;
	int max_last;
	vector<Wagon> wagons;
public:
	Train(int tlok_masse, int tmax_last) : lok_masse(tlok_masse), max_last(tmax_last)
	{
		if(lok_masse < 50 || lok_masse > 200 || max_last < 200 || max_last > 10000)
			throw runtime_error("runtime error");
	}
	
	Train(int tlok_masse, int tmax_last, vector<Wagon> twagons) : lok_masse(tlok_masse), max_last(tmax_last)
	{
		for (const Wagon& wg : twagons)
			wagons.push_back(wg);

		if (lok_masse < 50 || lok_masse > 200 || max_last < 200 || max_last > 10000)
			throw runtime_error("runtime error");
	}

	int total_load() const;
	bool ready() const;
	void couple(vector<Wagon> wag);
	vector<Wagon> uncouple(size_t from);
	friend ostream& operator << (ostream& out, const Train& zug);
};

#endif
