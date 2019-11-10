/* 2019-W02-Exercise_5_13.cpp :

Exercise 5.13
 Die Folge Fn ist definiert durch die Rekursion Fn=2*Fn-1+Fn-2*Fn-3
 mit den Startwerten F0=1, F1=1 und F2=1
 Schreiben Sie eine Funktion, die den Wert Fn an einer beliebigen Position n berechnet.

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