// 037-Add Two Distances.cpp 

/*
	This program takes two distances (in inch-feet system), adds them and displays the result 
	on the screen. 
		https://www.programiz.com/cpp-programming/examples/inch-feet-structure

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ Structures(https://www.programiz.com/cpp-programming/structure)
		C++ if, if...else and Nested if...else(https://www.programiz.com/cpp-programming/if-else)
*/

#include <iostream>
using namespace std;

struct Distance {
	int feet;
	float inch;
}d1, d2, sum;

int main()
{
	cout << "Enter 1st distance," << endl;
	cout << "Enter feet: ";
	cin >> d1.feet;
	cout << "Enter inch: ";
	cin >> d1.inch;
	cout << "\nEnter information for 2nd distance" << endl;
	cout << "Enter feet: ";
	cin >> d2.feet;
	cout << "Enter inch: ";
	cin >> d2.inch;
	sum.feet = d1.feet + d2.feet;
	sum.inch = d1.inch + d2.inch;
	// changing to feet if inch is greater than 12
	if (sum.inch > 12)
	{
		++sum.feet;
		sum.inch -= 12;
	}
	cout << endl << "Sum of distances = " << sum.feet << " feet  " << sum.inch << " inches";
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
