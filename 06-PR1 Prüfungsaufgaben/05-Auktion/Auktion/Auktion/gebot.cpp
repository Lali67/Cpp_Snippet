#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "gebot.h"

using namespace std;

bool Gebot::selbe_bieterin(const Gebot& gf) const 
{
	if (name == gf.name)
		return true;

	else
		return false;
}

bool operator == (const Gebot& gf, const Gebot& fg) 
{
	if (gf.betrag == fg.betrag)
		return true;

	else
		return false;
}

bool operator < (const Gebot& gf, const Gebot& fg) 
{
	if (gf.betrag < fg.betrag)
		return true;

	else
		return false;
}

bool operator >= (const Gebot& gf, int fg) 
{
	if (gf.betrag >= fg)
		return true;

	else
		return false;
}

ostream& operator << (ostream& out, const Gebot& gf)
{
	out << "[" << gf.name << ": " << gf.betrag << " Euro]";
	
	return out;
}