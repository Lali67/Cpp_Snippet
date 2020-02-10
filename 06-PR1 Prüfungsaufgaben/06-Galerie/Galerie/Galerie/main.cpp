#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"gemaelde.h"
#include "galerie.h"
using namespace std;

int main() {
  vector<Gemaelde> gl;
  try {
    gl.push_back({"Venus",2000});
    gl.push_back({"",2000});
    gl.push_back({"Venus",2000});
  }
  catch (runtime_error&) {
    cout << "catch 1" << '\n';
  }
  try {
    gl.push_back({"Maya",3000});
    gl.push_back({"Lisa",10000});
    gl.push_back({"Maya",10001});
    gl.push_back({"Lisa",10000});
  }
  catch (runtime_error&) {
    cout << "catch 2" << '\n';
  }
  try {
    gl.push_back({"Elefanten",1000, Stil::Surreal});
    gl.push_back({"Lisa Simpson",100, Stil::Surreal});
    gl.push_back({"Bart Simpson",99, Stil::Surreal});
    gl.push_back({"Elefanten",10000, Stil::Surreal});
  }
  catch (runtime_error&) {
    cout << "catch 3" << '\n';
  }
  try {
    gl.push_back({"Abendmahl",4832, Stil::Klassisch});
    gl.push_back({"Goldhelm",100});
    gl.push_back({"Sonnenblumen",9999});
    gl.push_back({"Schrei",10000, Stil::Abstrakt});
  }
  catch (runtime_error&) {
    cout << "catch 4" << '\n';
  }
  try {
    gl.at(0).add_interessent("Sylvia");
    gl.at(0).add_interessent("Franz");
    gl.at(0).add_interessent("");
    gl.at(0).add_interessent("Maria");
  }
  catch (runtime_error&) {
    cout << "catch 5" << '\n';
  }
  try {
    gl.at(0).add_interessent("");
    gl.at(0).add_interessent("Maria");
  }
  catch (runtime_error&) {
    cout << "catch 6" << '\n';
  }
  try {
    gl.at(0).add_interessent("Maria");
    gl.at(0).add_interessent("");
    gl.at(0).add_interessent("Marie");
  }
  catch (runtime_error&) {
    cout << "catch 7" << '\n';
  }
  try {
    gl.at(1).add_interessent("Maria");
    gl.at(1).add_interessent("Sylvia");
    gl.at(1).add_interessent("Franz");
    gl.at(8).add_interessent("Franz");
    gl.at(8).add_interessent("Gustav");
  }
  catch (runtime_error&) {
    cout << "catch 8" << '\n';
  }
  for (const auto& g : gl)
    cout << g << " " << g.get_name() << " " << g.get_wert() << " " << g.hat_interessent() << '\n';
  cerr << gl.at(1) << '\n';

  try {
    Galerie g1{"Impressionen2018",gl};
    Galerie g2{"",gl};
    cout << Galerie{"Impressionen2018",gl};
  }
  catch (runtime_error&) {
    cout << "catch 8" << '\n';
  }
  try {
    Galerie g1{"Werte",gl};
    Galerie g3{"Werte",{}};
    cout << Galerie{"Werte",gl};
  }
  catch (runtime_error&) {
    cout << "catch 9" << '\n';
  }

  Galerie g{"Impressionen2018",gl};
  cout << g << '\n';
  cerr << g << '\n';
  cout << g.gesamtwert() << '\n';
  gl.at(2).add_interessent("Franz");
  gl.at(2).add_interessent("Maria");
  gl.at(2).add_interessent("Sylvia");
  gl.at(3).add_interessent("Susi");
  gl.at(3).add_interessent("Franz");
  gl.at(5).add_interessent("Franz");
  gl.at(5).add_interessent("Susi");
  Galerie gal{"Ersatz",gl};
  cout << gal << '\n';
  cerr << gal << '\n';

  //Dekommentieren fuer Zusatz print_interessenten
  /*
  cout << "\nZusatz print_interessenten\n";
  gal.print_interessenten(cout) << '\n';
  gal.print_interessenten(cerr) << '\n';
  Galerie{"Fade Werke",{{"Haus", 110}, {"Boote", 240}}}.print_interessenten(cerr) << '\n';
  */

  //Dekommentieren fuer Zusatz ersetzen
  /*
  cout << "\nZusatz ersetzen\n";
  gal.ersetzen(Stil::Klassisch,"Franz","Susi");
  cout << gal << '\n';
  gal.ersetzen(Stil::Klassisch,"Susi","Sylvia");
  cout << gal << '\n';
  */

  return 0;
}

