#ifndef ADDRESS_H
#define ADDRESS_H

#include<iostream>
#include<string>
#include<vector>
#include"city.h"
#include"zip.h"
using namespace std;

struct Address {
  string first_name;
  string surname;
  string road;
  string street_number;
  ZIP zip;

  ostream& print(ostream& = cout);
};

vector<vector<Address>> group(const vector<Address>&);

#endif //ADDRESS_H