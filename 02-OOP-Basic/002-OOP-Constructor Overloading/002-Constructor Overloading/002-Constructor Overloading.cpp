// 002-Constructor Overloading.cpp 

/*
	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ Classes and Objects (https://www.programiz.com/cpp-programming/object-class)
		C++ Constructors (https://www.programiz.com/cpp-programming/constructors)
		C++ Operator Overloading (https://www.programiz.com/cpp-programming/operator-overloading)
*/

// Source Code to demonstrate the working of overloaded constructors
	#include <iostream>
	using namespace std;
	class Area
	{
	private:
		int length;
		int breadth;
	public:
		// Constructor with no arguments
		Area() : length(5), breadth(2) { }
		// Constructor with two arguments
		Area(int l, int b) : length(l), breadth(b) { }
		void GetLength()
		{
			cout << "Enter length and breadth respectively: ";
			cin >> length >> breadth;
		}
		int AreaCalculation() { return length * breadth; }
		void DisplayArea(int temp)
		{
			cout << "Area: " << temp << endl;
		}
	};

	int main()
	{
		Area A1, A2(2, 1);
		int temp;
		cout << "Default Area when no argument is passed." << endl;
		temp = A1.AreaCalculation();
		A1.DisplayArea(temp);
		cout << "Area when (2,1) is passed as argument." << endl;
		temp = A2.AreaCalculation();
		A2.DisplayArea(temp);
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
