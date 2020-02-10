#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"show.h"
#include"tvstation.h"

using namespace std;

vector<Show> TV_Station::add_shows(const vector<Show>& shows)
{
	vector<Show> temp;

	for (const Show& sh : shows)
	{
		bool gefunden_2{ false };

		for (const Genre& gen : genreliste)
			if (sh.has_genre(gen))
			{
				gefunden_2 = true;
				break;
			}
		
		if (gefunden_2)
			showliste.push_back(sh);

		if (!gefunden_2)
			temp.push_back(sh);
	}

	return temp;
}

unsigned int TV_Station::produce() 
{
	unsigned int count {0};

	for (int i = 0; i < showliste.size(); i++)
	{
		if(showliste.at(i).produce_season())
			count++;
	}

	return count;
}

ostream& operator << (ostream& out, const TV_Station& stat) 
{
	out << "[" << stat.name << ", [";

	for (int i = 0; i < stat.genreliste.size() - 1; i++)
	{
		switch (stat.genreliste.at(i))
		{
		case Genre::Cartoon:
			out << "Cartoon, ";
			break;

		case Genre::Drama:
			out << "Drama, ";
			break;

		case Genre::Fantasy:
			out << "Fantasy, ";
			break;

		case Genre::SciFi:
			out << "SciFi, ";
			break;

		case Genre::Sitcom:
			out << "Sitcom, ";
			break;
		}
	}

	switch (stat.genreliste.at(stat.genreliste.size() - 1))
	{
	case Genre::Cartoon:
		out << "Cartoon], {";
		break;

	case Genre::Drama:
		out << "Drama], {";
		break;

	case Genre::Fantasy:
		out << "Fantasy], {";
		break;

	case Genre::SciFi:
		out << "SciFi], {";
		break;

	case Genre::Sitcom:
		out << "Sitcom], {";
		break;
	}

	if (stat.showliste.size() > 0)
	{
		for (int i = 0; i < stat.showliste.size() - 1; i++)
			out << stat.showliste.at(i) << ", ";

		out << stat.showliste.at(stat.showliste.size() - 1) << "}]";
	}

	else
		out << "}]";

	return out;
}