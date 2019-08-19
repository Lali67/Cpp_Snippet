#include "Point.h"

/* 
	The Point class Implementation (Point.cpp)
	https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp3_OOP.html#zz-6.
*/

#include "Point.h" // user-defined header in the same directory
#include <iostream>
#include <cmath>
using namespace std;

// Constructor (default values can only be specified in the declaration)
Point::Point(int x, int y) : x(x), y(y) { }  // Use member initializer list

// Public getter for private data member x
int Point::getX() const {
	return x;
}

// Public setter for private data member x
void Point::setX(int x) {
	this->x = x;
}

// Public getter for private data member y
int Point::getY() const {
	return y;
}

// Public setter for private data member y
void Point::setY(int y) {
	this->y = y;
}

// Public member function to set both x and y
void Point::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}

// Public member function to return the magitude
double Point::getMagnitude() const {
	return sqrt(x * x + y * y);    // sqrt in <cmath>
}

// Public member function to return the argument
double Point::getArgument() const {
	return atan2(y, x);    // atan2 in <cmath>
}

// Public member function to print description about this point
void Point::print() const {
	cout << "(" << x << "," << y << ")" << endl;
}
