#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"Spieler.h"
#include"Mannschaft.h"

using namespace std;

int main() {
	const Spieler stegen{ "Stegen",60,Position::Tor };
	const Spieler cillessen{ "Cillessen",10 };
	const Spieler umtiti{ "Umtiti",60,Position::Abwehr };
	const Spieler alba{ "Alba",60,Position::Abwehr };
	const Spieler digne{ "Digne",15,Position::Abwehr };
	const Spieler roberto{ "Roberto",55,Position::Abwehr };
	const Spieler paulinho{ "Paulinho",40,Position::Mitte };
	const Spieler gomes{ "Gomes",15,Position::Mitte };
	const Spieler rakitic{ "Rakitic",50,Position::Mitte };
	const Spieler coutinho{ "Coutinho",100,Position::Mitte };
	const Spieler messi{ "Messi",180,Position::Sturm };
	const Spieler suarez{ "Suarez",70,Position::Sturm };
	const Spieler elhaddadi{ "El Haddadi",12,Position::Sturm };
	
	cout << "SPIELER\n";
	cout << messi << '\n';
	cerr << messi << '\n';
	cout << cillessen << '\n';

	try {
		Spieler s{ "",60 };
		cout << s << '\n';
	}
	catch (runtime_error&) {
		cout << "Error 1\n";
	}
	try {
		Spieler s{ "Mesis",9 };
		cout << s << '\n';
	}
	catch (runtime_error&) {
		cout << "Error 2\n";
	}
	try {
		Spieler s{ "Mesis",500 };
		cout << s << '\n';
	}
	catch (runtime_error&) {
		cout << "Error 3\n";
	}
	try {
		Spieler s{ "Mesis",501 };
		cout << s << '\n';
	}
	catch (runtime_error&) {
		cout << "Error 4\n";
	}
	
	cout << (messi == messi) << (messi == alba) << (messi == Spieler{ "Test",180,Position::Sturm });
	cout << (messi == Spieler{ "Messi",18 }) << (messi == Spieler{ "Messis",180,Position::Sturm });
	cout << '\n';
	
	cout << "\nMANNSCHAFT\n";
	try {
		cout << Mannschaft{ "Kapfenberg" } << '\n';
		cerr << Mannschaft{ "Kapfenberg" } << '\n';
		cout << Mannschaft{ "Simmering" } << '\n';
		cout << Mannschaft{ "Brutal",{coutinho} } << '\n';
		cerr << Mannschaft{ "Brutal", {coutinho} } << '\n';
		cerr << Mannschaft{ "Sturm", {messi,cillessen} } << '\n';
		Mannschaft m{ "" };
		cout << m << '\n';
	}
	catch (runtime_error&) {
		cout << "Error 5\n";
	}
	try {
		Mannschaft m{ "Liga Nord",{messi,coutinho,cillessen,coutinho,elhaddadi} };
		cout << m << '\n';
	}
	catch (runtime_error&) {
		cout << "Error 6\n";
	}
	
	Mannschaft barcelona{ "Barcelona",{coutinho,cillessen,suarez} };
	
	const Mannschaft h{ "Hoppala",barcelona.engagieren({messi,cillessen,elhaddadi,coutinho,messi}) };
	cout << h << '\n';
	cerr << h << '\n';
	barcelona.engagieren({});
	cout << barcelona << '\n';
	
	//Dekommentieren fuer Zusatz aufstellung
	/*
	cout << "\nZusatz 10 Punkte\n";
	try {
	  cout << barcelona.aufstellung() << '\n';
	  cout << barcelona << '\n';
	}
	catch (runtime_error&) {
	  cout << "Error 7\n";
	}
	try {
	  barcelona.engagieren({umtiti,alba,digne,gomes,paulinho});
	  cout << barcelona.aufstellung() << '\n';
	  cout << barcelona << '\n';
	}
	catch (runtime_error&) {
	  cout << "Error 8\n";
	}
	try {
	  Mannschaft cpy{barcelona};
	  cpy.engagieren({});
	  cpy.engagieren({roberto});
	  cout << cpy.aufstellung() << '\n';
	  cpy = barcelona;
	  cpy.engagieren({stegen});
	  cout << cpy.aufstellung() << '\n';
	  cout << barcelona << '\n';
	}
	catch (runtime_error&) {
	  cout << "Error 9\n";
	}
	try {
	  Mannschaft cpy{barcelona};
	  cpy.engagieren({rakitic,roberto});
	  cout << cpy.aufstellung() << '\n';
	  cout << barcelona << '\n';
	}
	catch (runtime_error&) {
	  cout << "Error 10\n";
	}
	*/

	//Dekommentieren fuer Zusatz entlassen
	/*
	cout << "\nZusatz 15 Punkte\n";
	vector<Spieler> result;
	barcelona.engagieren({umtiti,alba,digne,gomes,paulinho,roberto,stegen});
	result = barcelona.entlassen({});
	cout << barcelona << '\n';
	for (const auto& s : result)
	  cout << s << " ";
	cout << '\n';
	result = barcelona.entlassen({Position::Tor});
	cout << barcelona << '\n';
	for (const auto& s : result)
	  cout << s << " ";
	cout << '\n';
	result = barcelona.entlassen({Position::Tor,Position::Sturm,Position::Sturm,Position::Tor});
	cout << barcelona << '\n';
	for (const auto& s : result)
	  cout << s << " ";
	cout << '\n';
	Mannschaft cpy_barcelona{barcelona};
	result = barcelona.entlassen({Position::Sturm,Position::Abwehr});
	cout << barcelona << '\n';
	for (const auto& s : result)
	  cout << s << " ";
	cout << '\n';
	result = barcelona.entlassen({Position::Sturm,Position::Abwehr,Position::Mitte});
	cout << barcelona << '\n';
	for (const auto& s : result)
	  cout << s << " ";
	cout << '\n';
	result = cpy_barcelona.entlassen({Position::Sturm,Position::Abwehr,Position::Mitte});
	cout << cpy_barcelona << '\n';
	for (const auto& s : result)
	  cout << s << " ";
	cout << '\n';
	*/

	return 0;
}

