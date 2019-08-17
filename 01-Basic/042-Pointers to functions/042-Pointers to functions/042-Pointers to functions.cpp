// 042-Pointers to functions.cpp 
/*
	void pointers are pointers 
		that point to a value that has no type (and thus also an undetermined length and 
		undetermined dereferencing properties). void pointer needs to be transformed into 
		some other pointer type that points to a concrete data type before being dereferenced.
			http://www.cplusplus.com/doc/tutorial/pointers/

	Pointers to functions
		The typical use of this is for passing a function as an argument to another function. 
		Pointers to functions are declared with the same syntax as a regular function declaration, 
		except that the name of the function is enclosed between parentheses () and 
		an asterisk (*) is inserted before the name

*/

// increaser
#include <iostream>
using namespace std;

void increase(void* data, int psize)
{
	if (psize == sizeof(char))
	{
		char* pchar; pchar = (char*)data; ++(*pchar);
	}
	else if (psize == sizeof(int))
	{
		int* pint; pint = (int*)data; ++(*pint);
	}
}

int addition(int a, int b)
{
	return (a + b);
}

int subtraction(int a, int b)
{
	return (a - b);
}

int operation(int x, int y, int (*functocall)(int, int))
{
	int g;
	g = (*functocall)(x, y);
	return (g);
}

int main()
{
	char a = 'x';
	int b = 1602;
	// ---- how to use void pointers
	increase(&a, sizeof(a));
	increase(&b, sizeof(b));
	cout << a << ", " << b << "\n";

	int m, n;
	int (*minus)(int, int) = subtraction;
	// how to use pointer to function
	m = operation(7, 5, addition);
	n = operation(20, m, minus);
	cout << n << "\n\n";

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
