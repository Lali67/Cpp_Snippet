#ifndef VIDEO_H
#define VIDEO_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

enum class Platform { YouTube, Vimeo, BitChute, Flickr, Facebook };

extern vector <string> platform_names;

class Video {
private:
	string title;
	int length;
	vector<Platform> platforms;
public:
	Video(string ttitle, int tlength, Platform tplat = Platform::YouTube) : title(ttitle), length(tlength)
	{
		platforms.push_back(tplat);

		if (title.size() == 0 || length <= 5)
			throw runtime_error("runtime error");
	}
	
	vector<Platform> upload(const vector<Platform>& v);
	int get_class() const;
	friend ostream& operator << (ostream& out, const Video& vv);
};





#endif

