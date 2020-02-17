#ifndef EXEMPLAR_H
#define EXEMPLAR_H

#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>

using namespace std;

enum class Zustand {Neuwertig, Gut, Abgegriffen, Unbrauchbar };

class Exemplar {
private:
	int num_auflag;
	Zustand zus;
	bool verliehen;
public:
	Exemplar (int tnum, Zustand tzus = Zustand::Neuwertig) : num_auflag(tnum), zus(tzus)
	{
		verliehen = false;
		if (num_auflag < 1 || num_auflag > 1000) 
			throw runtime_error("runtime error");
	}

	bool verfuegbar() const;
	bool entleihen();
	void retournieren(Zustand z);
	//Zustand getzus() const;
	friend ostream& operator << (ostream& out, const Exemplar& e);

};

#endif
