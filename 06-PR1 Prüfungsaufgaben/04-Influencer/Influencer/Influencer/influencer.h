#ifndef INFLUENCER_H
#define INFLUENCER_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"video.h"

using namespace std;

class Influencer {
private:
	string name;
	vector<Video> videos;
public:
	Influencer(string tname) : name(tname)
	{
		if (name.size() == 0)
			throw runtime_error("runtime error");
	}
	Influencer(string tname, vector<Video> tvideos) : name(tname)
	{
		for (int i = 0; i < tvideos.size(); i++)
			videos.push_back(tvideos.at(i));

		if (name.size() == 0)
			throw runtime_error("runtime error");
	}

	void create_video(const Video& v);
	vector<Video> videos_in_class(int c) const;
	friend ostream& operator << (ostream& out, const Influencer& ic);
};

#endif