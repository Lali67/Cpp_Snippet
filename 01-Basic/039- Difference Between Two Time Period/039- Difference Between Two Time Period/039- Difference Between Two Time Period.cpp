// 039- Difference Between Two Time Period.cpp 
/*
	Program to Calculate Difference Between Two Time Period
		https://www.programiz.com/cpp-programming/examples/time-structure

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ Structures(https://www.programiz.com/cpp-programming/structure)
		C++ Structure and Function(https://www.programiz.com/cpp-programming/structure-function)
		C++ Pointers to Structure(https://www.programiz.com/cpp-programming/structure-pointer)

*/

#include <iostream>
using namespace std;

struct TIME
{
	int seconds;
	int minutes;
	int hours;
};

void computeTimeDifference(struct TIME, struct TIME, struct TIME*);

int main()
{
	struct TIME t1, t2, difference;

	cout << "Enter start time." << endl;
	cout << "Enter hours, minutes and seconds respectively: ";
	cin >> t1.hours >> t1.minutes >> t1.seconds;

	cout << "Enter stop time." << endl;
	cout << "Enter hours, minutes and seconds respectively: ";
	cin >> t2.hours >> t2.minutes >> t2.seconds;

	computeTimeDifference(t1, t2, &difference);
	cout << endl << "TIME DIFFERENCE: " << t1.hours << ":" << t1.minutes << ":" << t1.seconds;
	cout << " - " << t2.hours << ":" << t2.minutes << ":" << t2.seconds;
	cout << " = " << difference.hours << ":" << difference.minutes << ":" << difference.seconds;

	return 0;
}
void computeTimeDifference(struct TIME t1, struct TIME t2, struct TIME* difference) {

	if (t2.seconds > t1.seconds)
	{
		--t1.minutes;
		t1.seconds += 60;
	}
	difference->seconds = t1.seconds - t2.seconds;
	if (t2.minutes > t1.minutes)
	{
		--t1.hours;
		t1.minutes += 60;
	}
	difference->minutes = t1.minutes - t2.minutes;
	difference->hours	= t1.hours - t2.hours;
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
