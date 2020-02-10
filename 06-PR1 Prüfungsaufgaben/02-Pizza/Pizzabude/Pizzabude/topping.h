#ifndef TOPPING_H
#define TOPPING_H

#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

class Topping {
	string name;
	string allergenes;
	bool specialty;
public:
	Topping(string tname, string tallergenes = "", bool tspecialty = false): name(tname), allergenes(tallergenes), specialty(tspecialty)
	{
		if (name.size() == 0)
			throw runtime_error("runtime error");
	};
	bool is_specialty() const;
	friend bool operator == (const Topping& t1, const Topping& t2);
	friend ostream& operator << (ostream& out, const Topping& ts);
};

#endif 