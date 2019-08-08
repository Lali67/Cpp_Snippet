// 021-Find LCM.cpp 
/*
	Examples on different ways to calculate the LCM (Lowest Common Multiple) 
	of two integers using loops and decision making statements. 
	https://www.programiz.com/cpp-programming/examples/lcm

	To understand this example, you should have the knowledge of following C++ programming topics:
		C++ if, if...else and Nested if...else (https://www.programiz.com/cpp-programming/if-else)
		C++ for Loop (https://www.programiz.com/cpp-programming/for-loop)
		C++ while and do...while Loop (https://www.programiz.com/cpp-programming/do-while-loop)

	LCM of two integers a and b is the smallest positive integer that is divisible by both a and b.

	Standard library:
	https://www.programiz.com/cpp-programming/library-function

*/

#include <iostream>
using namespace std;
int main()
{
	int n1, n2, max;
	cout << "Enter two numbers: ";
	cin >> n1 >> n2;

	// maximum value between n1 and n2 is stored in max
	max = (n1 > n2) ? n1 : n2;
	do
	{
		if (max % n1 == 0 && max % n2 == 0)
		{
			cout << "LCM = " << max;
			break;
		}
		else
			++max;
	} while (true);

	return 0;
}

/*
	#include <iostream>
	using namespace std;
	
	//LCM = (n1 * n2) / HCF

	int main()
	{
		int n1, n2, hcf, temp, lcm;
		cout << "Enter two numbers: ";
		cin >> n1 >> n2;
		hcf = n1;
		temp = n2;

		while(hcf != temp)
		{
			if(hcf > temp)
				hcf -= temp;
			else
				temp -= hcf;
		}
		lcm = (n1 * n2) / hcf;
		cout << "LCM = " << lcm;
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
