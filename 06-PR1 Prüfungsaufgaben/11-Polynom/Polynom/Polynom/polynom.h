#ifndef POLYNOM_H
#define POLYNOM_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class Polynom {
private:
	vector<int> koeffizienten;
public:
	Polynom (vector<int> tkoeffizienten)
	{
		for (const int& k : tkoeffizienten)
			koeffizienten.push_back(k);

		if (koeffizienten.size() == 0 || koeffizienten.at(koeffizienten.size() - 1) == 0)
			throw runtime_error("runtime error");
	}

	int grad() const;
	friend ostream& operator << (ostream& out, const Polynom& p);
	int wert(int n) const;
	ostream& print_fmt(ostream& o) const;
};

#endif