// 005-Binary Operator Overloading to Complex Number.cpp

/*
	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ Classes and Objects (https://www.programiz.com/cpp-programming/object-class)
		C++ Constructors (https://www.programiz.com/cpp-programming/constructors)
		C++ Operator Overloading (https://www.programiz.com/cpp-programming/operator-overloading)
*/

#include <iostream>
using namespace std;
// Since - is a binary operator( operator that operates on two operands ), one of the operands 
//    should be passed as argument to the operator functionand the rest process is similar to 
//    the overloading of unary operators.
class Complex
{
private:
	float real;
	float imag;
public:
	Complex() : real(0), imag(0) { }
	void input()
	{
		cout << "Enter real and imaginary parts respectively: ";
		cin >> real;
		cin >> imag;
	}
	// Operator overloading
	Complex operator - (Complex c2)
	{
		Complex temp;
		temp.real = real - c2.real;
		temp.imag = imag - c2.imag;
		return temp;
	}
	void output()
	{
		if (imag < 0)
			cout << "Output Complex number: " << real << imag << "i";
		else
			cout << "Output Complex number: " << real << "+" << imag << "i";
	}
};
int main()
{
	Complex c1, c2, result;
	cout << "Enter first complex number:\n";
	c1.input();
	cout << "Enter second complex number:\n";
	c2.input();
	// In case of operator overloading of binary operators in C++ programming, 
	// the object on right hand side of operator is always assumed as argument by compiler.
	result = c1 - c2;
	result.output();
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
