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
	vector <Topping> toppings;
public:
	Pizza() {}
	Pizza(vector <Topping> gewuenschte) {}
	Pizza(vector <Topping> gewuenschte, vector <Topping> ungewuenschte)
	{
		Topping cheese{ "Cheese", "G" }, tomato{ "Tomato sauce" };
		bool gefunden_cheese{ false };
		bool gefunden_tomato{false};

		for (int i = 0; i < ungewuenschte.size(); i++) 
		{
			if (ungewuenschte.at(i) == cheese)
				gefunden_cheese = true;
			
			if (ungewuenschte.at(i) == tomato)
				gefunden_tomato = true;
		}
		if (!gefunden_cheese)
			toppings.push_back(cheese);

		if (!gefunden_tomato)
			toppings.push_back(tomato);
		
		for (int i = 0; i < gewuenschte.size(); i++) 
		{
			bool gefunden{false};

			for (int j = 0; j < toppings.size(); j++) 
			{
				if (gewuenschte.at(i) == toppings.at(j))
					gefunden = true;
			}
			if (!gefunden)
				toppings.push_back(gewuenschte.at(i));
		}
		if (toppings.size() == 0)
			throw runtime_error("runtime error");
		
	};

	double price() const;
	friend ostream& operator << (ostream& out, const Pizza& pz);

};

#endif 
