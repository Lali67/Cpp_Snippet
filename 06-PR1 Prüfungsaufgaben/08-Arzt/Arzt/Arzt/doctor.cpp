#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"patient.h"
#include"doctor.h"

using namespace std;

vector<Patient> Doctor::cannot_treat() const
{
	vector<Patient> temp;

	for (const Patient& pt : waiting)
		if (pt.count_symptoms_of(expertise) < expertise.size())
			temp.push_back(pt);

	return temp;
}

ostream& operator << (ostream& out, const Doctor& doc) 
{
	//[name, { Fachgebietsliste }, { Patientenliste }]
	out << "[" << doc.name << ", {";

	for (int i = 0; i < doc.expertise.size() - 1; i++)
		switch (doc.expertise.at(i))
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

	switch (doc.expertise.at(doc.expertise.size() - 1))
	{

	case Field::Card:
		out << "Cardiology}, {";
		break;

	case Field::Neuro:
		out << "Neurology}, {";
		break;

	case Field::Onc:
		out << "Oncology}, {";
		break;

	case Field::Opht:
		out << "Ophthalmology}, {";
		break;

	case Field::Orth:
		out << "Orthopedia}, {";
		break;

	case Field::Neph:
		out << "Nephrology}, {";
		break;

	case Field::Gast:
		out << "Gastrology}, {";
		break;

	case Field::Pul:
		out << "Pulmonology}, {";
		break;
	}

	if (doc.waiting.size() > 0)
	{
		for (int i = 0; i < doc.waiting.size() - 1; i++)
			out << doc.waiting.at(i) << ", ";
		out << doc.waiting.at(doc.waiting.size() - 1) << "}]";
	}

	else
		out << "}]";

	return out;
}