/* 2019-W02-Exercise_5_12.cpp :

Exercise 5.12
 Schreiben Sie eine Funktion, die eine natürliche Zahl als Parameter erhält und 
 die Anzahl der möglichen Darstellungen der Zahl als eine Summe aufeinanderfolgender natürlicher Zahlen retourniert. 
 Für 15 würde z.B. 3 retourniert, da 15 dargestellt werden kann als 7+8, 4+5+6, 1+2+3+4+5.
 Verwenden Sie keine Schleife in der Funktion.

Dániel Szöke (11913915)
08.11.2019

*/

#include <iostream>
#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <exception>

using namespace std;

long int specialSerious(int n)
{
    if (n < 3)
        return 0;
    if (n == 3)
        return 3;

    // calculation of  Fn = 2*(Fn-1) + Fn-2 * Fn-3
    return ((2 * specialSerious(n - 1)) + specialSerious(n - 2) * specialSerious(n - 3));
}

// main function
int main(void)
{

    cout << "This program...\n";
    cout << "-------- Test --------\n";
    cout << "Fn = 2*(Fn-1) + Fn-2 * Fn-3, n=4  : " << specialSerious(4) << endl;
    cout << "Fn = 2*(Fn-1) + Fn-2 * Fn-3, n=5  : " << specialSerious(5) << endl;
    cout << "Fn = 2*(Fn-1) + Fn-2 * Fn-3, n=16 : " << specialSerious(16) << endl;

	return 0;
}