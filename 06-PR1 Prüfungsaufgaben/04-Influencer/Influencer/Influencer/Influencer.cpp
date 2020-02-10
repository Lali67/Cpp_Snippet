#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"influencer.h"

using namespace std;

void Influencer::create_video(const Video& v)
{
		videos.push_back(v);
}

vector<Video> Influencer::videos_in_class(int c) const
{
	vector<Video> temp_3;
	
	for (int i = videos.size() - 1; i >= 0; i--)
			if (videos.at(i).get_class() == c)
				temp_3.push_back(videos.at(i));
	
	return temp_3;
}

ostream& operator << (ostream& out, const Influencer& ic)
{
	out << "[" << ic.name << " (" << ic.videos.size() << "), " << "{";
	
	if (ic.videos.size() > 0)
	{
		for (int i = 0; i < ic.videos.size() - 1; i++)
			out << ic.videos.at(i) << ", ";

		out << ic.videos.at(ic.videos.size() - 1) << "}]";
	}
	else
	{
		out << "}]";
	}
	return out;
}