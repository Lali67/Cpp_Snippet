// 036-Store Information of a Student.cpp 

/*
	This program stores the information (name, roll and marks entered by the user) of 
	a student in a structure and displays it on the screen.
		https://www.programiz.com/cpp-programming/examples/structure-store-information

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ Structures(https://www.programiz.com/cpp-programming/structure)
		C++ Strings(https://www.programiz.com/cpp-programming/strings)

	In this program, a structure(student) is created which contains name, roll and marks 
	as its data member. Then, a structure variable(s) is created. 
	Then, data (name, roll and marks) is taken from user and stored in data members of 
	structure variable s. Finally, the data entered by user is displayed.
*/

#include <iostream>
using namespace std;

struct student
{
	char name[50];
	int roll;
	float marks;
};

int main()
{
	student s;
	cout << "Enter information," << endl;
	cout << "Enter name: ";
	cin >> s.name;
	cout << "Enter roll number: ";
	cin >> s.roll;
	cout << "Enter marks: ";
	cin >> s.marks;
	cout << "\nDisplaying Information," << endl;
	cout << "Name: " << s.name << endl;
	cout << "Roll: " << s.roll << endl;
	cout << "Marks: " << s.marks << endl;
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
