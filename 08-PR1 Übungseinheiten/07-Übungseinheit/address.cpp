#include<iostream>
#include<string>
#include<vector>
#include"city.h"
#include"zip.h"
#include"address.h"

using namespace std;

ostream& Address::print(ostream& o) {
 o << first_name << ' ' << surname << '\n' << road << ' ' << street_number << '\n';
 zip.print(o);
 return o;
}

vector<vector<Address>> group(const vector<Address>& addresses) {
  vector<vector<Address>> ret;
  for (const auto& address : addresses) {
    bool found{false};
    for (auto& group : ret)
      if (group.at(0).zip.code == address.zip.code) {
        found = true;
        group.push_back(address);
      }
    if (!found)
      ret.push_back(vector<Address>{address});
  }
  return ret;
}