#pragma once
/* 
	The Point class Header (Point.h)
	https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp3_OOP.html#zz-6.
	The Point class models 2D points with x and y co-ordinates.

	The Point class contains:
		Private data members x and y (of type int), with default values of 0.
		A constructor, getters and setters for private data member x and y.
		A function setXY() to set both x and y coordinates of a Point.
		A function getMagnitude() which returns √(x2+y2). 
			You can use the built-in sqrt() function in <cmath> to compute the square root.
		A function getArgument() which returns tan-1(y/x). 
			You can use the built-in atan2(y, x) function in <cmath> to compute the gradient in radians.
		A function print() which prints "(x,y)" of this instance.

*/

// Point class declaration
class Point {
	private:
		// private data members (variables)
		int x;
		int y;

	public:
		// Declare member function prototypes
		Point(int x = 0, int y = 0);  // Constructor with default values

		int		getX() const;
		void	setX(int x);
		int		getY() const;
		void	setY(int y);
		void	setXY(int x, int y);
		double	getMagnitude() const;
		double	getArgument() const;
		void	print() const;
};

