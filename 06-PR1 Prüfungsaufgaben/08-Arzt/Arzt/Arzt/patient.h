#ifndef PATIENT_H
#define PATIENT_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

enum class Field { Card, Neuro, Onc, Opht, Orth, Neph, Gast, Pul };

class Patient {
private:
	string name;
	vector<Field> symptoms;
public:
	Patient(string tname) : name(tname)
	{
		if (name.size() == 0)
			throw runtime_error("runtime error");
	}
	
	Patient(string tname, vector<Field> tsymptoms) : name(tname)
	{
		if (name.size() == 0)
			throw runtime_error("runtime error");

		for (const Field& vec : tsymptoms)
			symptoms.push_back(vec);

		for (const Field& vec : symptoms)
		{
			int count{ 0 };

			for (int j = 0; j < symptoms.size(); j++)
				if (vec == symptoms.at(j))
					count++;

			if (count > 1)
				throw runtime_error("runtime error");
		}
	}

	bool diagnose(const vector<Field>& v);
	size_t count_symptoms_of(const vector<Field>& v) const;
	friend ostream& operator << (ostream& out, const Patient& pat);

};

#endif