#include "miniatur.h"
#include"vector.h"
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<algorithm>
#include<numeric>		//accumulate

using namespace std;

Miniatur::Miniatur(std::string aName, Fraktion aFraktion, int aPoints, std::vector<int> aStats)
{
	name = aName; points = aPoints; stats = aStats;
}
void Miniatur::add_points(int pt_num) 
	{ points += pt_num; };
const std::string& Miniatur::get_name() const 
	{ return name; };
Fraktion Miniatur::get_fraktion() const 
	{ return f; };
int Miniatur::get_points() const 
	{ return points; };
const std::vector<int>& Miniatur::get_stats() const 
	{ return stats; };

std::ostream& Miniatur::print(std::ostream& out) const 
	{ return out; };
std::ostream& Miniatur::write(std::ostream& out) const
	{ return out; };
std::istream& Miniatur::read(std::istream& in) 
{
	in >> name; return in;
};

std::ostream& operator<< (ostream& os, const Miniatur& s) {
	return os;
}

std::istream& operator>>(std::istream& o, Miniatur& s) 
	{ return o; };
