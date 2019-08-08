// 020-Find GCD.cpp 

/*
	Examples on different ways to calculate GCD of two integers 
	(for both positive and negative integers) using loops and decision making statements. 
	https://www.programiz.com/cpp-programming/examples/hcf-gcd

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)
		C++ for Loop (https://www.programiz.com/cpp-programming/for-loop)
		C++ while and do...while Loop (https://www.programiz.com/cpp-programming/do-while-loop)

	The largest integer which can perfectly divide two integers is known 
	as GCD (Greatest Common Divisor) or HCF(Highest Common Factor) of those two numbers.

	Standard library:
	https://www.programiz.com/cpp-programming/library-function

*/

#include <iostream>
using namespace std;

int main()
{
	int n1, n2;
	cout << "Enter two numbers: ";
	cin >> n1 >> n2;

	while (n1 != n2)
	{
		if (n1 > n2)
			n1 -= n2;
		else
			n2 -= n1;
	}
	cout << "HCF = " << n1;
	return 0;
}

/*
	    #include <iostream>
    using namespace std;
    int main() {
        int n1, n2, hcf;
        cout << "Enter two numbers: ";
        cin >> n1 >> n2;
        // Swapping variables n1 and n2 if n2 is greater than n1.
        if ( n2 > n1) {   
            int temp = n2;
            n2 = n1;
            n1 = temp;
        }
        
        for (int i = 1; i <=  n2; ++i) {
            if (n1 % i == 0 && n2 % i ==0) {
                hcf = i;
            }
        }
        cout << "HCF = " << hcf;
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
