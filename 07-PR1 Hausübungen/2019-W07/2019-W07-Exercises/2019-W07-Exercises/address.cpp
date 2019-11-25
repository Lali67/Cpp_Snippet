#include<iostream>
#include<string>
#include<vector>
#include <fstream>
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
        bool found{ false };
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
    std::ifstream file("address_input_pr1.txt");

    while (getline(file, line)) {
        vector<string> data{ split(line) };
        if (!check_data(data, 5))
            throw runtime_error("illegal input format (address)");
        addresses.push_back(Address{ data.at(0),data.at(1),data.at(2),data.at(3),{data.at(4)} });
    }

    if (addresses.empty())
        throw runtime_error("illegal input format (file)");
}