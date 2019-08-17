// 040-Store and Display Information Using Structure.cpp 

/*
	This program stores the information (name, roll and marks) of 2 students using structures. 
		https://www.programiz.com/cpp-programming/examples/information-structure-array

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ Arrays(https://www.programiz.com/cpp-programming/arrays)
		C++ Structures(https://www.programiz.com/cpp-programming/structure)

	In this program, a structure, student is created.
	This structure has three members: name (string), roll (integer) and marks (float).
*/

#include <iostream>
using namespace std;

struct student
{
	char name[50];
	int roll;
	float marks;
} s[2];

int main()
{
	cout << "Enter information of students: " << endl;
	// storing information
	for (int i = 0; i < 2; ++i)
	{
		s[i].roll = i + 1;
		cout << "For roll number" << s[i].roll << "," << endl;
		cout << "Enter name: ";
		cin >> s[i].name;
		cout << "Enter marks: ";
		cin >> s[i].marks;
		cout << endl;
	}
	cout << "Displaying Information: " << endl;
	// Displaying information
	for (int i = 0; i < 2; ++i)
	{
		cout << "\nRoll number: " << i + 1 << endl;
		cout << "Name: " << s[i].name << endl;
		cout << "Marks: " << s[i].marks << endl;
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
