#include<iostream>
#include<unordered_map>
#include<stdexcept>
#include<algorithm>
#include<numeric>
#include<iterator>
#include"vector.h"
#include"miniatur.h"

#include <set>

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
  
  Vector<Spezial_Miniatur> vsm {Spezial_Miniatur{"Genestealer",Fraktion::Tyraniden,395}, 
                                Spezial_Miniatur{"Burna Boy",Fraktion::Orks,240}, 
                                Spezial_Miniatur{"Tankbusta",Fraktion::Orks,252}, 
                                Spezial_Miniatur{"Inceptors", Fraktion::SM,403},
                                Spezial_Miniatur(),
                                Spezial_Miniatur{"Kabalite Warrior",Fraktion::Drukhari,324} };
  Vector<Miniatur> v_back,v_in;
  
  copy(vsm.begin(), vsm.end(), std::back_inserter(v_back));
  auto v_in_it = v_in.begin();
  copy(vsm.begin(), vsm.end(), std::inserter(v_in,v_in_it));
  
  cout << vsm << '\n';
  cout << v_back << '\n';
  cout << v_in << '\n';
  
  // What is the difference between v_in and v_back?
    //---- There are no difference.
  auto pos = vs.begin();
  transform(vsm.begin(), vsm.end(), std::inserter(vs,++pos), [] (const Spezial_Miniatur& a) {return a.get_name();});
  for_each(vs.begin(), vs.end(), [] (const string& s) {cout<<s<<'\n';});
  cout<<'\n';
 
  // Why does the following statement work for vi, but not v_in?
  cout << *max_element(vi.begin(), vi.end());
  //cout << *max_element(v_in.begin(), v_in.end());
  cout << '\n';

  // What is needed in Miniatur, so that the following statement works for Spezial_Miniatur?
    //----  define operator overloading: bool operator < ()
  cout << *max_element(vsm.begin(), vsm.end()) << '\n';

  // Print the smallest even number of vector vi
  cout << *min_element(vi.begin(), vi.end(), [](const int& el, const int& smallest) {
                                                return (el % 2 == 0 && el < smallest) || smallest % 2 != 0;
                                                }) << '\n';

  // Print the element with the most points of vector vsm.
  cout << *max_element(vsm.begin(), vsm.end()) << '\n';

  // Print the number of Ork Miniaturen of vsm without using a loop.
  cout << count_if(vsm.begin(), vsm.end(), [](const Spezial_Miniatur& sm) 
                                            { return sm.get_fraktion() == Fraktion::Orks; }) << '\n';

  // Copy only elements of vsm into a new Vector if it has a 'B' or 'b' in its name
  Vector<Spezial_Miniatur> vsm_copy_item{};
  copy_if(vsm.begin(), vsm.end(), std::back_inserter(vsm_copy_item), [](const Spezial_Miniatur& sm) {
      return sm.get_name().find_first_of("Bb") != string::npos;
      });
  cout << vsm_copy_item << '\n';

  set<Spezial_Miniatur> set1{ vsm.begin(), vsm.end() };
  cout << "Sorting by Points: " << '\n';
  for (const auto& el : set1)
      cout << el << '\n';

  set<Spezial_Miniatur, NameCompare_Spezial_Miniatur> set2{ vsm.begin(), vsm.end() };
  cout << "Sorting by Name: " << '\n';
  for (const auto& el : set2)
      cout << el << '\n';

  // Define Vector<Miniatur*> pointer
  Vector<Miniatur*> vsm_ptr;
  transform(vsm.begin(), vsm.end(), std::back_inserter(vsm_ptr), [](Spezial_Miniatur& m) {
      return &m;
      });

  cout << "Elements by Vector<Miniatur*> Pointer: " << '\n';
  for (const auto& item : vsm_ptr)
      cout << *item << '\n';


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
