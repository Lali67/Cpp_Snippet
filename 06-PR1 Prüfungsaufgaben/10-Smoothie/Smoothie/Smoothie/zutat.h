#ifndef ZUTAT_H
#define ZUTAT_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Zutat {
private:
	string name;
	int tbrennwert;
public:
	Zutat(string tname, int twert = 32) : name(tname), tbrennwert(twert)  
	{
		if (name.size() == 0 || tbrennwert < 10 || tbrennwert > 75)
			throw runtime_error("runtime error");
	}

	int brennwert() const;
	friend bool operator == (const Zutat& z1, const Zutat& z2);
	friend ostream& operator << (ostream& out, const Zutat& zt);

};

#endif
