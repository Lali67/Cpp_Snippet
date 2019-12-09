#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <string>
//#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Score {
	unsigned int student_id;
	unsigned int assessment_id;
	int assessment_score;

public:
	//constructor
	Score(unsigned int s_id, unsigned int a_id, int score) :
		student_id(s_id), assessment_id(a_id), assessment_score(score) {};

	//getter functions
	int getScore() { return assessment_score; };
	unsigned int getAssessmentID() { return assessment_id; };
	unsigned int getStudentID() { return student_id; };

	//operator overloading
	  //std::sort() uses your overloaded operator< to compare objects
	bool operator < (Score const& obj) {
		return	(student_id < obj.student_id) ||
			((student_id == obj.student_id) && (assessment_id < obj.assessment_id));
	};

	//print functions
	void print(std::ostream& str = std::cout) const {
		std::stringstream s_id, as_id, as_sc;

		s_id << std::setw(6) << std::setfill(' ') << student_id;
		as_id << std::setw(6) << std::setfill(' ') << assessment_id;
		as_sc << std::setw(6) << std::setfill(' ') << assessment_score;
		str << "Student id: " << s_id.str() << " Assessment id: " << as_id.str() <<
			"  Score:   " << as_sc.str() << endl;
	};
	friend std::ostream& operator << (std::ostream& stream, Score const& sc) {
		sc.print(stream);
		return stream;
	};
};

#endif