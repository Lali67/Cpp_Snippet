// 043-Syntax and semantic errors I.cpp
/*
	Although debugging tools and techniques aren’t part of the C++ standard, learning to find and 
	remove bugs in the programs you write is an extremely important part of 
	being a successful programmer. 
*/

#include <iostream>

int main()
{
	std::cout < "Hi there"; << x; // invalid operator (<), extraneous semicolon, undeclared variable (x)
	return 0 // missing semicolon at end of statement
}

/*
	int main()
{
    int a = 10;
    int b = 0;
    std::cout << a << " / " << b << " = " << a / b; // division by 0 is undefined
    return 0;
}
*/

/*
int main()
{
	int x;
	std::cout << x; // Use of uninitialized variable leads to undefined result

	return 0;
}
*/

/*
int add(int x, int y)
{
	return x - y; // function is supposed to add, but it doesn't
}

int main()
{
	std::cout << add(5, 3); // should produce 8, but produces 2

	return 0;
}
*/

/*
#include <iostream>

int main()
{
	return 0; // function returns here

	std::cout << "Hello, world!"; // so this never executes
}

*/

/*
#include <iostream>

int add(int x, int y)
{
	return x - y; // function is supposed to add, but it doesn't
}

int main()
{
	std::cout << add(5, 3); // should produce 8, but produces 2
	return 0;
}
*/

/*
	int main() 
{ 
    int i = 0; 
  
    // logical error : a semicolon after loop 
    for(i = 0; i < 3; i++); 
    { 
        printf("loop "); 
        continue; 
    }  
    getchar(); 
    return 0; 
} 
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
