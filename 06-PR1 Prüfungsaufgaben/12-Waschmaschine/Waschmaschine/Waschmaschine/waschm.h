#ifndef WASCHM_H
#define WASCHM_H

#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

class WaschM {
private:
	int max_lad_gewicht;
	vector<KleidSt> kleidungsstuecke;
public:
	WaschM (int tgew) : max_lad_gewicht(tgew)
	{
		if (max_lad_gewicht < 4000 || max_lad_gewicht > 50000)
			throw runtime_error("runtime error");
	}

	void zuladen(const vector<KleidSt>& z);
	void waschen(Programm pr);
	friend ostream& operator << (ostream& out, const WaschM& w);
	vector<KleidSt> aussortieren(Programm p);
};

#endif