#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"patient.h"
#include"doctor.h"

using namespace std;

int main(){
try {
  cout << "Class Patient:\n";
  try {
    Patient p{""};
    cout << "test 1 " << p << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 1\n";
  }
  try {
    Patient t{"Mary",{Field::Onc, Field::Neuro, Field::Gast, Field::Neuro, Field::Card}};
    cout << "test 2 " << t << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 2\n";
  }

  const vector<Patient> vp{{"Mary",{Field::Onc, Field::Gast, Field::Neuro, Field::Card}},
                           {"Peter",{Field::Gast, Field::Orth, Field::Neph}},{"Paul",{Field::Opht}},{"Anne"},
                           {"Olivia",{Field::Gast, Field::Pul}},{"Ken",{Field::Pul}},
                           {"Lisa",{Field::Neph, Field::Onc}}, {"Sue",{Field::Orth, Field::Card, Field::Neuro}},
                           {"Jim",{Field::Card,Field::Orth, Field::Gast, Field::Neph}}, {"John",{Field::Pul}}};
  for (auto p : vp) { 
    cerr << p << '\n';
    cout << p;
    cout << ' ' << p.count_symptoms_of({Field::Gast, Field::Neph, Field::Orth});
    cout << ' ' << p.count_symptoms_of({Field::Pul, Field::Neuro, Field::Card});
    cout << ' ' << p.diagnose({Field::Gast, Field::Neph, Field::Orth}) << '\n';
    cout << p << '\n';
  }
  cout << '\n';
  
  cout << "\nClass Doctor:\n";
  try {
    Doctor d{"",{Field::Pul}};
    cout << "test 3 " << d << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 3\n";
  }
  try {
    Doctor d{"Linda", {}};
    cout << "test 4 " << d << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 4\n";
  }
  try {
    Doctor d{"Eric", {Field::Card, Field::Opht, Field::Pul, Field::Card}, vp};
    cout << "test 5 " << d << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 5\n";
  }
  try {
    Doctor d{"Eric", {Field::Opht, Field::Card, Field::Card, Field::Pul}, vp};
    cout << "test 6 " << d << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 6\n";
  }
  const vector<Doctor> vd{{"Eric", {Field::Opht, Field::Pul, Field::Card}, vp},
                         {"Linda", {Field::Pul}, {vp.at(0), vp.at(1), vp.at(2), vp.at(7), vp.at(6), vp.at(3)}},
                         {"Olga", {Field::Card, Field::Neuro, Field::Onc, Field::Opht, Field::Orth, Field::Neph,
                                   Field::Gast, Field::Pul}, vp},
                         {"Herbert", {Field::Card, Field::Neuro, Field::Onc, Field::Opht, Field::Orth, Field::Neph,
                                   Field::Gast, Field::Pul}, {vp.begin()+4, vp.end()}}};
  for (const auto& d : vd) {
    cout << '\n' << d << '\n';
    cout << Doctor{"Dr", {Field::Onc}, d.cannot_treat()} << '\n';
    cerr << d << '\n';
  }
  
// Dekommentieren fuer Zusatz next
/*
  cout << "\nAdditional task next\n";
  Doctor dr{vd.at(0)};
  for (int i{0}; i<5; ++i)
    cout << Doctor{"Dr", {Field::Onc}, dr.next()} << '\n';
  cout << dr << '\n';
  dr = vd.at(1);
  cout << '\n' << Doctor{"Dr", {Field::Onc}, dr.next()} << '\n';
  cout << dr << '\n';
*/

// Dekommentieren fuer Zusatz reorder
/*
  cout << "\nAdditional task reorder\n";
  cout << '\n';
  for (auto d : vd) {
    d.reorder();
    cout << d << '\n';
  }
  auto check{Doctor{"Juri", {Field::Card, Field::Neuro, Field::Neph}, 
                 {{"Sylvia"}, {"Ben", {Field::Neuro, Field::Onc}}, {"Fran", {Field::Neph, Field::Card}}, 
                 {"Fred", {Field::Card, Field::Neuro, Field::Neph}}, {"Wilma"}, 
                 {"Barney", {Field::Onc, Field::Card, Field::Orth}},
                 {"Betty", {Field::Onc, Field::Orth, Field::Card, Field::Neph, Field::Pul, Field::Neuro}}}}};
  check.reorder();
  cout << check << '\n';
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
Class Patient:
catch 1
catch 2
[Mary {Oncology, Gastrology, Neurology, Cardiology}]
[Mary {Oncology, Gastrology, Neurology, Cardiology}] 1 2 1
[Mary {Oncology, Gastrology, Neurology, Cardiology, Nephrology, Orthopedia}]
[Peter {Gastrology, Orthopedia, Nephrology}]
[Peter {Gastrology, Orthopedia, Nephrology}] 3 0 0
[Peter {Gastrology, Orthopedia, Nephrology}]
[Paul {Ophthalmology}]
[Paul {Ophthalmology}] 0 0 1
[Paul {Ophthalmology, Gastrology, Nephrology, Orthopedia}]
[Anne]
[Anne] 0 0 1
[Anne {Gastrology, Nephrology, Orthopedia}]
[Olivia {Gastrology, Pulmonology}]
[Olivia {Gastrology, Pulmonology}] 1 1 1
[Olivia {Gastrology, Pulmonology, Nephrology, Orthopedia}]
[Ken {Pulmonology}]
[Ken {Pulmonology}] 0 1 1
[Ken {Pulmonology, Gastrology, Nephrology, Orthopedia}]
[Lisa {Nephrology, Oncology}]
[Lisa {Nephrology, Oncology}] 1 0 1
[Lisa {Nephrology, Oncology, Gastrology, Orthopedia}]
[Sue {Orthopedia, Cardiology, Neurology}]
[Sue {Orthopedia, Cardiology, Neurology}] 1 2 1
[Sue {Orthopedia, Cardiology, Neurology, Gastrology, Nephrology}]
[Jim {Cardiology, Orthopedia, Gastrology, Nephrology}]
[Jim {Cardiology, Orthopedia, Gastrology, Nephrology}] 3 1 0
[Jim {Cardiology, Orthopedia, Gastrology, Nephrology}]
[John {Pulmonology}]
[John {Pulmonology}] 0 1 1
[John {Pulmonology, Gastrology, Nephrology, Orthopedia}]


Class Doctor:
catch 3
catch 4
catch 5
catch 6

[Eric, {Ophthalmology, Pulmonology, Cardiology}, {[Mary {Oncology, Gastrology, Neurology, Cardiology}], [Peter {Gastrology, Orthopedia, Nephrology}], [Paul {Ophthalmology}], [Anne], [Olivia {Gastrology, Pulmonology}], [Ken {Pulmonology}], [Lisa {Nephrology, Oncology}], [Sue {Orthopedia, Cardiology, Neurology}], [Jim {Cardiology, Orthopedia, Gastrology, Nephrology}], [John {Pulmonology}]}]
[Dr, {Oncology}, {[Peter {Gastrology, Orthopedia, Nephrology}], [Anne], [Lisa {Nephrology, Oncology}]}]
[Eric, {Ophthalmology, Pulmonology, Cardiology}, {[Mary {Oncology, Gastrology, Neurology, Cardiology}], [Peter {Gastrology, Orthopedia, Nephrology}], [Paul {Ophthalmology}], [Anne], [Olivia {Gastrology, Pulmonology}], [Ken {Pulmonology}], [Lisa {Nephrology, Oncology}], [Sue {Orthopedia, Cardiology, Neurology}], [Jim {Cardiology, Orthopedia, Gastrology, Nephrology}], [John {Pulmonology}]}]

[Linda, {Pulmonology}, {[Mary {Oncology, Gastrology, Neurology, Cardiology}], [Peter {Gastrology, Orthopedia, Nephrology}], [Paul {Ophthalmology}], [Sue {Orthopedia, Cardiology, Neurology}], [Lisa {Nephrology, Oncology}], [Anne]}]
[Dr, {Oncology}, {[Mary {Oncology, Gastrology, Neurology, Cardiology}], [Peter {Gastrology, Orthopedia, Nephrology}], [Paul {Ophthalmology}], [Sue {Orthopedia, Cardiology, Neurology}], [Lisa {Nephrology, Oncology}], [Anne]}]
[Linda, {Pulmonology}, {[Mary {Oncology, Gastrology, Neurology, Cardiology}], [Peter {Gastrology, Orthopedia, Nephrology}], [Paul {Ophthalmology}], [Sue {Orthopedia, Cardiology, Neurology}], [Lisa {Nephrology, Oncology}], [Anne]}]

[Olga, {Cardiology, Neurology, Oncology, Ophthalmology, Orthopedia, Nephrology, Gastrology, Pulmonology}, {[Mary {Oncology, Gastrology, Neurology, Cardiology}], [Peter {Gastrology, Orthopedia, Nephrology}], [Paul {Ophthalmology}], [Anne], [Olivia {Gastrology, Pulmonology}], [Ken {Pulmonology}], [Lisa {Nephrology, Oncology}], [Sue {Orthopedia, Cardiology, Neurology}], [Jim {Cardiology, Orthopedia, Gastrology, Nephrology}], [John {Pulmonology}]}]
[Dr, {Oncology}, {[Anne]}]
[Olga, {Cardiology, Neurology, Oncology, Ophthalmology, Orthopedia, Nephrology, Gastrology, Pulmonology}, {[Mary {Oncology, Gastrology, Neurology, Cardiology}], [Peter {Gastrology, Orthopedia, Nephrology}], [Paul {Ophthalmology}], [Anne], [Olivia {Gastrology, Pulmonology}], [Ken {Pulmonology}], [Lisa {Nephrology, Oncology}], [Sue {Orthopedia, Cardiology, Neurology}], [Jim {Cardiology, Orthopedia, Gastrology, Nephrology}], [John {Pulmonology}]}]

[Herbert, {Cardiology, Neurology, Oncology, Ophthalmology, Orthopedia, Nephrology, Gastrology, Pulmonology}, {[Olivia {Gastrology, Pulmonology}], [Ken {Pulmonology}], [Lisa {Nephrology, Oncology}], [Sue {Orthopedia, Cardiology, Neurology}], [Jim {Cardiology, Orthopedia, Gastrology, Nephrology}], [John {Pulmonology}]}]
[Dr, {Oncology}, {}]
[Herbert, {Cardiology, Neurology, Oncology, Ophthalmology, Orthopedia, Nephrology, Gastrology, Pulmonology}, {[Olivia {Gastrology, Pulmonology}], [Ken {Pulmonology}], [Lisa {Nephrology, Oncology}], [Sue {Orthopedia, Cardiology, Neurology}], [Jim {Cardiology, Orthopedia, Gastrology, Nephrology}], [John {Pulmonology}]}]

Additional task next
[Dr, {Oncology}, {}]
[Dr, {Oncology}, {[Peter {Gastrology, Orthopedia, Nephrology}]}]
[Dr, {Oncology}, {[Anne]}]
[Dr, {Oncology}, {}]
[Dr, {Oncology}, {[Lisa {Nephrology, Oncology}]}]
[Eric, {Ophthalmology, Pulmonology, Cardiology}, {[Jim {Cardiology, Orthopedia, Gastrology, Nephrology}], [John {Pulmonology}]}]

[Dr, {Oncology}, {[Mary {Oncology, Gastrology, Neurology, Cardiology}], [Peter {Gastrology, Orthopedia, Nephrology}], [Paul {Ophthalmology}], [Sue {Orthopedia, Cardiology, Neurology}], [Lisa {Nephrology, Oncology}], [Anne]}]
[Linda, {Pulmonology}, {}]

Additional task reorder

[Eric, {Ophthalmology, Pulmonology, Cardiology}, {[Peter {Gastrology, Orthopedia, Nephrology}], [Anne], [Lisa {Nephrology, Oncology}], [Mary {Oncology, Gastrology, Neurology, Cardiology}], [Paul {Ophthalmology}], [Olivia {Gastrology, Pulmonology}], [Ken {Pulmonology}], [Sue {Orthopedia, Cardiology, Neurology}], [Jim {Cardiology, Orthopedia, Gastrology, Nephrology}], [John {Pulmonology}]}]
[Linda, {Pulmonology}, {[Mary {Oncology, Gastrology, Neurology, Cardiology}], [Peter {Gastrology, Orthopedia, Nephrology}], [Paul {Ophthalmology}], [Sue {Orthopedia, Cardiology, Neurology}], [Lisa {Nephrology, Oncology}], [Anne]}]
[Olga, {Cardiology, Neurology, Oncology, Ophthalmology, Orthopedia, Nephrology, Gastrology, Pulmonology}, {[Anne], [Paul {Ophthalmology}], [Ken {Pulmonology}], [John {Pulmonology}], [Olivia {Gastrology, Pulmonology}], [Lisa {Nephrology, Oncology}], [Peter {Gastrology, Orthopedia, Nephrology}], [Sue {Orthopedia, Cardiology, Neurology}], [Mary {Oncology, Gastrology, Neurology, Cardiology}], [Jim {Cardiology, Orthopedia, Gastrology, Nephrology}]}]
[Herbert, {Cardiology, Neurology, Oncology, Ophthalmology, Orthopedia, Nephrology, Gastrology, Pulmonology}, {[Ken {Pulmonology}], [John {Pulmonology}], [Olivia {Gastrology, Pulmonology}], [Lisa {Nephrology, Oncology}], [Sue {Orthopedia, Cardiology, Neurology}], [Jim {Cardiology, Orthopedia, Gastrology, Nephrology}]}]
[Juri, {Cardiology, Neurology, Nephrology}, {[Sylvia], [Wilma], [Ben {Neurology, Oncology}], [Barney {Oncology, Cardiology, Orthopedia}], [Fran {Nephrology, Cardiology}], [Fred {Cardiology, Neurology, Nephrology}], [Betty {Oncology, Orthopedia, Cardiology, Nephrology, Pulmonology, Neurology}]}]
*/
