#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Category{Economy, Business, First};
const vector<string> category_names{"Economy", "Business", "First"};

//Definition der Klasse Passenger

class Passenger{
  private:
  	string name;
  	Category category;
  public:
  	Passenger(string name_in, Category c);
  	Passenger(string name_in);
  	bool in_category(Category c) const;
  	bool operator==(Passenger p) const;
  	ostream& print(ostream& o) const; 
  	Category get_category()const;
  
  
};

ostream& operator<< (ostream& o, const Passenger& p);
#endif