#ifndef KLEIDST_H
#define KLEIDST_H

#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

enum class Programm { Koch, Normal, Bunt, Fein };

class KleidSt {
private:
	string bezeichnung;
	int gewicht;
	Programm pflegehinweis;
public:
	KleidSt (string tbez, int tgewicht, Programm tpfleg = Programm::Normal) 
			: bezeichnung(tbez), gewicht(tgewicht), pflegehinweis(tpfleg)
	{
		if (bezeichnung.size() == 0 || gewicht <= 0 || gewicht >= 5000)
			throw runtime_error("runtime error");
	}

	bool vertraeglich(Programm p) const;
	friend ostream& operator << (ostream& out, const KleidSt& k);
	int getgewicht() const;
	Programm getprogramm() const;

};

#endif
