// 008-Multiple inheritance.cpp 

/*
	A class may inherit from more than one class by simply specifying more base classes, 
	separated by commas, in the list of a class's base classes (i.e., after the colon). 
	For example, if the program had a specific class to print on screen called Output, 
	and we wanted our classes Rectangle and Triangle to also inherit its members 
	in addition to those of Polygon we could write:

		1	class Rectangle: public Polygon, public Output;
		2	class Triangle: public Polygon, public Output; 

	http://www.cplusplus.com/doc/tutorial/inheritance/
	
*/

// multiple inheritance
#include <iostream>
using namespace std;

class Polygon {
	protected:
		int width, height;
	public:
		Polygon(int a, int b) : width(a), height(b) {}
};

class Output {
	public:
		static void print(int i);
};

void Output::print(int i) {
	cout << i << '\n';
}

class Rectangle : public Polygon, public Output {
	public:
		Rectangle(int a, int b) : Polygon(a, b) {}
		int area()
		{
			return width * height;
		}
};

class Triangle : public Polygon, public Output {
	public:
		Triangle(int a, int b) : Polygon(a, b) {}
		int area()
		{
			return width * height / 2;
		}
};

int main() {
	Rectangle rect(4, 5);
	Triangle trgl(4, 5);
	cout << "Rectangle area: "; rect.print(rect.area());
	cout << "Triangle area : "; Triangle::print(trgl.area());
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
