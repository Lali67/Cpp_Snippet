#include <iostream>
#include <string>
#include <vector>
#include "passenger.h"

using namespace std;

//Implementierung der Klasse Passenger


		Passenger::Passenger(string name_in, Category c_in){
      name = name_in;
      category = c_in;
      
      if (name.size() == 0)
      	throw runtime_error("fehler");
       
      
    }
  	Passenger::Passenger(string name_in){
      
      name = name_in;
      category = Category::Economy;
      
      if (name.size() == 0)
      	throw runtime_error("fehler");
       
      
    }

  	bool Passenger::in_category(Category c) const{
      
      if (category == c)
        return true;
      
      return false;
      
      
      
    }
  	bool Passenger::operator==(Passenger p) const{
      
      if (this->name == p.name)
        return true;
      return false;
      
      
    }
  	ostream& Passenger::print(ostream& o) const{
      
      o << "[" << name << ": " << category_names.at(static_cast<int>(category)) << "]";
      return o;
      
      
    }
  
  	Category Passenger::get_category()const{
      
     return category; 
      
      
    }
	ostream& operator<< (ostream& o, const Passenger& p){
      
      return p.print(o);
      
      
    }