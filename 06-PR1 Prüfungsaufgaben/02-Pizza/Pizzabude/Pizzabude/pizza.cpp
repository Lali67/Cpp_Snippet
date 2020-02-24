#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "pizza.h" 

using namespace std;

double Pizza::price() const
{
	double preis{ 7 };
	Topping Tomato_sauce{ "Tomato sauce" };
	Topping Cheese{ "Cheese", "G" };
	int count{ 2 };

	for (const Topping& t : toppings)
	{
		if (t == Tomato_sauce == false && t == Cheese == false && count <= 0)
		{
			preis += 1;
		}
		if (t.is_specialty()) preis += 0.5;
		count--;
	}

	return preis;
}

ostream& operator << (ostream& out, const Pizza& p) 
{
	out << "[{";

	for(int i = 0; i < p.toppings.size() - 1; i++)
		out << p.toppings.at(i) << ", ";
	out << p.toppings.at(p.toppings.size() - 1) << "}, " << p.price() << " Euro]";

	return out;
}