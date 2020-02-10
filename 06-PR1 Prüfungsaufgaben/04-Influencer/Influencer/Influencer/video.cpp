#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"video.h"

using namespace std;

extern vector <string> platform_names;

vector<Platform> Video::upload(const vector<Platform>& v) 
{
	vector<Platform> temp;

	for (int j = 0; j < v.size(); j++) 
	{
		bool gefunden = false;

		for (int i = 0; i < platforms.size(); i++)
		{
			if (platforms.at(i) == v.at(j))
				gefunden = true;
		}

		if (!gefunden)
			platforms.push_back(v.at(j));

		else
			temp.push_back(v.at(j));
	}
	return temp;
}

int Video::get_class() const
{
	int temp_2;

	temp_2 = (length / 10) + 1;

	return temp_2;
}

ostream& operator << (ostream& out, const Video& vv)
{
	out << "[" << vv.title << " (" << vv.get_class() << "): {";
	
	if (vv.platforms.size() > 0)
	{
		for (int i = 0; i < vv.platforms.size() - 1; i++)
			out << platform_names.at(static_cast<size_t>(vv.platforms.at(i))) << ", ";

		out << platform_names.at(static_cast<size_t>(vv.platforms.at(vv.platforms.size() - 1))) << "}, " << vv.length << "]";
	}

	return out;
}