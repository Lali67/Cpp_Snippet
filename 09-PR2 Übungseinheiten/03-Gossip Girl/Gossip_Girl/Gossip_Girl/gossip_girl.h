#ifndef GOSSIP_GIRL_H
#define GOSSIP_GIRL_H

#include<iostream>
#include<fstream>
#include<unordered_map>
#include<stdexcept>
#include<algorithm>
#include<numeric>
#include<iterator>
#include<set>
#include<vector>

using namespace std;

enum class Area { Manhattan, Brooklyn, Bronx, Queens, Harlem };

class Gossip_Girl {
    string name;
    int age;
    Area area;
    int fame_level;
    vector<int> accounts;  // PPG,RPG,APG, and more

public:
    Gossip_Girl(string str= "Serena van der Woodson", int i = 20, Area ae = Area::Manhattan, int j = 100, vector<int> iptr= { 10000,200000,555555 }):
        name(str), age(i), area(ae), fame_level(j), accounts(iptr)
    {}
    virtual             ~Gossip_Girl() {};
    string              get_name() const { return name; };
    int                 get_age() const { return age; };
    Area                get_area() const { return area; };
    int                 get_fame_level() const { return fame_level; };
    const vector<int>&  get_accounts() const { return accounts; };

    friend ostream& operator<<(ostream& o, const Gossip_Girl& h) {
        o << h.get_name()<<", "<< h.get_age();
        return o;
    };
    bool operator<(const Gossip_Girl& s) const { return true; };
    bool operator>(const Gossip_Girl& s) const { return true; };
    friend bool operator==(const Gossip_Girl& s, const Gossip_Girl& s2) { return s.get_fame_level() == s2.get_fame_level(); };
    friend bool operator!=(const Gossip_Girl& s, const Gossip_Girl& s2) { return s.get_fame_level() != s2.get_fame_level();; };
    ostream& write(ostream& i) const {
        return i;
    };;
};

string to_string(Area);
#endif

