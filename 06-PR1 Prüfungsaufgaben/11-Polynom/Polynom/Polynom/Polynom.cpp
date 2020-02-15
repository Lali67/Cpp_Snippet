#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>
#include"polynom.h"

using namespace std;

int Polynom::grad() const
{
	/*int count{ 0 };

	for (const int& i : koeffizienten)
		count++;
	
	count--; 

	return count; */
	return koeffizienten.size() - 1;
}

ostream& operator << (ostream& out, const Polynom& p) 
{
	int n = p.koeffizienten.size() - 1;

	for (int i = p.koeffizienten.size() - 1; i >= 1; i--)
	{
		out << p.koeffizienten.at(i) << "x^" << n-- << "+";
	}
	out << p.koeffizienten.at(0);

	return out;
}

int Polynom::wert(int n) const 
{
	//x2 + x + 1 , n = 2, return 2*2 + 2 + 1 = 7
	int ret{0};

	for (int i = koeffizienten.size() - 1; i >= 1; i--)
	{
		ret += koeffizienten.at(i) * pow(n, i);
	}
	ret += koeffizienten.at(0);

	return ret;
}

ostream& Polynom::print_fmt(ostream& o) const 
{
	int n = koeffizienten.size() - 1;

	for (int i = koeffizienten.size() - 1; i >= 1; i--)
	{
		if (koeffizienten.at(i) != 0)
		{
			if (koeffizienten.at(i) != 1 && koeffizienten.at(i) != -1)
				o << koeffizienten.at(i);
			if (koeffizienten.at(i) == -1)
				o << "-";
			if (n != 1)
				o << "x^" << n;
			if (n == 1)
				o << "x";
			if (koeffizienten.at(i - 1) > 0)
				o << "+";
		}
		else
			if (koeffizienten.at(i - 1) > 0)
				o << "+";
		n--;
	}

	if(koeffizienten.at(0) != 0)
		o << koeffizienten.at(0);

	return o;
}