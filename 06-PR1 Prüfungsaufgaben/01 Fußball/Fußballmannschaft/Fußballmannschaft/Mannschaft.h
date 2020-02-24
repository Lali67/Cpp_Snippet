#ifndef MANNSCHAFT_H
#define MANNSCHAFT_H

#include <iostream>
#include <vector>
#include <string>
#include <exception>

using namespace std;

class Mannschaft {
private:
	string mname;
	vector <Spieler> spielerliste;
public:
	Mannschaft(string tmname) : mname(tmname)
	{
		if (mname.size() == 0) throw runtime_error("runtime error");
	}
	Mannschaft(string tmname, vector <Spieler> tspielerliste) : mname(tmname)
	{
		if (mname.size() == 0) throw runtime_error("runtime error");
		
		for (int i = 0; i < tspielerliste.size(); i++)
			spielerliste.push_back(tspielerliste.at(i));

		for (int i = 0; i < spielerliste.size(); i++)
		{
			int count{ 0 };

			for (int j = 0; j < spielerliste.size(); j++)
				if (spielerliste.at(i) == spielerliste.at(j))
					count++;

			if(count > 1) throw runtime_error("runtime error");
		}
	}

	vector<Spieler> engagieren(const vector<Spieler>& vecs);
	friend ostream& operator << (ostream& out, const Mannschaft& ms);
};

#endif