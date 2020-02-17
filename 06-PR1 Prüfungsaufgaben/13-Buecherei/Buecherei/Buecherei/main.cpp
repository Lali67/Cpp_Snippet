#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include"exemplar.h"
#include"werk.h"

using namespace std;

int main() {
  try {
    Exemplar e{0, Zustand::Unbrauchbar};
    cout << e << '\n';
  }
  catch (runtime_error&) {
    cout << "Error1\n";
  }
  try {
    Exemplar e{1};
    cout << e << '\n';
    cerr << e << '\n';
  }
  catch (runtime_error&) {
    cout << "Error2\n";
  }
  try {
    Exemplar e{1001};
    cout << e << '\n';
  }
  catch (runtime_error&) {
    cout<<"Error3\n";
  }
  try {
    Exemplar e{2, Zustand::Gut};
    cout << e << '\n';
    cerr << e << '\n';
    if (e.verfuegbar()) cout << "verfuegbar\n";
    if (e.entleihen()) cout << "entliehen\n";
    if (e.verfuegbar()) cout << "verfuegbar\n";
    if (e.entleihen()) cout << "entliehen\n";
    cout << e << '\n';
    try {
      e.retournieren(Zustand::Neuwertig);
    }
    catch (runtime_error&) {
      cout << "Zustand kann nicht besser werden!\n";
    }
    try {
      e.retournieren(Zustand::Abgegriffen);
    }
    catch (runtime_error&) {
      cout << "Error4\n";
    }
    cout << e << '\n';
    if (e.entleihen()) cout << "wieder entliehen\n";
    cout << e << '\n';
    try {
      e.retournieren(Zustand::Abgegriffen);
    }
    catch (runtime_error&) {
      cout << "Error5\n";
    }
    cout << e << '\n';
  }
  catch (runtime_error&) {
    cout << "Error6\n";
  }
  try {
    Exemplar e{1000, Zustand::Gut};
    cout << e << '\n';
    cerr << e << '\n';
    if (e.verfuegbar()) cout << "verfuegbar\n";
    if (e.entleihen()) cout << "entliehen\n";
    e.retournieren(Zustand::Unbrauchbar);
    if (e.verfuegbar()) cout << "verfuegbar\n";
    if (e.entleihen()) cout << "entliehen\n";
    cout << e << '\n';
  }
  catch (runtime_error&) {
    cout << "Error7\n";
  }
  
  vector<Werk> bestand;
  try {
    bestand.push_back(Werk{"Adams","Hitchhiker",1979});
    bestand.push_back(Werk{"Musil","",1915});
  }
  catch (runtime_error&) {
    cout << "Error8\n";
  }
  try {
    bestand.push_back(Werk{"Stroustrup","C++",2014});
    bestand.push_back(Werk{"Gutenberg","Bibel",1450});
  }
  catch (runtime_error&) {
    cout << "Error9\n";
  }
  try {
    bestand.push_back(Werk{"Meyers","Effective STL",2001});
    bestand.push_back(Werk{"","Mann ohne Eigenschaften",1915});
  }
  catch (runtime_error&) {
    cout << "Error10\n";
  }
  try {
    bestand.push_back(Werk{"Eisenmenger","Entdecktes",1700});
    bestand.push_back(Werk{"Kagawa","Talon",2017});
    bestand.push_back(Werk{"Martin","GoT 6/11",2018});
  }
  catch (runtime_error&) {
    cout << "Error11\n";
  }
  try {
    bestand.push_back(Werk{"Kafka","Verwandlung",1912});
    bestand.push_back(Werk{"Goldmann","Baukunst",1699});
  }
  catch (runtime_error&) {
    cout << "Error12\n";
  }

  try {
    bestand.at(0).erwerben(1,Zustand::Neuwertig);
    bestand.at(0).erwerben(1,Zustand::Gut);
    bestand.at(0).erwerben(2,Zustand::Abgegriffen);
    bestand.at(0).erwerben(3,Zustand::Unbrauchbar);
  }
  catch (runtime_error&) {
    cout << "Error13\n";
  }
  try {
    bestand.at(1).erwerben(-1,Zustand::Neuwertig);
  }
  catch (runtime_error&) {
    cout << "Error14\n";
  }
  for (int i{ 0 }; i < 4; ++i)
    cout << (bestand.at(0).entleihen()?'+':'-');
  cout << (bestand.at(2).entleihen()?'+':'-');
  cout << '\n';
  for (int i{0}; i<4; ++i)
    try {
      bestand.at(0).retournieren(i,Zustand::Gut);
    }
    catch (runtime_error&) {
      cout << "Failed " << i << '\n';
    }
  cout << '\n';
  
  bestand.at(1).erwerben(2,Zustand::Neuwertig);
  bestand.at(1).erwerben(2,Zustand::Neuwertig);
  bestand.at(1).erwerben(4,Zustand::Neuwertig);
  bestand.at(1).erwerben(3,Zustand::Neuwertig);
  bestand.at(2).erwerben(2,Zustand::Neuwertig);
  bestand.at(2).erwerben(1,Zustand::Neuwertig);
  bestand.at(2).erwerben(1,Zustand::Neuwertig);
  bestand.at(2).erwerben(3,Zustand::Neuwertig);
  bestand.at(5).erwerben(2,Zustand::Neuwertig);
  bestand.at(5).erwerben(1,Zustand::Neuwertig);
  for (const Werk& w : bestand) {
    cout << w << '\n';
    cerr << w << '\n';
  }
  /*
  // Dekommentieren fuer Zusatz erstausgaben
  cout << "\nZusatz erstausgaben\n";
  vector<Werk> result{Werk::erstausgaben(bestand)};
  for (const Werk& w : result)
    cout << w << '\n';

  // Dekommentieren fuer Zusatz aussortieren
  cout << "\nZusatz ausortieren\n";
  bestand.at(0).retournieren(2,Zustand::Unbrauchbar);
  for (int i{0}; i<4; ++i) bestand.at(1).entleihen();
  bestand.at(1).retournieren(1,Zustand::Unbrauchbar);
  bestand.at(1).retournieren(2,Zustand::Unbrauchbar);
  bestand.at(4).erwerben(4,Zustand::Gut);
  bestand.at(4).entleihen();
  bestand.at(4).retournieren(0,Zustand::Unbrauchbar);
  bestand.at(5).entleihen();
  bestand.at(5).retournieren(0,Zustand::Unbrauchbar);
  for (const Werk& w : bestand)
    cout << w << '\n';
  Werk::aussortieren(bestand);
  for (const Werk& w : bestand)
    cout << w << '\n';
	*/
  return 0;
}

