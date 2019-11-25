#ifndef AUTO_H
#define AUTO_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

const vector<string> color_names{ 
	"0-white", "1-black", "2-silver", "3-brown", "4-gold",
	"5-red", "6-green", "7-blue", "8-yellow", "9-gray", "10-other"
};

enum class Color { 
	white, black, silver, brown, gold,
	red, green, blue, yellow, gray, other  };

const vector<string> extras_names{
	"0-Four wheel drive", "1-Wireless Mobile CarPlay", "2-Adaptive LED headlights",
	"3-Affordable night vision systems", "4-Traffic_assistant"
};

enum class CarExtrasList {
	four_wheel_drive, wireless_Mobile_CarPlay, adaptive_LED_headlights, 
	affordable_night_vision_systems, traffic_assistant
};

struct Car {
	string					brand;
	string					type;
	int						kW; 
	Color					color;
	vector<CarExtrasList>	extras;

	//print the data of Car
	ostream& print(ostream& output = std::cout);
	//read the data of Car
	void read(istream& input = std::cin, ostream& output = std::cout);
};

struct DesiredCar{
	string					brand;
	string					type;
	int						kW;
	vector<Color>			colors;
	vector<CarExtrasList>	extras;
};

void histogram(vector<Car> cars, ostream& output = std::cout);
bool find(vector<Car> cars, DesiredCar aCar);


#endif
