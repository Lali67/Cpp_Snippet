// 038- Add Complex Numbers by Passing Structure.cpp 
/*
	This program takes two complex numbers as structures and adds them with the use of functions. 
		https://www.programiz.com/cpp-programming/examples/complex-number-add

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ Structures(https://www.programiz.com/cpp-programming/structure)
		C++ Structure and Function(https://www.programiz.com/cpp-programming/structure-function)
*/

#include <iostream>
using namespace std;

typedef struct complex
{
	float real;
	float imag;
} complexNumber;

complexNumber addComplexNumbers(complex, complex);

int main()
{
	complexNumber n1, n2, temporaryNumber;
	char signOfImag;

	cout << "For 1st complex number," << endl;
	cout << "Enter real and imaginary parts respectively:" << endl;
	cin >> n1.real >> n1.imag;

	cout << endl << "For 2nd complex number," << endl;
	cout << "Enter real and imaginary parts respectively:" << endl;
	cin >> n2.real >> n2.imag;

	temporaryNumber			= addComplexNumbers(n1, n2);
	signOfImag				= (temporaryNumber.imag > 0) ? '+' : '-';
	temporaryNumber.imag	= (temporaryNumber.imag > 0) ? temporaryNumber.imag : -temporaryNumber.imag;

	cout << "Sum = " << temporaryNumber.real << signOfImag << temporaryNumber.imag << "i\n\n";
	return 0;
}

complexNumber addComplexNumbers(complex n1, complex n2)
{
	complex temp;
	temp.real = n1.real + n2.real;
	temp.imag = n1.imag + n2.imag;
	return(temp);
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
