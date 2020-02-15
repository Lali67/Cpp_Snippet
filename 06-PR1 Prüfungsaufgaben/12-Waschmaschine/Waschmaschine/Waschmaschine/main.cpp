#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"kleidst.h"
#include"waschm.h"

using namespace std;

int main()
{
  try {
    cout<<KleidSt{"",200}<<'\n';
  }
  catch (runtime_error&) {
    cout<<"A\n";
  }
  try {
    cout<<KleidSt{"Bluse",150}<<'\n';
  }
  catch (runtime_error&) {
    cout<<"B\n";
  }
  try {
    cout<<KleidSt{"Hose",5000}<<'\n';
  }
  catch (runtime_error&) {
    cout<<"C\n";
  }
  try {
    cout<<KleidSt{"Socke",-5}<<'\n';
  }
  catch (runtime_error&) {
    cout<<"D\n";
  }
  try {
    cout<<KleidSt{"Rock",0}<<'\n';
  }
  catch (runtime_error&) {
    cout<<"E\n";
  }
  try {
    cout<<WaschM{-3}<<'\n';
  }
  catch (runtime_error&) {
    cout<<"F\n";
  }
  try {
    cout<<WaschM{50}<<'\n';
  }
  catch (runtime_error&) {
    cout<<"F\n";
  }
  try {
    cout<<WaschM{50000}<<'\n';
  }
  catch (runtime_error&) {
    cout<<"F\n";
  }

  vector<Programm> test_programm{Programm::Koch, Programm::Normal, Programm::Bunt, Programm::Fein};
  vector<KleidSt> kleider{{"Bluse",200},{"Bluse",120,Programm::Fein},{"Hose",1500,Programm::Koch}, {"Socke",25,Programm::Bunt}};
  for (size_t i{0}; i<test_programm.size(); ++i)
    cout << kleider.at(0).vertraeglich(test_programm.at(i));
  cout << '\n';
  
  WaschM w{4000};
  w.zuladen(kleider);
  try {
    w.waschen(Programm::Bunt);
  }
  catch (runtime_error&) {
    cout<<"nicht gewaschen 1\n";
  }
  cout<<w<<'\n';
  cerr<<w<<'\n';
  try {
    w.waschen(Programm::Fein);
  }
  catch (runtime_error&) {
    cout<<"nicht gewaschen 2\n";
  }
  cout<<w<<'\n';
  w.zuladen(kleider);
  w.zuladen(kleider);
  w.zuladen(kleider);
  try {
    w.waschen(Programm::Fein);
  }
  catch (runtime_error&) {
    cout<<"nicht gewaschen 3\n";
  }
  cout<<w<<'\n';
  WaschM w1{5535};
  w1.zuladen(kleider);
  w1.zuladen(kleider);
  w1.zuladen(kleider);
  try {
    w1.waschen(Programm::Fein);
  }
  catch (runtime_error&) {
    cout<<"nicht gewaschen 4\n";
  }
  cout<<w1<<'\n';
  w1.zuladen(kleider);
  w1.zuladen(kleider);
  w1.zuladen(kleider);
  w1.zuladen({{"Taschentuch",1}});
  try {
    w1.waschen(Programm::Fein);
  }
  catch (runtime_error&) {
    cout<<"nicht gewaschen 5\n";
  }
  cout<<w1<<'\n';

  //Dekommentieren für Zusatz programme
  /*
  cout<<'\n';
  WaschM wa{30000};
  cout<<wa.programme()<<' ';
  wa.zuladen({{"Socke",15,Programm::Bunt}});
  cout<<wa.programme()<<' ';
  wa.zuladen({{"Bluse",250,Programm::Fein}});
  cout<<wa.programme()<<' ';
  wa.zuladen({{"Socke",15,Programm::Bunt}});
  cout<<wa.programme()<<' ';
  wa.zuladen(kleider);
  cout<<wa.programme()<<'\n';
  */

  //Dekommentieren für Zusatz aussortieren
  /*
  WaschM w2{5000};
  WaschM w3{10000};
  cout<<'\n';
  w2.zuladen({{"Socke",15,Programm::Bunt}});
  w2.zuladen({{"Bluse",250,Programm::Fein}});
  w3.zuladen(w2.aussortieren(Programm::Koch));
  cout<<w3<<'\n';
  cout<<w2<<'\n';
  w2.zuladen(kleider);
  w2.zuladen(kleider);
  w3.zuladen(w2.aussortieren(Programm::Fein));
  cout<<w3<<'\n';
  cout<<w2<<'\n';
  w3.zuladen(w2.aussortieren(Programm::Normal));
  cout<<w3<<'\n';
  cout<<w2<<'\n';
  w3.zuladen(w2.aussortieren(Programm::Koch));
  cout<<w3<<'\n';
  cout<<w2<<'\n';
  */  
  
  return 0;
}

