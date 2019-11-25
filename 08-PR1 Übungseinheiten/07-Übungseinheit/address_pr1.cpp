#include<iostream>
#include<string>
#include<vector>
#include"city.h"
#include"zip.h"
#include"address.h"
using namespace std;

vector<string> split(string str, char delim = ',') {
  vector<string> ret;
  string current;
  for (const auto& c : str)
    if (c == delim) {
      ret.push_back(current);
      current.clear();
    }
    else
      current.push_back(c);
  ret.push_back(current);
  return ret;
}

bool check_data(vector<string> data, size_t size) {
  if (data.size() != size)
    return false;
  for (const auto& field : data)
    if (field.empty())
      return false;
  return true;
}

void read_data(vector<Address>& addresses) {
  string line;
  while (getline(cin,line)) {
    vector<string> data{split(line)};
    if (!check_data(data, 5))
      throw runtime_error("illegal input format (address)");
    addresses.push_back(Address{data.at(0),data.at(1),data.at(2),data.at(3),{data.at(4)}});
  }

  if (addresses.empty())
    throw runtime_error("illegal input format (file)");
}

int main() {
  vector<Address> addresses;

  try {
    read_data(addresses);

    cout << "\nAddresses\n\n";
    for (auto& address : addresses) { //const intentionally not used
      address.print();
      cout << "\n\n";
    }

    cout << "\nGrouped Addresses\n\n";
    vector<vector<Address>> grouped_addresses{group(addresses)};
    for (auto& addresses : grouped_addresses) { //const intentionally not used
      for (auto& address: addresses) { //const intentionally not used
         address.print();
         cout << "\n\n";
      }
      cout << '\n';
    }
  }
  catch(runtime_error& e) {
    cerr << "Error: " << e.what() << '\n';
    cerr << "Program terminated!\n";
  }
  return 0;
}