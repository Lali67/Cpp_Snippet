// 004-Inc_Dec Operator Overloading.cpp

/*
	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ Classes and Objects (https://www.programiz.com/cpp-programming/object-class)
		C++ Constructors (https://www.programiz.com/cpp-programming/constructors)
		C++ Operator Overloading (https://www.programiz.com/cpp-programming/operator-overloading)
*/

#include <iostream>
using namespace std;

// 'Check' allows to use both codes ++obj; obj1 = ++obj;. It is because, temp returned 
//    from operator function is stored in object obj.
class Check
{
private:
	int i;
public:
	Check() : i(0) {  }
	// Return type is Check
	
	// Prefix Increment ++ operator overloading
	Check operator ++()
	{
		Check temp;
		++i;
		temp.i = i;
		return temp;
	}

	// Notice int inside bracket which indicates postfix increment.
	Check operator ++ (int)
	{
		Check temp;
		temp.i = i++;
		return temp;
	}

	// Prefix Decrement -- operator overloading
	Check operator -- ()
	{
		Check temp;
		temp.i = --i;
		return temp;
	}
	
	// Notice int inside bracket which indicates postfix decrement.
	Check operator -- (int)
	{
		Check temp;
		temp.i = i--;
		return temp;
	}

	void Display()
	{
		cout << "i = " << i << endl;
	}
};
int main()
{
	Check obj, obj1;
	obj.Display();
	obj1.Display();
	obj1 = ++obj;
	obj.Display();
	obj1.Display();
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