/** Erwarteter Output **
A
[Bluse, 150 g, Normalwäsche]
C
D
E
F
F
[50000 g {}]
0111
nicht gewaschen 1
[4000 g {[Bluse, 200 g, Normalwäsche], [Bluse, 120 g, Feinwäsche], [Hose, 1500 g, Kochwäsche], [Socke, 25 g, Buntwäsche]}]
[4000 g {[Bluse, 200 g, Normalwäsche], [Bluse, 120 g, Feinwäsche], [Hose, 1500 g, Kochwäsche], [Socke, 25 g, Buntwäsche]}]
[4000 g {}]
nicht gewaschen 3
[4000 g {[Bluse, 200 g, Normalwäsche], [Bluse, 120 g, Feinwäsche], [Hose, 1500 g, Kochwäsche], [Socke, 25 g, Buntwäsche], [Bluse, 200 g, Normalwäsche], [Bluse, 120 g, Feinwäsche], [Hose, 1500 g, Kochwäsche], [Socke, 25 g, Buntwäsche], [Bluse, 200 g, Normalwäsche], [Bluse, 120 g, Feinwäsche], [Hose, 1500 g, Kochwäsche], [Socke, 25 g, Buntwäsche]}]
[5535 g {}]
nicht gewaschen 5
[5535 g {[Bluse, 200 g, Normalwäsche], [Bluse, 120 g, Feinwäsche], [Hose, 1500 g, Kochwäsche], [Socke, 25 g, Buntwäsche], [Bluse, 200 g, Normalwäsche], [Bluse, 120 g, Feinwäsche], [Hose, 1500 g, Kochwäsche], [Socke, 25 g, Buntwäsche], [Bluse, 200 g, Normalwäsche], [Bluse, 120 g, Feinwäsche], [Hose, 1500 g, Kochwäsche], [Socke, 25 g, Buntwäsche], [Taschentuch, 1 g, Normalwäsche]}]

0 1 2 2 4

[10000 g {[Socke, 15 g, Buntwäsche], [Bluse, 250 g, Feinwäsche]}]
[5000 g {}]
[10000 g {[Socke, 15 g, Buntwäsche], [Bluse, 250 g, Feinwäsche]}]
[5000 g {[Bluse, 200 g, Normalwäsche], [Bluse, 120 g, Feinwäsche], [Hose, 1500 g, Kochwäsche], [Socke, 25 g, Buntwäsche], [Bluse, 200 g, Normalwäsche], [Bluse, 120 g, Feinwäsche], [Hose, 1500 g, Kochwäsche], [Socke, 25 g, Buntwäsche]}]
[10000 g {[Socke, 15 g, Buntwäsche], [Bluse, 250 g, Feinwäsche], [Bluse, 120 g, Feinwäsche], [Socke, 25 g, Buntwäsche], [Bluse, 120 g, Feinwäsche], [Socke, 25 g, Buntwäsche]}]
[5000 g {[Bluse, 200 g, Normalwäsche], [Hose, 1500 g, Kochwäsche], [Bluse, 200 g, Normalwäsche], [Hose, 1500 g, Kochwäsche]}]
[10000 g {[Socke, 15 g, Buntwäsche], [Bluse, 250 g, Feinwäsche], [Bluse, 120 g, Feinwäsche], [Socke, 25 g, Buntwäsche], [Bluse, 120 g, Feinwäsche], [Socke, 25 g, Buntwäsche], [Bluse, 200 g, Normalwäsche], [Bluse, 200 g, Normalwäsche]}]
[5000 g {[Hose, 1500 g, Kochwäsche], [Hose, 1500 g, Kochwäsche]}]
*/