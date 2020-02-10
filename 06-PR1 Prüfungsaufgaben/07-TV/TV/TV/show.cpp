#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"show.h"

using namespace std;

bool Show::produce_season() 
{
	if (anzahl_staffeln < 10 && status == true)
	{
		anzahl_staffeln += 1;
		return true;
	}

	return false;
}

void Show::cancel() 
{
	if (status == false)
		throw runtime_error("runtime error");

	if (status == true)
		status = false;
}

bool Show::reboot(string newname) 
{
	if (status == false)
	{
		if (newname.size() > 0 && status == false && anzahl_staffeln < 10)
		{
			name = newname;
			status = true;
			anzahl_staffeln += 1;
		}
		
		else
			return false;
	}
	
	else
		return false;

	return true;
}

bool Show::has_genre(Genre g) const 
{
	if (genre == g)
		return true;

	else
		return false;
}

ostream& operator << (ostream& out, const Show& s) 
{
	out << "["; 
	
	if(s.status == false)
	out << s.name << ", " << s.anzahl_staffeln << " Staffel(n), ";

	if (s.status == true)
		out << "*" << s.name << "*, " << s.anzahl_staffeln << " Staffel(n), ";

	switch (s.genre)
	{
		case Genre::Cartoon:
			out << "Cartoon";
			break;

		case Genre::Drama:
			out << "Drama";
			break;
		
		case Genre::Fantasy:
			out << "Fantasy";
			break;
		
		case Genre::SciFi:
			out << "SciFi";
			break;
		
		case Genre::Sitcom:
			out << "Sitcom";
			break;
	}
	out << "]";
	
	return out;
}