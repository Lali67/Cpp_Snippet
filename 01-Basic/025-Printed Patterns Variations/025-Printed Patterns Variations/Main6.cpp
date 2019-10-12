// 025-Printed Patterns Variations.cpp 

/*
----
Output:
    *
   ***
  *****
 *******
*********
----
*/
#include <iostream>
const int MAX_NUM_LINES = 20;
using namespace std;

int main()
{
	for (int i = 0; i < MAX_NUM_LINES; i++) {
		for (int j = 0; j < MAX_NUM_LINES - i-1; j++) {
			std::cout << " ";
		}
		for (int k = 0; k < 2*i+1; k++) {
			std::cout << "*";
		}
		cout << endl;
	}

	

}