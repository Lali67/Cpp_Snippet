#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"package.h"
#include"conveyor.h"

using namespace std;

int main(){
try {
  cout << "Class Package:\n";
  try {
    Package p{4};
    cout << "test 1 " << p << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 1\n";
  }
  try {
    Package p{20001, Region::US};
    cout << "test 2 " << p << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 2\n";
  }

  const vector<Package> vp{{5}, {20000, Region::OTHER}, {250, Region::US}, {10001, Region::AFR},
                           {720, Region::SA}, {12750, Region::US}, {280, Region::EU}, {832},
                           {15000, Region::US}, {10000, Region::AUS}};
  for (auto p : vp) { 
    cerr << p << '\n';
    cout << p << ' ' << p.destination_in({Region::AFR, Region::OTHER}) <<
                        p.destination_in({Region::US}) <<
                        p.destination_in({Region::AUS, Region::EU}) << '\n';
  }
  cout << '\n';
  
  cout << "\nClass Conveyor:\n";
  try {
    Conveyor c{{}};
    cout << "test 3 " << c << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 3\n";
  }
  try {
    Conveyor c{{Region::AFR, Region::US}, vp};
    cout << "test 4 " << c << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 4\n";
  }
  try {
    Conveyor c{{Region::EU, Region::OTHER, Region::SA, Region::AFR, Region::US}, vp};
    cout << "test 5 " << c << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 5\n";
  }

  vector<Conveyor> vc{{{Region::EU}}, {{Region::US, Region::AUS}, {}}, {{Region::AFR, Region::SA, Region::OTHER}}};
  for (auto& c : vc) {
    cout << Conveyor{{Region::EU, Region::US, Region::AUS, Region::AFR, Region::SA, Region::OTHER}, 
                      c.add_packages(vp)} << '\n';
  }
  const vector<Conveyor> cvc{vc};
  for (const auto& c : cvc) {
    cout << c << '\n';
  }
  cout << cvc.at(0).overlap(cvc.at(0)) << cvc.at(1).overlap(cvc.at(2)) << cvc.at(2).overlap(cvc.at(0)) << '\n';
  Conveyor c1{{Region::AUS, Region::SA}};
  cout << c1.overlap(cvc.at(0)) << c1.overlap(cvc.at(1)) << c1.overlap(cvc.at(2)) << '\n';

  
// Dekommentieren fuer Zusatz clear_regions
/*
  cout << "\nAdditional task clear_regions\n";
  for (auto c : cvc) {
    cout << c.clear_regions().size() << ' ';
  }
  cout << '\n';
  for (auto c : cvc) {
    Conveyor c1{{Region::EU, Region::US, Region::AUS, Region::AFR, Region::SA, Region::OTHER}, 
                      c.add_packages(vp)};
    cout << Conveyor{c1.clear_regions()} << '\n';
  }
*/

// Dekommentieren fuer Zusatz dispatch
/*
  cout << "\nAdditional task dispatch\n";
  for (size_t i{0}; i<vc.size(); ++i) {
    Conveyor c{{Region::EU, Region::US, Region::AUS, Region::AFR, Region::SA, Region::OTHER}, vp};
    c.dispatch(vc.at(i), vc.at((i+1)%3));
    cout << c << '\n' << vc.at(i) << '\n' << vc.at((i+1)%3) << '\n';
  }
  vector<Conveyor> t{{{Region::EU}}, {{Region::US}}, {{Region::AUS}}, {{Region::SA}}, {{Region::OTHER}}};
  vc.at(0).dispatch(t.at(0), t.at(1));
  vc.at(1).dispatch(t.at(1), t.at(2));
  vc.at(2).dispatch(t.at(3), t.at(4));
  for (const auto& c : vc)
    cout << c << '\n';
  for (const auto& c : t)
    cout << c << '\n';  
  try {
    Conveyor check{{Region::EU}}, a{{Region::EU, Region::AUS}}, b{{Region::US, Region::AUS}};
    check.dispatch(a, b);
    cout << "test 6\n";
  } catch (runtime_error& e) {
    cout << "catch 6\n";
  }
*/
}
catch (exception& e) {
  cout << "Unexpected exception: " << e.what() << '\n';
}
catch (...) {
  cout << "Non standard exception thrown!";
}
return 0;
}