/* Erwartete Ausgabe
SPIELER
[Messi, 180 Mio Euro, Sturm]
[Messi, 180 Mio Euro, Sturm]
[Cillessen, 10 Mio Euro, Tor]
Error 1
Error 2
[Mesis, 500 Mio Euro, Tor]
Error 4
10010

MANNSCHAFT
[Kapfenberg, {}]
[Kapfenberg, {}]
[Simmering, {}]
[Brutal, {[Coutinho, 100 Mio Euro, Mitte]}]
[Brutal, {[Coutinho, 100 Mio Euro, Mitte]}]
[Sturm, {[Messi, 180 Mio Euro, Sturm], [Cillessen, 10 Mio Euro, Tor]}]
Error 5
Error 6
[Hoppala, {[Cillessen, 10 Mio Euro, Tor], [Coutinho, 100 Mio Euro, Mitte], [Messi, 180 Mio Euro, Sturm]}]
[Hoppala, {[Cillessen, 10 Mio Euro, Tor], [Coutinho, 100 Mio Euro, Mitte], [Messi, 180 Mio Euro, Sturm]}]
[Barcelona, {[Coutinho, 100 Mio Euro, Mitte], [Cillessen, 10 Mio Euro, Tor], [Suarez, 70 Mio Euro, Sturm], [Messi, 180 Mio Euro, Sturm], [El Haddadi, 12 Mio Euro, Sturm]}]

Zusatz 10 Punkte
Error 7
Error 8
4-3-3
Error 9
Error 10

Zusatz 15 Punkte
[Barcelona, {[Coutinho, 100 Mio Euro, Mitte], [Cillessen, 10 Mio Euro, Tor], [Suarez, 70 Mio Euro, Sturm], [Messi, 180 Mio Euro, Sturm], [El Haddadi, 12 Mio Euro, Sturm], [Umtiti, 60 Mio Euro, Abwehr], [Alba, 60 Mio Euro, Abwehr], [Digne, 15 Mio Euro, Abwehr], [Gomes, 15 Mio Euro, Mitte], [Paulinho, 40 Mio Euro, Mitte], [Roberto, 55 Mio Euro, Abwehr], [Stegen, 60 Mio Euro, Tor]}]

[Barcelona, {[Coutinho, 100 Mio Euro, Mitte], [Suarez, 70 Mio Euro, Sturm], [Messi, 180 Mio Euro, Sturm], [El Haddadi, 12 Mio Euro, Sturm], [Umtiti, 60 Mio Euro, Abwehr], [Alba, 60 Mio Euro, Abwehr], [Digne, 15 Mio Euro, Abwehr], [Gomes, 15 Mio Euro, Mitte], [Paulinho, 40 Mio Euro, Mitte], [Roberto, 55 Mio Euro, Abwehr]}]
[Cillessen, 10 Mio Euro, Tor] [Stegen, 60 Mio Euro, Tor]
[Barcelona, {[Coutinho, 100 Mio Euro, Mitte], [Umtiti, 60 Mio Euro, Abwehr], [Alba, 60 Mio Euro, Abwehr], [Digne, 15 Mio Euro, Abwehr], [Gomes, 15 Mio Euro, Mitte], [Paulinho, 40 Mio Euro, Mitte], [Roberto, 55 Mio Euro, Abwehr]}]
[Suarez, 70 Mio Euro, Sturm] [Messi, 180 Mio Euro, Sturm] [El Haddadi, 12 Mio Euro, Sturm]
[Barcelona, {[Coutinho, 100 Mio Euro, Mitte], [Gomes, 15 Mio Euro, Mitte], [Paulinho, 40 Mio Euro, Mitte]}]
[Umtiti, 60 Mio Euro, Abwehr] [Alba, 60 Mio Euro, Abwehr] [Digne, 15 Mio Euro, Abwehr] [Roberto, 55 Mio Euro, Abwehr]
[Barcelona, {}]
[Coutinho, 100 Mio Euro, Mitte] [Gomes, 15 Mio Euro, Mitte] [Paulinho, 40 Mio Euro, Mitte]
[Barcelona, {}]
[Coutinho, 100 Mio Euro, Mitte] [Umtiti, 60 Mio Euro, Abwehr] [Alba, 60 Mio Euro, Abwehr] [Digne, 15 Mio Euro, Abwehr] [Gomes, 15 Mio Euro, Mitte] [Paulinho, 40 Mio Euro, Mitte] [Roberto, 55 Mio Euro, Abwehr]
*/