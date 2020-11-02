#include<iostream>
#include<unordered_map>
#include<stdexcept>
#include<algorithm>
#include<numeric>
#include<iterator>
#include"vector.h"
#include"miniatur.h"
using namespace std;



int main() {
  Vector<int> tmp;
  {
    const Vector<int> v {1,2,3,4,5};
    const Vector<int> cpy{v};
    tmp = cpy;
  }
  const Vector<int> vi{tmp}; 
  cout << accumulate(vi.begin(), vi.end(), 0, [] (int sum, int elem) {return sum+elem;})<<'\n';

  {
    Vector<string> vss(0);
    for(size_t i{0};i<20;++i)
      vss.push_back("a");
  }
  
  {
    Vector<string> vss{}; 
    for(size_t i{0};i<20;++i)
      vss.push_back("a");
  }
  
  Vector<string> vs {"a","bb","ccc"};
  vs.erase(find(vs.begin(), vs.end(), "bb"));
  for (auto& s : vs) s+="z";
  for (const auto& s : vs) cout<<s<<' ';
  cout<<'\n';

  // Interesting Stuff starts here
  using Spezial_Miniatur = Miniatur;
  Vector<Spezial_Miniatur> vsm {Spezial_Miniatur{"Genestealer",Fraktion::Tyraniden,395}, 
                                Spezial_Miniatur{"Burna Boy",Fraktion::Orks,240}, 
                                Spezial_Miniatur{"Tankbusta",Fraktion::Orks,252}, 
                                Spezial_Miniatur{"Inceptors", Fraktion::SM,403},
                                Spezial_Miniatur(),Spezial_Miniatur{"Kabalite Warrior",Fraktion::Drukhari,324}};
  Vector<Miniatur> v_back,v_in;
  
  copy(vsm.begin(), vsm.end(), std::back_inserter(v_back));
  auto v_in_it = v_in.begin();
  copy(vsm.begin(), vsm.end(), std::inserter(v_in,v_in_it));
  
  cout << vsm << '\n';
  cout << v_back << '\n';
  cout << v_in << '\n';
  
  // What is the difference between v_in and v_back?
  //  --- There is no difference

/*  auto pos = vs.begin();
  transform(vsm.begin(), vsm.end(), std::inserter(vs,++pos), [] (const Spezial_Miniatur& a) {return a.get_name();});
  for_each(vs.begin(), vs.end(), [] (const string& s) {cout<<s<<'\n';});
  cout<<'\n';
  /*
  // Why does the following statement work for vi, but not v_in?
  cout << *max_element(vi.begin(), vi.end());
  // What is needed in Miniatur, so that the following statement works for Spezial_Miniatur?
  //cout << *max_element(vsm.begin(), vsm.end());

  // Print the smallest even number of vector vi


  // Print the element with the most points of vector vsm.


  // Print the number of Ork Miniaturen of vsm without using a loop.


  // Copy only elements of vsm into a new Vector if it has a 'B' or 'b' in its name
*/
  cout<<'\n';
  return 0;
}

/* Expected Output:
15
az cccz
[[Name: Genestealer, Fraktion: Tyraniden, Punkte: 395], *Nr: 1*, [Name: Burna Boy, Fraktion: Orks, Punkte: 240], *Nr: 2*, [Name: Tankbusta, Fraktion: Orks, Punkte: 252], *Nr: 3*, [Name: Inceptors, Fraktion: Space_Marines, Punkte: 403], *Nr: 4*, [Name: Hive_Tyrant, Fraktion: Tyraniden, Punkte: 180], *Nr: 5*, [Name: Kabalite Warrior, Fraktion: Drukhari, Punkte: 324], *Nr: 6*]
[[Name: Genestealer, Fraktion: Tyraniden, Punkte: 395], [Name: Burna Boy, Fraktion: Orks, Punkte: 240], [Name: Tankbusta, Fraktion: Orks, Punkte: 252], [Name: Inceptors, Fraktion: Space_Marines, Punkte: 403], [Name: Hive_Tyrant, Fraktion: Tyraniden, Punkte: 180], [Name: Kabalite Warrior, Fraktion: Drukhari, Punkte: 324]]
[[Name: Genestealer, Fraktion: Tyraniden, Punkte: 395], [Name: Burna Boy, Fraktion: Orks, Punkte: 240], [Name: Tankbusta, Fraktion: Orks, Punkte: 252], [Name: Inceptors, Fraktion: Space_Marines, Punkte: 403], [Name: Hive_Tyrant, Fraktion: Tyraniden, Punkte: 180], [Name: Kabalite Warrior, Fraktion: Drukhari, Punkte: 324]]
az
Genestealer
Burna Boy
Tankbusta
Inceptors
Hive_Tyrant
Kabalite Warrior
cccz

5
*/
