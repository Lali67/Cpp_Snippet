#ifndef ASSESSMENT_H
#define ASSESSMENT_H

#include <iostream>
#include <string>
//#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Assessment {
	unsigned int id;
	string name;
	string description;
	int maxPoint;

public:
	Assessment(unsigned int ass_id, string ass_name,
		string ass_description = "Test1", int ass_maxPoint = 100) :
		id(ass_id), name(ass_name), description(ass_description), maxPoint(ass_maxPoint) {};
	// Copy constructor
	Assessment(const Assessment& obj) {
		id = obj.id;
		name = obj.name;
		description = obj.description;
		maxPoint = obj.maxPoint;
	}
	
	// getter function
	int getMaxPoint() { return maxPoint; }
	//operator overloading
	  //std::sort() uses your overloaded operator< to compare objects
	bool operator < (Assessment const& obj) { return id < obj.id; }
	  //std::find() uses your overloaded operator== to compare objects
	bool operator == (Assessment const& obj) { return id == obj.id; }

	// print functions
	void print(std::ostream& str = std::cout) const {
		std::stringstream ss;

		ss << std::setw(6) << std::setfill(' ') << id;
		str << "Assessment id: " << ss.str() << " Name: " << name << endl;
	};
	friend std::ostream& operator << (std::ostream& stream, Assessment const& sc) {
		sc.print(stream);
		return stream;
	}
};

#endif
