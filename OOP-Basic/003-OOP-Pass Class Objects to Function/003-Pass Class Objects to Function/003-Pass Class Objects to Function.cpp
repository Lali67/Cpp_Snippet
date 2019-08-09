// 003-Pass Class Objects to Function.cpp 

/*
	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ Classes and Objects (https://www.programiz.com/cpp-programming/object-class)
		C++ Constructors (https://www.programiz.com/cpp-programming/constructors)
		C++ Operator Overloading (https://www.programiz.com/cpp-programming/operator-overloading)
*/

#include <iostream>
using namespace std;

//C++ program to add two complex numbers by passing objects to a function.
	class Complex
	{
	private:
		int real;
		int imag;
	public:
		Complex() : real(0), imag(0) { }
		void readData()
		{
			cout << "Enter real and imaginary number respectively:" << endl;
			cin >> real >> imag;
		}
		void addComplexNumbers(Complex comp1, Complex comp2)
		{
			// real represents the real data of object c3 because 
			//   this function is called using code c3.add(c1,c2);
			real = comp1.real + comp2.real;
			// imag represents the imag data of object c3 because 
			//   this function is called using code c3.add(c1,c2);
			imag = comp1.imag + comp2.imag;
		}
		void displaySum()
		{
			cout << "Sum = " << real << "+" << imag << "i";
		}
	};

	int main()
	{
		Complex c1, c2, c3;
		c1.readData();
		c2.readData();
		c3.addComplexNumbers(c1, c2);
		c3.displaySum();
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
