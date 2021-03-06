#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include"zutat.h"

using namespace std;

int Zutat::brennwert() const { return tbrennwert; }

bool operator == (const Zutat& z1, const Zutat& z2) 
{ 
	return z1.name == z2.name && z1.brennwert() == z2.brennwert();
}

ostream& operator << (ostream& out, const Zutat& zt) 
{
	out << "[" << zt.name << " " << zt.brennwert() << " kJ]";

	return out;
}