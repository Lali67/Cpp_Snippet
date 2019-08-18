#include "Author.h"

/* Implementation for the Author class (Author.cpp) */
#include <iostream>
#include "Author.h"
using namespace std;

// Constructor, with input validation
Author::Author(const string& name, const string& email, char gender) : name(name) {
	setEmail(email);  // Call setter to check for valid email
	if (gender == 'm' || gender == 'f') {
		this->gender = gender;
	}
	else {
		cout << "Invalid gender! Set to 'u' (unknown)." << endl;
		this->gender = 'u';
	}
}

string Author::getName() const {
	return name;
}

string Author::getEmail() const {
	return email;
}

void Author::setEmail(const string& email) {
	// Check for valid email. Assume that a valid email contains
	//  a '@' that is not the first nor last character.
	size_t atIndex = email.find('@');
	if (atIndex != string::npos && atIndex != 0 && atIndex != email.length() - 1) {
		this->email = email;
	}
	else {
		cout << "Invalid email! Set to empty string." << endl;
		this->email = "";
	}
}

char Author::getGender() const {
	return gender;
}

// print in the format "name (gender) at email"
void Author::print() const {
	cout << name << " (" << gender << ") at " << email << endl;
}
