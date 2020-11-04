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
    Gossip_Girl(string = "Serena van der Woodson", int = 20, Area = Area::Manhattan, int = 100, vector<int> = { 10000,200000,555555 });
    virtual ~Gossip_Girl();
    string get_name() const;
    int get_age() const;
    Area get_area() const;
    int get_fame_level() const;
    const vector<int>& get_accounts() const;
    friend ostream& operator<<(ostream& o, const Gossip_Girl& h);
    bool operator<(const Gossip_Girl& s) const;
    bool operator>(const Gossip_Girl& s) const;
    friend bool operator==(const Gossip_Girl& s, const Gossip_Girl& s2);
    friend bool operator!=(const Gossip_Girl& s, const Gossip_Girl& s2);
    ostream& write(ostream&) const;
};

string to_string(Area);
#endif