/* Erwarteter Output:
Ungueltiges Gebot: Marie, -3
Ungueltiges Gebot: Jane, 0
Ungueltiges Gebot: , 267
Ungueltiges Gebot: , 300000
Ungueltiges Gebot: Susi, 10000001
[Susi: 1 Euro]
[Franz: 100 Euro]
[Paul: 50000 Euro]
[John: 42 Euro]
[Susi: 273 Euro]
[Franz: 10000000 Euro]
[Marie: 708 Euro]
[Paul: 90 Euro]
[Jane: 42 Euro]
[John: 7568 Euro]
[Franz: 49 Euro]
[Marie: 502 Euro]
[Susi: 273 Euro]
[Lisa: 100 Euro]
[Lisa: 100 Euro]
[Susi: 1 Euro], [John: 42 Euro]: 0010
[Franz: 100 Euro], [John: 42 Euro]: 0001
[Paul: 50000 Euro], [John: 42 Euro]: 0001
[John: 42 Euro], [John: 42 Euro]: 1100
[Susi: 273 Euro], [John: 42 Euro]: 0001
[Franz: 10000000 Euro], [John: 42 Euro]: 0001
[Marie: 708 Euro], [John: 42 Euro]: 0001
[Paul: 90 Euro], [John: 42 Euro]: 0000
[Jane: 42 Euro], [John: 42 Euro]: 0100
[John: 7568 Euro], [John: 42 Euro]: 1001
[Franz: 49 Euro], [John: 42 Euro]: 0000
[Marie: 502 Euro], [John: 42 Euro]: 0001
[Susi: 273 Euro], [John: 42 Euro]: 0001
Error 1
Error 2
Error 3
Error 4
[Muell: 100 Euro, Sonstiges {}]: 0
[Kohinoor: 1000000 Euro, Schmuck {}]: 1
[Schrank: 42 Euro, Moebel {}]: 0
[Katze im Sack: 10000000 Euro, Sonstiges {}]: 0
[Mona Lisa: 50 Euro, Kunst {}]: 1
[Test: 1 Euro, Sonstiges {}]: 0
[Faust: 666 Euro, Kunst {}]
[Faust: 666 Euro, Kunst {}]
1111111 selbst unterboten:[Paul: 90 Euro] 11 selbst unterboten:[Franz: 49 Euro]  selbst unterboten:[Marie: 502 Euro] 1
0000010000000
[Muell: 100 Euro, Sonstiges {[Susi: 1 Euro], [Franz: 100 Euro], [Paul: 50000 Euro], [John: 42 Euro], [Susi: 273 Euro], [Franz: 10000000 Euro], [Marie: 708 Euro], [Jane: 42 Euro], [John: 7568 Euro], [Susi: 273 Euro]}]
[Kohinoor: 1000000 Euro, Schmuck {[Franz: 10000000 Euro]}]
[Schrank: 42 Euro, Moebel {[Bart: 2 Euro], [John: 42 Euro], [Susi: 1 Euro], [Jane: 42 Euro]}]
[Katze im Sack: 10000000 Euro, Sonstiges {[John: 42 Euro], [Susi: 1 Euro], [Jane: 42 Euro]}]
[Mona Lisa: 50 Euro, Kunst {[Paul: 90 Euro], [Susi: 273 Euro], [Paul: 90 Euro]}]
[Test: 1 Euro, Sonstiges {}]

Erweiterung zuschlag
[Franz: 10000000 Euro]
[Franz: 10000000 Euro]
[John: 42 Euro]
Zuschlag gescheitert
[Susi: 273 Euro]
Zuschlag gescheitert

Erweiterung probleme
Probleme:
[Katze im Sack: 10000000 Euro, Sonstiges {[John: 42 Euro], [Susi: 1 Euro], [Jane: 42 Euro]}]
[Test: 1 Euro, Sonstiges {}]
Rest:
[Muell: 100 Euro, Sonstiges {[Susi: 1 Euro], [Franz: 100 Euro], [Paul: 50000 Euro], [John: 42 Euro], [Susi: 273 Euro], [Franz: 10000000 Euro], [Marie: 708 Euro], [Jane: 42 Euro], [John: 7568 Euro], [Susi: 273 Euro]}]
[Kohinoor: 1000000 Euro, Schmuck {[Franz: 10000000 Euro]}]
[Schrank: 42 Euro, Moebel {[Bart: 2 Euro], [John: 42 Euro], [Susi: 1 Euro], [Jane: 42 Euro]}]
[Mona Lisa: 50 Euro, Kunst {[Paul: 90 Euro], [Susi: 273 Euro], [Paul: 90 Euro]}]
*/