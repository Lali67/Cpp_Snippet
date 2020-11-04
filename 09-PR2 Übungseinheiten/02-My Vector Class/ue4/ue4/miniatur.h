#ifndef MINIATUR_H
#define MINIATUR_H
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

enum class Fraktion {
    Tyraniden, SM, CSM, Orks, AstraMilitarum, GreyKnights, Demons, Harlequins,
    ThousandSons, AdeptusMechanicus, Craftworlds, Drukhari
};

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
    std::ostream&               to_s(Fraktion type, std::ostream& out) const;
    std::ostream&               print(std::ostream& out) const;
    std::ostream&               write(std::ostream& out) const;
    std::istream&               read(std::istream& in);

    bool operator == (const Miniatur& rhs) { 
        return points == rhs.get_points(); 
    }
    bool operator != (const Miniatur& rhs) { 
        return points != rhs.get_points(); 
    }
    friend bool operator == (const Miniatur& lhs, const Miniatur& rhs) {
        return lhs.get_points() == rhs.get_points();
    }
    friend bool operator != (const Miniatur& lhs, const Miniatur& rhs) { 
        return lhs.get_points() != rhs.get_points();
    }
    
    friend std::ostream& operator << (std::ostream& o, const Miniatur& s) {
        //[Name: Genestealer, Fraktion : Tyraniden, Punkte : 395]
        o << '[' << "Name: " << s.get_name() << ", Fraktion : ";  s.to_s(s.get_fraktion(), o);
        switch (s.get_fraktion()) {
        case Fraktion::Tyraniden:			o << "Tyraniden"; break;
        case Fraktion::SM:					o << "SM"; break;
        case Fraktion::CSM:					o << "CSM"; break;
        case Fraktion::Orks:				o << "Orks"; break;
        case Fraktion::AstraMilitarum:		o << "AstraMilitarum"; break;
        case Fraktion::GreyKnights:			o << "GreyKnights"; break;
        case Fraktion::Demons:				o << "Demons"; break;
        case Fraktion::Harlequins:			out << "Harlequins"; break;
        case Fraktion::ThousandSons:		out << "ThousandSons"; break;
        case Fraktion::AdeptusMechanicus:	out << "AdeptusMechanicus"; break;
        case Fraktion::Craftworlds:			out << "Craftworlds"; break;
        case Fraktion::Drukhari:			out << "Drukhari"; break;
        }
        o << ", Punkte : " << s.get_points() << ']';
        return o;
    };
    friend std::istream& operator >>(std::istream& o, Miniatur& s);
    virtual ~Miniatur() = default;
};

class Spezial_Miniatur : public Miniatur {

    public:
        Spezial_Miniatur(std::string aName = "Hive_Tyrant", Fraktion aFraktion = Fraktion::Tyraniden, int aPoint = 180):
            Miniatur(aName, static_cast<Fraktion>(aFraktion), aPoint)
        {
        };
        std::ostream& print(std::ostream& o) const;
};


#endif
