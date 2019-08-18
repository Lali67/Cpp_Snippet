#pragma once 
	//designed to cause the current source file to be included only once in a single compilation

/* The Circle class Header (Circle.h) */
#include <string>   // using string
using namespace std;


// Circle class declaration
class Circle {
	private:   // Accessible by members of this class only
	   // private data members (variables)
		double radius;
		string color;

	public:    // Accessible by ALL
	   // Declare prototype of member functions
	   // Constructor with default values
		Circle(double radius = 1.0, string color = "red");

		// Public getters & setters for private data members
		double	getRadius() const;
		void	setRadius(double radius);
		string	getColor() const;
		void	setColor(string color);

		// Public member Function
		double	getArea() const;
};

