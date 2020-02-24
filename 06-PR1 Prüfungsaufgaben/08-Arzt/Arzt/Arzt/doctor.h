#ifndef DOCTOR_H
#define DOCTOR_H

#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using namespace std;

class Doctor {
private:
	string name;
	vector<Field> expertise;
	vector<Patient> waiting;
public:
	Doctor(string tname, vector<Field> texpertise) : name(tname) 
	{
		for (const Field& exp : texpertise)
			expertise.push_back(exp);

		if (name.size() == 0 || expertise.size() == 0)
			throw runtime_error("runtime error");

		for (const Field& vec : expertise)
		{
			int count{ 0 };

			for (const Field& vec : expertise)
			{
				int count{ 0 };

				for (int j = 0; j < expertise.size(); j++)
					if (vec == expertise.at(j))
						count++;

				if (count > 1)
					throw runtime_error("runtime error");
			}
		}
	}
	
	Doctor(string tname, vector<Field> texpertise, vector<Patient> twaiting) : name(tname)
	{
		for (const Field& exp : texpertise)
			expertise.push_back(exp);

		for (const Patient& pt : twaiting)
			waiting.push_back(pt);

		if (name.size() == 0 || expertise.size() == 0)
			throw runtime_error("runtime error");

		for (const Field& vec : expertise)
		{
			int count{ 0 };

			for (int j = 0; j < expertise.size(); j++)
				if (vec == expertise.at(j))
					count++;

			if (count > 1)
				throw runtime_error("runtime error");
		}
	}

	vector<Patient> cannot_treat() const;
	friend ostream& operator << (ostream& out, const Doctor& doc);

};

#endif