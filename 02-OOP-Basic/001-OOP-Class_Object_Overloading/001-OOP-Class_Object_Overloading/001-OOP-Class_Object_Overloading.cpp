// 001-OOP-Class_Object_Overloading.cpp 

/*
	Detail info: https://dev.to/ichtrojan/understanding-basic-object-oriented-programming-with-c-3d0a

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ Classes and Objects (https://www.programiz.com/cpp-programming/object-class)
		C++ Constructors (https://www.programiz.com/cpp-programming/constructors)
		C++ Operator Overloading (https://www.programiz.com/cpp-programming/operator-overloading)
*/


	#include <iostream>
	using namespace std;

	class human {
	public:
		string name;
		int age;

		human(): name("NewBorn"), age(0)
		{
			// Body of constructor
			//You can also initialise the data members inside the constructor's body as below. 
			// However, this method is not preferred.

		}

		void eat() {
			cout << name << " is eating" << endl;
		}

		void eat(string food1) {
			cout << name << " is eating " << food1 << endl;
		}

		void eat(string food1, string food2) {
			cout << name << " is eating " << food1 << " and " << food2 << endl;
		}
	};

	int main() {
		human exhibitA;

		exhibitA.name = "Michael";
		exhibitA.eat();
		exhibitA.eat("Rice");
		exhibitA.eat("Rice", "Beans");

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
