#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "gebot.h"
#include "lot.h"
using namespace std;

int main() {
  const vector<string> namen{"Susi","Franz","Marie","Paul","Jane","","John"};
  const vector<int> betraege{1,100,-3,50000,0,267,42,273,10000000,708,90,42,300000,7568,10000001,49,502};

  vector<Gebot> gebote;
  size_t i{0};
  for (const auto& betrag : betraege) {
    try {
      gebote.push_back(Gebot{namen.at(i%namen.size()),betrag});
    }
    catch (runtime_error&) {
      cout<<"Ungueltiges Gebot: "<< namen.at(i%namen.size()) << ", " << betrag <<'\n';;
    }
    ++i;
  }
  gebote.push_back(Gebot{"Susi",273});
  for (const auto& gebot : gebote)
    cout << gebot << '\n';
  cout << Gebot{"Lisa"} << '\n';
  cerr << Gebot{"Lisa"} << '\n';

  for (const auto& gebot : gebote) 
    cout << gebot << ", " << gebote.at(3) << ": " << gebot.selbe_bieterin(gebote.at(3)) << (gebot==gebote.at(3))
         << (gebot<gebote.at(3)) << (gebot>=100) << '\n';

  vector<Lot> lots;
  try {
    lots.push_back(Lot{"Muell",100});
    lots.push_back(Lot{"",100});
  }
  catch (runtime_error&) {
    cout << "Error 1\n";
  }
  try {
    lots.push_back(Lot{"Kohinoor",1000000,Kategorie::Schmuck});
    lots.push_back(Lot{"Schrank",42,Kategorie::Moebel});
    lots.push_back(Lot{"Error",10000001});
  }
  catch (runtime_error&) {
    cout << "Error 2\n";
  }
  try {
    lots.push_back(Lot{"Katze im Sack",10000000});
    lots.push_back(Lot{"Error",0});
  }
  catch (runtime_error&) {
    cout << "Error 3\n";
  }
  try {
    lots.push_back(Lot{"Mona Lisa",50,Kategorie::Kunst});
    lots.push_back(Lot{"Test",1,Kategorie::Sonstiges});
    lots.push_back(Lot{"Error",-42});
  }
  catch (runtime_error&) {
    cout << "Error 4\n";
  }
  for (const auto& lot : lots) 
    cout << lot << ": " << lot.ist_offen() << '\n';
  cout << Lot{"Faust",666,Kategorie::Kunst} << '\n';  
  cerr << Lot{"Faust",666,Kategorie::Kunst} << '\n';  

  for (const auto& gebot : gebote)
    try {
      cout << lots.at(0).bieten(gebot);
    }
    catch(runtime_error&) {
      cout << " selbst unterboten:" << gebot << ' ';
    }
  cout << '\n';
  for (const auto& gebot : gebote)
    try {
      cout << lots.at(1).bieten(gebot);
    }
    catch(runtime_error&) {
      cout << " selbst unterboten:" << gebot << ' ';
    }
  cout << '\n';

  lots.at(2).bieten(Gebot{"Bart",2});
  lots.at(2).bieten(gebote.at(3));
  lots.at(2).bieten(gebote.at(0));
  lots.at(2).bieten(gebote.at(8));
  lots.at(3).bieten(gebote.at(3));
  lots.at(3).bieten(gebote.at(0));
  lots.at(3).bieten(gebote.at(8));
  lots.at(4).bieten(gebote.at(7));
  lots.at(4).bieten(gebote.at(3));
  lots.at(4).bieten(gebote.at(4));
  lots.at(4).bieten(gebote.at(7));
  for (const auto& lot : lots)
    cout << lot << '\n';
 
  //Dekommentieren fuer Erweiterung zuschlag
  /*
  cout << "\nErweiterung zuschlag\n";
  for (const auto& lot : lots)
    try {
      cout << lot.zuschlag() << '\n';
    }
    catch(runtime_error&) {
      cout << "Zuschlag gescheitert\n";
    }
  */

  //Dekommentieren fuer Erweiterung probleme
  /*
  cout << "\nErweiterung probleme\n";
  cout << "Probleme:\n";
  vector<Lot> resultat{Lot::probleme(lots)};
  for (const auto& lot : resultat)
    cout << lot << '\n';
  cout << "Rest:\n";
  for (const auto& lot : lots)
    cout << lot << '\n';
  */

  return 0;  
}

/* Erwartete Ausgabe:
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