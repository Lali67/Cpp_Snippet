#ifndef GALERIE_H
#define GALERIE_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

class Galerie {
private:
	string bezeichnung;
	vector<Gemaelde> gemaelde;
public:
	Galerie(string tbezeichnung, vector<Gemaelde> tgemaelde) : bezeichnung(tbezeichnung) 
	{
		for (const Gemaelde& gm : tgemaelde)
			gemaelde.push_back(gm);

		if(bezeichnung.size() == 0 || gemaelde.size() == 0)
			throw runtime_error("runtime error");

	}

	int gesamtwert() const;
	friend ostream& operator << (ostream& out, const Galerie& gal);

};

#endif
