/* 2019-W02-Exercise_2_14.cpp :

Exercise 2.14
(*) Berechnen Sie den Ausdruck 2147483647+1 jeweils unter Verwendung der Datentypen int, unsigned, 
long und double. Vergleichen und interpretieren Sie die Ergebnisse.

Dániel Szöke (11913915)
16.10.2019

*/

#include <iostream>

using namespace std;

int main()
{
	// arithmetic overflow: + operation causes overflow at compiler time: MAX_INT
	cout << "int(2147483647 + 1):      " << int(2147483647 + 1) << "  -> MAX_INT: 2147483647" << endl;
	
	// it is correct
	cout << "unsigned(2147483647 + 1): " << unsigned(2147483647 + 1) << "  -> Unsigned MAX_INT: 4294967295" << endl;
	
	// arithmetic overflow: + operation causes overflow at compiler time
	cout << "long(2147483647 + 1):     " << long(2147483647 + 1) << "  -> Unsigned MAX_LONG: 2147483647" << endl;
	
	// arithmetic overflow: using + operation on a 4 byte value than casting the result to 8 byte value
	cout << "double(2147483647 + 1):   " << double(2147483647 + 1) << "4byte -> 8byte" << endl;

	return 0;
}
