#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "topping.h"

using namespace std;

class Pizza {
private:
	vector<Topping> toppings;
public:
	Pizza () 
	{
		Topping Tomato_sauce{ "Tomato sauce" };
		Topping Cheese{ "Cheese", "G" };

		toppings.push_back(Tomato_sauce);
		toppings.push_back(Cheese);
	}
	Pizza (vector<Topping> gew) 
	{
		for (const Topping& t : gew)
			toppings.push_back(t);

		Topping Tomato_sauce{ "Tomato sauce" };
		Topping Cheese{ "Cheese", "G" };
		bool tomato_found{ false };
		bool cheese_found{ false };

		for (const Topping& t : toppings)
			if (t == Tomato_sauce) { tomato_found = true; break; }

		for (const Topping& t : toppings)
			if (t == Cheese) { cheese_found = true; break; }

		if (!tomato_found)  toppings.push_back(Tomato_sauce);
		if (!cheese_found)	toppings.push_back(Cheese);

		if (toppings.size() == 0)
			throw runtime_error("runtime");
	}
	Pizza (vector<Topping> gew, vector<Topping> ungew)
	{
		Topping Tomato_sauce{ "Tomato sauce" };
		Topping Cheese{ "Cheese", "G" };
		bool tomato_found{ false };
		bool cheese_found{ false };

		for(const Topping& t : ungew)
			if (t == Tomato_sauce) { tomato_found = true; break; }

		for (const Topping& t : ungew)
			if (t == Cheese) { cheese_found = true; break; }

		if (!tomato_found)  toppings.push_back(Tomato_sauce); 
		if (!cheese_found)	toppings.push_back(Cheese);

		vector<bool> in{};

		for (int i = 0; i < gew.size(); i++)
		{
			bool gefunden{ false };

			for (int j = 0; j < toppings.size(); j++)
				if (gew.at(i) == toppings.at(j)) { gefunden = true; }

			in.push_back(gefunden);
		}

		for (int i = 0; i < in.size(); i++)
			if (in.at(i) == false) toppings.push_back(gew.at(i));

		if (toppings.size() == 0)
			throw runtime_error("runtime");
	}

	double price() const;
	friend ostream& operator << (ostream& out, const Pizza& p);

};

#endif