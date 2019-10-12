#include <iostream>
#include <string>
#include <vector>
#include "passenger.h"
#include "flight.h"

// Implementierung der Klasse Flight


  	Flight::Flight(string no_in, int seats_in){
      
      no = no_in;
      seats = seats_in;
      
      if ( no.size() == 0)
        throw runtime_error("Fehler");
      if (seats < 0)
        throw runtime_error("Fehler");
      
    }
  	bool Flight::check_in(const Passenger& p){
      
      for (const auto& i:checked_in)
       if (p == i)
         return false;
        
      if (checked_in.size() == static_cast<unsigned>(seats))
        return false;
      
      checked_in.push_back(p);
      return true;
    
      
      
    }
  	bool Flight::board(const Passenger& p){
      
      for (const auto& i:boarded)
        if (p == i)
        	return false;
      
      bool is_da{false};
      
      for (const auto& i:checked_in){
        if (p == i)
         	is_da=true;
      }
      if (!(is_da))
          return false;
      boarded.push_back(p);
     	return true;
      
    }

		bool Flight::is_check(const Passenger& p)const{
      
     for (const auto& i:checked_in)
       if(i == p)
         return true;
      
     return false;      
      
      
    }
		bool Flight::is_onboard(const Passenger& p)const{
      
     for (const auto& i:boarded)
       if(i == p)
         return true;
      
     return false;
    }
  	ostream& Flight::print(ostream& o)const{
      bool is_first{true};
      o << "[" << no << ", {";
      
      for (const auto& i:checked_in){
       if (is_first){
        o << i;
       if(is_onboard(i))
       	o << "*";
        is_first = false;
       }
        else{
          o << ", " << i;
        	if(is_onboard(i))
           o << "*";
        }
      }
      o << "}]";
      return o;
    }
  
  bool Flight::ready(const vector<int>& seats_per_category) const{
    
   if  (seats_per_category.size() != 3 )
     throw runtime_error("fehler");
   for (const auto& i:seats_per_category)
     if (i < 0)
       throw runtime_error("fehler");
    
    int eco{0};
    int business{0};
    int first{0};
    
    for (const auto& i:checked_in)
    	if(!(is_onboard(i) && is_check(i)))
        return false;
      
      for (const auto& i:checked_in){
       if(i.get_category() == Category::Economy)
       	++eco;
       if(i.get_category() == Category::Business)
       	++business;
       if(i.get_category() == Category::First)
        ++first;
      }
      if(eco <= seats_per_category.at(0) && business <= seats_per_category.at(1) && first <= seats_per_category.at(2))
        return true;
    
    
    return false; 
  }


		void Flight::pretty_print() const{
      bool is_first{true};
     if (checked_in.size() == 0 && boarded.size() == 0){
      cout << no; 
     }
     if (boarded.size() == 0 && checked_in.size() > 0){
      cout << no << ", missing: {";
      for (const auto& i: checked_in){
        if (is_first){
          cout << i;
          is_first=false;
        }
        else{
         cout << ", " << i; 
        }
        
      }
       cout << "}";
     }
      
     if ( checked_in.size() > 0 && boarded.size() > 0){
       cout << no << ", boarded: {";
        for (const auto& i: boarded){
          if (is_first){
            cout << i;
            is_first=false;
          }
          else{
           cout << ", " << i; 
          }

        }
       cout << "}";
       if (checked_in.size() != boarded.size()){
         cout <<", missing: {";
          is_first = true;
          for (const auto& i: checked_in){
            if (!(is_onboard(i))){
              if (is_first){
                cout << i;
                is_first=false;
              }
              else{
               cout << ", " << i; 
              }
            }
          }
        
       cout << "}";
       }
     }
      
    }

		ostream& operator<<(ostream& o,const Flight& f){
      
      return f.print(o);
      
    }

