#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
//#include<vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Student{
	unsigned int id;
	string name;

	public:
		//constructor
		Student(unsigned int anID, string aName) :id(anID), name(aName){};
		// Copy constructor
		Student(const Student &aStudent) {
			id = aStudent.id;
			name = aStudent.name;
		}
		// getter functions
		unsigned int getId() { return id; };
		string getName() { return name; };

		//operator overloading
		  //std::sort() uses your overloaded operator< to compare objects
		bool operator < (Student const& obj) {return id < obj.id; }
		  //std::find() uses your overloaded operator== to compare objects
		bool operator == (Student const& obj) { return id == obj.id; }

		// print functions
		void print(std::ostream & str = std::cout) const {
			std::stringstream ss;

			ss << std::setw(6) << std::setfill(' ') << id;
			str << "Student id: " << ss.str() << " Name: " << name << endl;
		};
		friend std::ostream& operator << (std::ostream& stream, Student const& sc) {
			sc.print(stream);
			return stream;
		}
};

#endif