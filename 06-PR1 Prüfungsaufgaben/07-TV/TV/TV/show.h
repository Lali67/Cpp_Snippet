#ifndef SHOW_H
#define SHOW_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

enum class Genre { Sitcom, Drama, SciFi, Fantasy, Cartoon };

class Show {
private:
	string name;
	Genre genre;
	int anzahl_staffeln;
	bool status;
public:
	Show(string tname, Genre tgenre, int anzahl_tstaffeln = 1) : name(tname), genre(tgenre), anzahl_staffeln(anzahl_tstaffeln)
	{
		status = true;

		if (name.size() == 0 || anzahl_staffeln < 1 || anzahl_staffeln > 10)
			throw runtime_error("runtime error");

	}

	bool produce_season();
	void cancel();
	bool reboot(string newname);
	bool has_genre(Genre g) const;
	friend ostream& operator << (ostream& out, const Show& s);

};


#endif