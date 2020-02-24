#ifndef TVSTATION_H
#define TVSTATION_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

class TV_Station {
private:
	string name;
	vector<Genre> genreliste;
	vector<Show> showliste;
public:
	TV_Station(string tname, vector<Genre> tgenreliste) : name(tname)
	{
			for (const Genre& gen : tgenreliste)
				genreliste.push_back(gen);

			if (name.size() == 0 || genreliste.size() == 0)
				throw runtime_error("runtime error");
	}

	TV_Station(string tname, vector<Genre> tgenreliste, vector<Show> tshowliste) : name(tname)
	{
		for (const Genre& gen : tgenreliste)
			genreliste.push_back(gen);

		for (const Show& sh : tshowliste)
			showliste.push_back(sh);

		if (name.size() == 0 || genreliste.size() == 0)
			throw runtime_error("runtime error");

		for (const Show& sh : showliste)
		{
			bool gefunden{ false };

			for (const Genre& gen : genreliste)
				if (sh.has_genre(gen))
				{
					gefunden = true;
					break;
				}
					
			if (!gefunden)
				throw runtime_error("runtime error");
		}
	}

	vector<Show> add_shows(const vector<Show>& shows);
	unsigned int produce();
	friend ostream& operator << (ostream& out, const TV_Station& stat);

};

#endif
