#include<iostream>
#include<string>
#include<vector>
#include"zip.h"

using namespace std;

bool ZIP::check() {
  for (const auto& c : cities)
    if (c.zip_code==code)
      return true;
  return false;
}

ostream& ZIP::print(ostream& o) {
  for (const auto& c : cities)
    if (c.zip_code==code) {
      o << code << " " << c.city_name;
      return o;
    }
  throw runtime_error("ZIP not found");
}
