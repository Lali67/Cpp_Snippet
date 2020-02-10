#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "pizza.h" 

using namespace std;

double Pizza::price() const {
	Topping cheese{ "Cheese", "G" }, tomato{ "Tomato sauce" };
	vector <Topping> list;
	double preis{ 7 };
	int count{ 0 };

	for (int i = 0; i < toppings.size(); i++)
	{
		if (toppings.at(i) == cheese)
			count++;
		else
			if (toppings.at(i) == tomato)
				count++;
			else
				list.push_back(toppings.at(i));
	}
	
	for (int i = 0; i < list.size() - count; i++)
	{
		if (list.at(i).is_specialty())
			preis += 1.5;
		else
			preis += 1;
	}

	return preis;
}


ostream& operator << (ostream& out, const Pizza& pz) {

	
	out << "[";
	
	for (int i = 0; i < pz.toppings.size() - 1; i++) 
	{
		out << pz.toppings.at(i) << ", ";
	}
	out << pz.toppings.at(pz.toppings.size() - 1);
	out << pz.price() << " Euro]";

	return out;
}