/** Erwartete Ausgabe **
Error1
[Auflage: 1, Zustand: neuwertig]
[Auflage: 1, Zustand: neuwertig]
Error3
[Auflage: 2, Zustand: gut]
[Auflage: 2, Zustand: gut]
verfuegbar
entliehen
[Auflage: 2, Zustand: gut, verliehen]
Zustand kann nicht besser werden!
[Auflage: 2, Zustand: abgegriffen]
wieder entliehen
[Auflage: 2, Zustand: abgegriffen, verliehen]
[Auflage: 2, Zustand: abgegriffen]
[Auflage: 1000, Zustand: gut]
[Auflage: 1000, Zustand: gut]
verfuegbar
entliehen
[Auflage: 1000, Zustand: unbrauchbar]
Error8
Error9
Error10
Error11
Error12
Error13
Error14
+++--
Failed 2
Failed 3

[Adams, Hitchhiker, 1979 {[Auflage: 1, Zustand: gut], [Auflage: 1, Zustand: gut], [Auflage: 2, Zustand: abgegriffen, verliehen]}]
[Adams, Hitchhiker, 1979 {[Auflage: 1, Zustand: gut], [Auflage: 1, Zustand: gut], [Auflage: 2, Zustand: abgegriffen, verliehen]}]
[Stroustrup, C++, 2014 {[Auflage: 2, Zustand: neuwertig], [Auflage: 2, Zustand: neuwertig], [Auflage: 4, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]
[Stroustrup, C++, 2014 {[Auflage: 2, Zustand: neuwertig], [Auflage: 2, Zustand: neuwertig], [Auflage: 4, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]
[Meyers, Effective STL, 2001 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]
[Meyers, Effective STL, 2001 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]
[Eisenmenger, Entdecktes, 1700 {}]
[Eisenmenger, Entdecktes, 1700 {}]
[Kagawa, Talon, 2017 {}]
[Kagawa, Talon, 2017 {}]
[Kafka, Verwandlung, 1912 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig]}]
[Kafka, Verwandlung, 1912 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig]}]

Zusatz erstausgaben
[Adams, Hitchhiker, 1979 {[Auflage: 1, Zustand: gut], [Auflage: 1, Zustand: gut], [Auflage: 2, Zustand: abgegriffen, verliehen]}]
[Meyers, Effective STL, 2001 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]
[Kafka, Verwandlung, 1912 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig]}]

Zusatz ausortieren
[Adams, Hitchhiker, 1979 {[Auflage: 1, Zustand: gut], [Auflage: 1, Zustand: gut], [Auflage: 2, Zustand: unbrauchbar]}]
[Stroustrup, C++, 2014 {[Auflage: 2, Zustand: neuwertig, verliehen], [Auflage: 2, Zustand: unbrauchbar], [Auflage: 4, Zustand: unbrauchbar], [Auflage: 3, Zustand: neuwertig, verliehen]}]
[Meyers, Effective STL, 2001 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]
[Eisenmenger, Entdecktes, 1700 {}]
[Kagawa, Talon, 2017 {[Auflage: 4, Zustand: unbrauchbar]}]
[Kafka, Verwandlung, 1912 {[Auflage: 2, Zustand: unbrauchbar], [Auflage: 1, Zustand: neuwertig]}]
[Adams, Hitchhiker, 1979 {[Auflage: 1, Zustand: gut], [Auflage: 1, Zustand: gut]}]
[Stroustrup, C++, 2014 {[Auflage: 2, Zustand: neuwertig, verliehen], [Auflage: 3, Zustand: neuwertig, verliehen]}]
[Meyers, Effective STL, 2001 {[Auflage: 2, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 1, Zustand: neuwertig], [Auflage: 3, Zustand: neuwertig]}]
[Eisenmenger, Entdecktes, 1700 {}]
[Kagawa, Talon, 2017 {}]
[Kafka, Verwandlung, 1912 {[Auflage: 1, Zustand: neuwertig]}]
*/