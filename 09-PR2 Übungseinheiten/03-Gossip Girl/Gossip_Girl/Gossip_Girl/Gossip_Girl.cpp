#include "vector.h"
#include "tasks.h"
#include "gossip_girl.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main() {
    cout << boolalpha;
    const Vector<string> v_str{ "A"s,"B"s,"C"s };
    Vector<int> vi{ 4,2,1,5,4,5,4 };
    
    cout << v_str << endl;
    cout << vi << endl;
    
      Vector<Gossip_Girl> v;
      cout << v.empty() << endl;
      cout << v << endl;
      cerr << v << endl;
      
      // Objects


      const Gossip_Girl o0;
      const Gossip_Girl o1{"Blair Waldorf",21,Area::Manhattan,9,{70000,100000,200000}};
      const Gossip_Girl o2{"Dan Humphrey",22,Area::Brooklyn,8,{5000,3000}};
      const Gossip_Girl o3{"Vanessa Abrams",21,Area::Brooklyn,8,{50000,3000}};
      const Gossip_Girl o4{"Charles Bass",20,Area::Bronx,10,{20000,100000}};
      const Gossip_Girl o5{"Bart Bass",50,Area::Bronx,10,{200000,100000}};
      const Gossip_Girl o6{"Lily van der Woodson",51,Area::Queens,34,{12345,67890}};
      const Gossip_Girl o7{"Rufus Humphrey",45,Area::Queens,3,{6000,67890}};
      const Gossip_Girl o8{"Nate Archibald",15,Area::Manhattan,8,{100000,3123123,31232}};
      const Gossip_Girl o9{"Kristen Bell",45,Area::Harlem,7,{12312313,12333}};
     {
        Vector<Gossip_Girl> x(0);
        x.insert(x.end(),o0);
        x.insert(x.begin(),o1);
        x.push_back(o4);
        x.push_back(o5);
        x.insert(x.end(),o7);
        x.insert(x.end(),o9);
        x.push_back(o6);
        x.insert(x.end(),o8);
        x.insert(x.end(),o3);
        x.insert(x.end(),o2);
        const Vector<Gossip_Girl> tmp{x};
        v = tmp;
      }
      for(const auto& x : v)
        cout << x << endl;
      /*
      auto it = ++v.begin();
      const Gossip_Girl oo{*it};
      v.erase(++v.begin());
      v.insert(v.begin(),oo);

      cout << v.size() << endl;
      cout << v << endl;

      */

      //Task 1
      /*
      {
        const Vector<string> gnames{get_names(v)};

        cout << "Names: " << gnames << endl;
      }
      {
        const Vector<string> gnames{get_names({})};

        cout << "Names: " << gnames << endl;
      }
      */
      //Task 2
      /*
      try{
        Gossip_Girl x {longest_name(Vector<Gossip_Girl>{o7,o9})};
        cout << "Gossip_Girl: " << x <<  endl;
      } catch( runtime_error& e){
        cout << "Err1" << endl;
      }
      cout << longest_name(v) << endl;
      cout << longest_name({o6,o2,o8}) << endl;
      */
      //Task 3
      /*
      {
        std::string x{max_str(v)};
        cout << "Max: " << x << endl;
      }
      {
        try{
          std::string x{max_str({})};
          cout << "Max: " << x << endl;
        }catch(runtime_error&){
          cout << "Error 2" << endl;
        }
      }
      {
        std::string x{max_str({o7,o6})};
        cout << "Max: " << x << endl;
      }
      {
        try{
          std::string x{max_str({o2,o3})};
          cout << "Max: " << x << endl;
        }catch(runtime_error&){
          cout << "Error 3" << endl;
        }
      }
      */

      //Task 4 
      /*
      {
        cout << "Vector<int>: ";
        auto it_1{vi.begin_x()};
        for(;it_1!=vi.end_x();++it_1)
          cout << *it_1 << " ";
        cout << endl;
      }

      {
        cout << "Vector<int>: ";
        auto it_1{vi.begin_x()};
        while(it_1!=vi.end_x())
          cout << *(it_1++) << " ";
        cout << endl;
      }

      {
        cout << "Vector<int>: ";
        Vector<int> vi;
        auto it_1{vi.begin_x()};
        for(;it_1!=vi.end_x();++it_1)
          cout << *it_1 << " ";
        cout << endl;
      }
      {
        cout << "Vector<Gossip_Girl>: ";
        auto it_1{v.begin_x()};
        for(;it_1!=v.end_x();++it_1)
          cout << "[" << it_1->get_name() << "], ";
        cout << endl;
      }
      */
      //Task 5 
      /*
      {
        cout << "Vector<int>: ";
        auto it_1{vi.begin_y()};
        for(;it_1!=vi.end_y();++it_1)
          cout << *it_1 << " ";
        cout << "At End? " << (it_1==vi.end_y()) << endl;
      }
      {
        cout << "Vector<int>: ";
        Vector<int> vi;
        auto it_1{vi.begin_y()};
        for(;it_1!=vi.end_y();++it_1)
          cout << *it_1 << " ";
        ++it_1;
        cout << "At End? " << (it_1==vi.end_y()) << endl;
      }
      {
        cout << "Vector<Gossip_Girl>: ";
        auto it_1{v.begin_y()};
        for(;it_1!=v.end_y();++it_1)
          cout << "[" << it_1->get_name() << "] ";
        cout << endl;
        ++it_1;
        cout << "At End? " << (it_1==v.end_y()) << endl;
      }
      */
      //Task 6
      /*
      const Vector<int> civ{vi};
      const Vector<Gossip_Girl> cv{v};
      {
        for(auto x{civ.begin_z()};x!=civ.end();++x)
          cout << *x << " ";
        cout << endl;
      }
      {
        for(auto x{cv.begin_z()};x!=cv.end();++x)
          cout << "[" << x->get_name() << "] ";
        cout << endl;
      }
      {
        const Vector<Gossip_Girl> cv{o4,o5,o6};
        for(auto x{cv.begin_z()};x!=cv.end();++x)
          cout << "[" << x->get_name() << "] ";
        cout << endl;
      }
      */
    return 0;
}
