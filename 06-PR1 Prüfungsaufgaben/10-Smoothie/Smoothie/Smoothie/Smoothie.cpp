#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include"zutat.h"
#include"smoothie.h"

using namespace std;

void Smoothie::hinzu(const Zutat& z) { zutaten.push_back(z); }

int Smoothie::brennwert() const 
{
	int summe{ 0 };

	for (const Zutat& z : zutaten)
		summe += z.brennwert();

	return summe;
}

ostream& operator << (ostream& out, const Smoothie& sm) 
{
	out << "[{";

	if (sm.zutaten.size() > 0)
	{
		for (int i = 0; i < sm.zutaten.size() - 1; i++)
			out << sm.zutaten.at(i) << ", ";
		out << sm.zutaten.at(sm.zutaten.size() - 1) << "}, ";
	}

	else
		out << "}, ";

	out << sm.bezeichnung << "]";

	return out;
}

void Smoothie::unterheben(const Zutat& z) 
{
	if(zutaten.size() == 0) 
		throw runtime_error("runtime error");

	for (int i = 0; i < zutaten.size(); i++)
	{
		zutaten.insert(zutaten.begin() + i, z);
		i++;
	}
}

void Smoothie::liste(ostream& out) const 
{
	vector<Zutat> temp;

	for (const Zutat& z2 : zutaten)
		temp.push_back(z2);
	
	for (int i = 0; i < temp.size(); i++)
	{
		int count{ 0 };

		for (const Zutat& z4 : zutaten) 
			if (temp.at(i) == z4) count++;

		if (count > 1)
			do
			{
				for (int j = temp.size() - 1; j >= 0; j--)
					if (temp.at(j) == temp.at(i))
					{
						temp.erase(temp.begin() + j);
						count--;
						break;
					}
			} while (count > 1);
	}
	
	for (int i = 0; i < temp.size(); i++)
	{
		int count_2{ 0 };

		for (const Zutat& z1 : zutaten)
			if (temp.at(i) == z1) count_2++;

		cout << temp.at(i) << "*" << count_2;

		if (i < temp.size() - 1) cout << ", ";
	}
}