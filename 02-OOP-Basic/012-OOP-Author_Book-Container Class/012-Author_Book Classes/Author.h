#pragma once
// https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp3_OOP.html#zz-9.

/* Header for the Author class (Author.h) */
#include <string>
using namespace std;

class Author {
private:
	string	name;
	string	email;
	char	gender;   // 'm', 'f', or 'u' for unknown

public:
	Author(const std::string& name, const std::string& email, char gender);
	// & specifies pass by reference, const for non-mutable

	string	getName() const;
	string	getEmail() const;
	char	getGender() const;

	void	setEmail(const std::string& email);

	void	print() const;
};
