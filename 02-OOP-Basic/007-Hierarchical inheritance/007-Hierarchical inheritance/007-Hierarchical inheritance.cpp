// 007-Hierarchical inheritance.cpp 

/*
	C++ program to demonstrate example of hierarchical inheritance to get square and cube of a number.
		http://www.cplusplus.com/doc/tutorial/inheritance/
*/


#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	void getNumber(void)
	{
		cout << "Enter an integer number: ";
		cin >> num;
	}
	//to return num
	int returnNumber(void)
	{
		return num;
	}
};

//Base Class 1, to calculate square of a number
class Square :public Number
{
public:
	int getSquare(void)
	{
		int num, sqr;
		num = returnNumber(); //get number from class Number
		sqr = num * num;
		return sqr;
	}
};

//Base Class 2, to calculate cube of a number
class Cube :public Number
{
private:

public:
	int getCube(void)
	{
		int num, cube;
		num = returnNumber(); //get number from class Number
		cube = num * num * num;
		return cube;
	}
};
int main()
{
	Square objS;
	Cube objC;
	int sqr, cube;

	objS.getNumber();
	sqr = objS.getSquare();
	cout << "Square of " << objS.returnNumber() << " is: " << sqr << endl;

	objC.getNumber();
	cube = objC.getCube();
	cout << "Cube   of " << objS.returnNumber() << " is: " << cube << endl;

	return 0;
}
