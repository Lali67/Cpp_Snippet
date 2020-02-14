#ifndef SMOOTHIE_H
#define SMOOTHIE_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Smoothie {
private:
	string bezeichnung;
	vector<Zutat> zutaten;
public:
	Smoothie(string tbez) : bezeichnung(tbez)
	{
		if(bezeichnung.size() == 0)
			throw runtime_error("runtime error");
	}

	void hinzu(const Zutat& z);
	int brennwert() const;
	friend ostream& operator << (ostream& out, const Smoothie& sm);
	void unterheben(const Zutat& z);
	void liste(ostream& out) const;

};

#endif
