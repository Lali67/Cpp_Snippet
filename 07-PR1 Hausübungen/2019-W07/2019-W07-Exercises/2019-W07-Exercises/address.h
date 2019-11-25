#ifndef ADDRESS_H
#define ADDRESS_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct City {
    string  zip_code;
    string  city_name;
};

struct ZIP {
    inline const static vector<City> cities{ 
        {"1010","Wien"},{"1020","Wien"},{"1080","Wien"},{"1090","Wien"},{"1110","Wien"},
        {"1100","Wien"},{"1300","Mannswoerth"},{"4099","Wiesen"},{"8051","Graz"},{"8036","Graz"},
        {"8047","Hart bei Graz"},{"05020","Salzburg"},{"5026","Salzburg"} };

    string code;

    bool check() {
        for (const auto& c : cities)
            if (c.zip_code == code)
                return true;
        return false;
    };

    ostream& print(ostream& o) {
        for (const auto& c : cities)
            if (c.zip_code == code) {
                o << code << " " << c.city_name;
                return o;
            }
        throw runtime_error("ZIP not found");
    }
};

struct Address {
    string  first_name;
    string  surname;
    string  road;
    string  street_number;
    ZIP     zip;

    ostream& print(ostream& = cout);
};

vector<vector<Address>> group(const vector<Address>&);
void read_data(vector<Address>& addresses);

#endif //ADDRESS_H