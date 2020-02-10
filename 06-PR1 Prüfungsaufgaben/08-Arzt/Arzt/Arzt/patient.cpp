#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"patient.h"

using namespace std;

bool Patient::diagnose(const vector<Field>& v)
{
	bool hinzugefuegt{false};

	for (const Field& vec : v)
	{
		bool gefunden{false};

		for (const Field& tvec : symptoms)
			if (vec == tvec)
			{
				gefunden = true;
				break;
			}

		if (!gefunden)
		{
			symptoms.push_back(vec);
			hinzugefuegt = true;
		}
	}

	if (hinzugefuegt)
		return true;

	return false;
}

size_t Patient::count_symptoms_of(const vector<Field>& v) const
{
	size_t count{0};

	for (const Field& vec : v)
		for (const Field& tvec : symptoms)
			if (vec == tvec)
			{
				count++;
				break;
			}
	
	return count;
}

ostream& operator << (ostream& out, const Patient& pat)
{
	//[name{ Symptomliste }]

	out << "[" << pat.name;

	if (pat.symptoms.size() > 0) 
	{
		out << " {";

		for(int i = 0; i < pat.symptoms.size() - 1; i++)
			switch (pat.symptoms.at(i))
			{
				case Field::Card:
					out << "Cardiology, ";
					break;

				case Field::Neuro:
					out << "Neurology, ";
					break;

				case Field::Onc:
					out << "Oncology, ";
					break;

				case Field::Opht:
					out << "Ophthalmology, ";
					break;

				case Field::Orth:
					out << "Orthopedia, ";
					break;

				case Field::Neph:
					out << "Nephrology, ";
					break;

				case Field::Gast:
					out << "Gastrology, ";
					break;

				case Field::Pul:
					out << "Pulmonology, ";
					break;
			}
		
		switch(pat.symptoms.at(pat.symptoms.size() - 1)) 
		{

		case Field::Card:
			out << "Cardiology}]";
			break;

		case Field::Neuro:
			out << "Neurology}]";
			break;

		case Field::Onc:
			out << "Oncology}]";
			break;

		case Field::Opht:
			out << "Ophthalmology}]";
			break;

		case Field::Orth:
			out << "Orthopedia}]";
			break;

		case Field::Neph:
			out << "Nephrology}]";
			break;

		case Field::Gast:
			out << "Gastrology}]";
			break;

		case Field::Pul:
			out << "Pulmonology}]";
			break;
		}
	}

	else
		out << "]";

	return out;
}