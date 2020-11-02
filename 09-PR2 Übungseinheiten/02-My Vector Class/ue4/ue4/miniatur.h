#ifndef MINIATUR_H
#define MINIATUR_H
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>


enum class Fraktion {
    Tyraniden, SM, CSM, Orks, AstraMilitarum, GreyKnights, Demons, Harlequins,
    ThousandSons, AdeptusMechanicus, Craftworlds, Drukhari
};

std::string to_s(Fraktion);

class Miniatur {
    std::string               name;
    Fraktion                  f;
    int                       points;
    std::vector<int>          stats;  // HP,BS,WS

public:
    Miniatur(std::string aName = "Hive_Tyrant", Fraktion aFraktion = Fraktion::Tyraniden, int aPoints = 180, 
                std::vector<int> aStats = { 4,3,2 });

    void                        add_points(int pt_num);
    const std::string&          get_name() const;
    Fraktion                    get_fraktion() const;
    int                         get_points() const;
    const std::vector<int>&     get_stats() const;

    std::ostream& print(std::ostream& out) const;
    std::ostream& write(std::ostream& out) const;
    std::istream& read(std::istream& in);

    virtual ~Miniatur() = default;
};
/*
class Spezial_Miniatur : public Miniatur {
private:
    int nr;
    int counter;
public:
    Spezial_Miniatur(std::string aName = "Hive_Tyrant", Fraktion aFraktion = Fraktion::Tyraniden, int aPoint = 180):
        Miniatur(aName, static_cast<Fraktion>(aFraktion), aPoint)
    {
        nr = 0; counter = 0;
    };
    //std::ostream& print(std::ostream& o) const override;
};

std::ostream& operator <<(std::ostream& o, const Miniatur& s);
std::istream& operator>>(std::istream& o, Miniatur& s);
*/

#endif
