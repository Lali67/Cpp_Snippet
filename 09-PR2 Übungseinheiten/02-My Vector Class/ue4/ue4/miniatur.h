#ifndef MINIATUR_H
#define MINIATUR_H
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>


enum class Fraktion{Tyraniden,SM,CSM,Orks,AstraMilitarum,GreyKnights,Demons,Harlequins,
                    ThousandSons,AdeptusMechanicus,Craftworlds,Drukhari};

std::string to_s(Fraktion);

class Miniatur{
  std::string               name;
  Fraktion                  f;
  int                       points;
  std::vector<int>          stats;  // HP,BS,WS

  public:
    Miniatur(std::string="Hive_Tyrant", Fraktion=Fraktion::Tyraniden, int=180, std::vector<int> = {4,3,2});

    void                    add_points(int);
    const std::string&      get_name() const;
    Fraktion                get_fraktion() const;
    int                     get_points() const;
    const std::vector<int>& get_stats() const;
    std::ostream&           print(std::ostream&) const;
    std::ostream&           write(std::ostream&) const;
    std::istream&           read(std::istream&);
    virtual ~Miniatur() = default;
};

std::ostream& operator<<(std::ostream& o,const Miniatur& s);
std::istream& operator>>(std::istream& o,Miniatur& s);

#endif
