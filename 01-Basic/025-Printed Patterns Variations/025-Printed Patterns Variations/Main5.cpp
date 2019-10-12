// 025-Printed Patterns Variations.cpp 

/*
----
Output:
*****
****
***
**
*
**
***
****
*****
----
*/
#include <iostream>
const int MAX_NUM_LINES = 15;
using namespace std;

int main()
{
	for (int i = 0; i < MAX_NUM_LINES; i++) {
		for (int j = 0; j < MAX_NUM_LINES-i;j++) {
			std::cout << "*";
		}
		cout << endl;
	}

	for (int i = 1; i < MAX_NUM_LINES; i++) {
		for (int k = 0; k < i+1; k++) {
			std::cout << "*";
		}
		cout << endl;
	}

}