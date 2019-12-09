#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Score.h"
#include "Assessment.h"
#include "Student.h"

using namespace std;

class Course {
	unsigned int id;
	string name;
	string description;
	vector<string> instructors;
	vector<Score> student_scores;
	vector<Assessment> assessments;
	vector<Student> students;

public:
	//constructor
	Course(unsigned int c_id, string aName, string desc = "Test Course") :
		id(c_id), name(aName), description(desc) {};
	// getter function
	string getName() { return name; }
	// fill list of Course
	void fillStudentList(vector<Student> list) {
		for (Student obj : list) students.push_back(obj);
	};
	void fillAssessmentList(vector<Assessment> list) {
		for (Assessment obj : list) assessments.push_back(obj);
	};
	void fillScoreList(vector<Score> list) {
		for (Score obj : list) student_scores.push_back(obj);
	};
	
	//statistics functions
	double getAvgAssessmentScoreByID(Student const& aStudent) {
		double ret{ 0.0 };
		std::vector<Student>::iterator st_it;
		std::vector<Score>::iterator sc_it;
		std::vector<Assessment>::iterator as_it;
		int counter{ 0 };

		std::sort(students.begin(), students.end());
		st_it = std::find(students.begin(), students.end(), aStudent);
		//check the aStudent is valid 
		if (st_it != students.end()) {
			cout << *st_it;
			std::sort(student_scores.begin(), student_scores.end());
			std::sort(assessments.begin(), assessments.end());
			for (Score score_obj : student_scores) {
				if (score_obj.getStudentID() == (*st_it).getId()) {
					Assessment temp{ score_obj.getAssessmentID(),"" };
					as_it = std::find(assessments.begin(), assessments.end(), temp);
					ret += double(score_obj.getScore()) / double((*as_it).getMaxPoint());
					counter++;
				}
			}
			if (counter > 0) ret = ret/double(counter) * 100.0;
		}
		else
			cout << "The student has not enrolled in this Course" << endl;

		return ret;
	}

	//print functions
	void printGeneralInfo(std::ostream& str = std::cout) const {
		str << "Course: " << id << " --- " << name<< endl;
		str << description << endl << endl;
	};

	void printSortedStudentByID(std::ostream& str = std::cout) {
		std::sort(students.begin(), students.end());
		for (Student aStudent : students) aStudent.print();
	};

	void printSortedAssessmentByID() {
		std::sort(assessments.begin(), assessments.end());
		for (Assessment anAssessment : assessments) anAssessment.print();
	}

	void printSortedScoresByID() {
		std::sort(student_scores.begin(), student_scores.end());
		for (Score aScore : student_scores) aScore.print();
	}

	friend std::ostream& operator << (std::ostream& stream, Course const& sc) {
		sc.printGeneralInfo(stream);
		return stream;
	}
};

#endif
