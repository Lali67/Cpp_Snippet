#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "topping.h"

using namespace std;

bool Topping::is_specialty() const { return specialty;}

bool operator == (const Topping& t1, const Topping& t2) {return t1.name == t2.name;}

ostream& operator << (ostream& out, const Topping& ts) {

	if (ts.allergenes.size() == 0)
		out << ts.name;
	else 
	{
	out << ts.name << " (";

	for (int i = 0; i < ts.allergenes.size() - 1; i++) 
			out << ts.allergenes.at(i) << ", ";	
	out << ts.allergenes.at(ts.allergenes.size() - 1) << ")";
	}
	
	return out;
}