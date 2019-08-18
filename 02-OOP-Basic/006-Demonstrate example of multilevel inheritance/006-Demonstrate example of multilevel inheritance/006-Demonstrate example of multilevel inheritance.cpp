// 006-Demonstrate example of multilevel inheritance.cpp 

/* 
	C++ program to demonstrate example of multilevel inheritance.
		http://www.cplusplus.com/doc/tutorial/inheritance/
*/

#include <iostream>
using namespace std;

//Base Class : class A
class A
{
	private:
		int a;
	public:
		void get_a(int val_a)
		{
			a = val_a;
		}

		void disp_a(void)
		{
			cout << "Value of a: " << a << endl;
		}
};

//Here Class B is base class for class C
//and Derived class for class A
class B : public A
{
	private:
		int b;
	public:
		//assign value of a from here
		void get_b(int val_a, int val_b)
		{
			//assign value of a by calling function of class A
			get_a(val_a);
			b = val_b;
		}

		void disp_b(void)
		{
			//display value of a
			disp_a();
			cout << "Value of b: " << b << endl;
		}
};

//Here class C is derived class and B is Base class
class C : public B
{
	private:
		int c;
	public:
		//assign value of a from here
		void get_c(int val_a, int val_b, int val_c)
		{
			/*** Multilevel Inheritance ***/
			//assign value of a, bby calling function of class B and Class A
			//here Class A is inherited on Class B, and Class B in inherited on Class B
			get_b(val_a, val_b);
			c = val_c;
		}

		void disp_c(void)
		{
			//display value of a and b using disp_b()
			disp_b();
			cout << "Value of c: " << c << endl;
		}
};

int main()
{
	//create object of final class, which is Class C
	C objC;

	objC.get_c(10, 20, 30);
	objC.disp_c();

	return 0;
}
