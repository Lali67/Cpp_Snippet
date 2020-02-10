#ifndef GEBOT_H
#define GEBOT_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Gebot {
private:
	string name;
	int betrag;
public:
	Gebot(string tname, int tbetrag = 100) : name(tname), betrag(tbetrag) 
	{
		if (name.size() == 0 || betrag <= 0 || betrag > 10000000)
			throw runtime_error("runtime error");
	}

	bool selbe_bieterin(const Gebot& gf) const;
	friend bool operator == (const Gebot& gf, const Gebot& fg);
	friend bool operator < (const Gebot& gf, const Gebot& fg);
	friend bool operator >= (const Gebot& gf, int fg);
	friend ostream& operator << (ostream& out, const Gebot& gf);

};

#endif 

