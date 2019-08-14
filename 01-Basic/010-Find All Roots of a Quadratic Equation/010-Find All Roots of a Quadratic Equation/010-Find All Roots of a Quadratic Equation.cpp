// 010-Find All Roots of a Quadratic Equation.cpp 
/*
	This program accepts coefficients of a quadratic equation from the user and displays the roots 
	(both real and complex roots depending upon the discriminant)
		https://www.programiz.com/cpp-programming/examples/quadratic-roots

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)

	Standard library:
	https://www.programiz.com/cpp-programming/library-function
*/

#include <iostream> //cin, cout
#include <cmath>	//sqrt
using namespace std;

int main() {
	float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;
	cout << "Enter coefficients a, b and c: \n";
	cin >> a >> b >> c;
	discriminant = b * b - 4 * a * c;

	if (discriminant > 0) {
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		x2 = (-b - sqrt(discriminant)) / (2 * a);
		cout << "Roots are real and different." << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}

	else if (discriminant == 0) {
		cout << "Roots are real and same." << endl;
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		cout << "x1 = x2 =" << x1 << endl;
	}
	else {
		realPart = -b / (2 * a);
		imaginaryPart = sqrt(-discriminant) / (2 * a);
		cout << "Roots are complex and different." << endl;
		cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
		cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
	}
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
