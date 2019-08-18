/* 
	A test driver for the Circle class (TestCircle.cpp)
	https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp3_OOP.html#zz-4.
*/

#include <iostream>
#include "Circle.h"   // using Circle class
using namespace std;

int main() {
	// Construct an instance of Circle c1
	Circle c1(1.2, "red");
	cout << "Radius=" << c1.getRadius() << "\t Area=" << c1.getArea()
		<< "\t Color=" << c1.getColor() << endl;

	c1.setRadius(2.1);   // Change radius and color of c1
	c1.setColor("blue");
	cout << "Radius=" << c1.getRadius() << "\t Area=" << c1.getArea()
		<< "\t Color=" << c1.getColor() << endl;

	// Construct another instance using the default constructor
	Circle c2;
	cout << "Radius=" << c2.getRadius() << "\t Area=" << c2.getArea()
		<< "\t Color=" << c2.getColor() << endl;
	return 0;
}