/* Erwarteter Output
Class Package:
catch 1
catch 2
[EU 5 g]
[EU 5 g] 001
[Other 20000 g heavy]
[Other 20000 g heavy] 100
[USA 250 g]
[USA 250 g] 010
[Africa 10001 g heavy]
[Africa 10001 g heavy] 100
[South America 720 g]
[South America 720 g] 000
[USA 12750 g heavy]
[USA 12750 g heavy] 010
[EU 280 g]
[EU 280 g] 001
[EU 832 g]
[EU 832 g] 001
[USA 15000 g heavy]
[USA 15000 g heavy] 010
[Australia 10000 g]
[Australia 10000 g] 001


Class Conveyor:
catch 3
catch 4
catch 5
[{EU, USA, Australia, Africa, South America, Other}, {[Other 20000 g heavy], [USA 250 g], [Africa 10001 g heavy], [South America 720 g], [USA 12750 g heavy], [USA 15000 g heavy], [Australia 10000 g]}]
[{EU, USA, Australia, Africa, South America, Other}, {[EU 5 g], [Other 20000 g heavy], [Africa 10001 g heavy], [South America 720 g], [EU 280 g], [EU 832 g]}]
[{EU, USA, Australia, Africa, South America, Other}, {[EU 5 g], [USA 250 g], [USA 12750 g heavy], [EU 280 g], [EU 832 g], [USA 15000 g heavy], [Australia 10000 g]}]
[{EU}, {[EU 5 g], [EU 280 g], [EU 832 g]}]
[{USA, Australia}, {[USA 250 g], [USA 12750 g heavy], [USA 15000 g heavy], [Australia 10000 g]}]
[{Africa, South America, Other}, {[Other 20000 g heavy], [Africa 10001 g heavy], [South America 720 g]}]
100
011

Additional task clear_regions
0 0 0
[{EU}, {}]
[{USA, Australia}, {}]
[{Africa, South America, Other}, {}]

Additional task dispatch
[{EU, USA, Australia, Africa, South America, Other}, {[Other 20000 g heavy], [Africa 10001 g heavy], [South America 720 g]}]
[{EU}, {[EU 5 g], [EU 280 g], [EU 832 g], [EU 5 g], [EU 280 g], [EU 832 g]}]
[{USA, Australia}, {[USA 250 g], [USA 12750 g heavy], [USA 15000 g heavy], [Australia 10000 g], [USA 250 g], [USA 12750 g heavy], [USA 15000 g heavy], [Australia 10000 g]}]
[{EU, USA, Australia, Africa, South America, Other}, {[EU 5 g], [EU 280 g], [EU 832 g]}]
[{USA, Australia}, {[USA 250 g], [USA 12750 g heavy], [USA 15000 g heavy], [Australia 10000 g], [USA 250 g], [USA 12750 g heavy], [USA 15000 g heavy], [Australia 10000 g], [USA 250 g], [USA 12750 g heavy], [USA 15000 g heavy], [Australia 10000 g]}]
[{Africa, South America, Other}, {[Other 20000 g heavy], [Africa 10001 g heavy], [South America 720 g], [Other 20000 g heavy], [Africa 10001 g heavy], [South America 720 g]}]
[{EU, USA, Australia, Africa, South America, Other}, {[USA 250 g], [USA 12750 g heavy], [USA 15000 g heavy], [Australia 10000 g]}]
[{Africa, South America, Other}, {[Other 20000 g heavy], [Africa 10001 g heavy], [South America 720 g], [Other 20000 g heavy], [Africa 10001 g heavy], [South America 720 g], [Other 20000 g heavy], [Africa 10001 g heavy], [South America 720 g]}]
[{EU}, {[EU 5 g], [EU 280 g], [EU 832 g], [EU 5 g], [EU 280 g], [EU 832 g], [EU 5 g], [EU 280 g], [EU 832 g]}]
[{EU}, {}]
[{USA, Australia}, {}]
[{Africa, South America, Other}, {[Africa 10001 g heavy], [Africa 10001 g heavy], [Africa 10001 g heavy]}]
[{EU}, {[EU 5 g], [EU 280 g], [EU 832 g], [EU 5 g], [EU 280 g], [EU 832 g], [EU 5 g], [EU 280 g], [EU 832 g]}]
[{USA}, {[USA 250 g], [USA 12750 g heavy], [USA 15000 g heavy], [USA 250 g], [USA 12750 g heavy], [USA 15000 g heavy], [USA 250 g], [USA 12750 g heavy], [USA 15000 g heavy]}]
[{Australia}, {[Australia 10000 g], [Australia 10000 g], [Australia 10000 g]}]
[{South America}, {[South America 720 g], [South America 720 g], [South America 720 g]}]
[{Other}, {[Other 20000 g heavy], [Other 20000 g heavy], [Other 20000 g heavy]}]
catch 6
*/