#ifndef WERK_H
#define WERK_H

#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>

using namespace std;

class Werk {
private:
	string autor;
	string name;
	int ersch_jahr;
	vector<Exemplar> exemplare;
public:
	Werk(string tat, string tn, int jahr) : autor(tat), name(tn), ersch_jahr(jahr)
	{
		exemplare = {};
		if (autor.size() == 0 || name.size() == 0 || ersch_jahr < 1700 || ersch_jahr > 2017)
			throw runtime_error("runtime error");
	}

	void erwerben(int nr, Zustand z);
	bool entleihen();
	void retournieren(int index, Zustand z);
	friend ostream& operator << (ostream& out, const Werk& w);

};

#endif
