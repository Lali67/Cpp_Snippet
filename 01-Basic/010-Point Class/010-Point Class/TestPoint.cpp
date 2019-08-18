/* 
	A test driver for the Point class (TestPoint.cpp) 
	https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp3_OOP.html#zz-6.
*/

#include <iostream>
#include <iomanip>
#include "Point.h"   // using Point class
using namespace std;

int main() {
	// Construct an instance of Point p1
	Point p1(3, 4);
	p1.print();
	cout << "x = " << p1.getX() << endl;
	cout << "y = " << p1.getY() << endl;
	cout << fixed << setprecision(2);
	cout << "mag = " << p1.getMagnitude() << endl;
	cout << "arg = " << p1.getArgument() << endl;
	p1.setX(6);
	p1.setY(8);
	p1.print();
	p1.setXY(1, 2);
	p1.print();

	// Construct an instance of Point using default constructor
	Point p2;
	p2.print();
}