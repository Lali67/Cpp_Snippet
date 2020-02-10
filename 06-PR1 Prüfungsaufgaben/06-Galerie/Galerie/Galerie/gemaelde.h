#ifndef GEMAELDE_H
#define GEMAELDE_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

enum class Stil { Klassisch, Abstrakt, Surreal };

class Gemaelde {
private:
	string name;
	int wert;
	Stil st;
	vector<string> interessenten;
public:
	Gemaelde(string tname, int twert, Stil sts = Stil::Klassisch) : name(tname), wert(twert)
	{
		st = sts;

		if (name.size() == 0 || wert < 100 || wert > 10000)
			throw runtime_error("runtime error");

	}

	int get_wert() const;
	string get_name() const;
	bool hat_interessent() const;
	void add_interessent(const string& interessent);
	friend ostream& operator << (ostream& out, const Gemaelde& gem);

};



#endif