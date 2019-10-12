#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <vector>
#include "passenger.h"

using namespace std;

// Definition der Klasse Flight

class Flight{
	private:
  	string no;
  	int seats;
  	vector<Passenger> checked_in {};
  	vector<Passenger> boarded {};  
  public:
  	Flight(string no_in, int seats_in);
  	bool check_in(const Passenger& p);
  	bool board(const Passenger& p);
  	ostream& print(ostream& o)const;
  	bool is_onboard(const Passenger& p)const;
 	 	bool is_check(const Passenger& p)const;
  	bool ready(const vector<int>& seats_per_category) const;
  	void pretty_print() const;
  
  
 
  
};
ostream& operator<<(ostream& o,const Flight& f);

#endif