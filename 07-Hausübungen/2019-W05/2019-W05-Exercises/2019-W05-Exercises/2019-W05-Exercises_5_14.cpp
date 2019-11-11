/* 2019-W02-Exercise_5_14.cpp :

Exercise 5.14
 Die Funktionen f(n), g(n) und h(n) sind für natürliche Zahlen n wie folgt definiert:
    f(0) = 0
    g(0) = 0
    h(0) = 1
    f(n) = h(n)+g(n-1)
    g(n) = 2*f(n)
    h(n) = n*h(n-1)
 Schreiben Sie ein Programm, das die Berechnung der Funktion f für ein beliebiges n erlaubt.


Dániel Szöke (11913915)
08.11.2019

*/

#include <iostream>
#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <exception>

using namespace std;

long int f(int n);
long int g(int n);
long int h(int n);

long int f(int n)
{
    if (n == 0)
        return 0;

    // calculation of  f(n) = h(n)+g(n-1)
    return h(n) + g(n - 1);
}

long int g(int n)
{
    if (n == 0)
        return 0;

    // calculation of  g(n) = 2*f(n)
    return 2 * f( n );
}

long int h(int n)
{
    if (n == 0)
        return 1;

    // calculation of  h(n) = n*h(n - 1)
    return n * h(n - 1);
}

// main function
int main(void)
{

 
    cout << "-------- Test --------\n";
    cout << "f(n), n=4  : " << f(4) << endl;
    cout << "f(n), n=5  : " << f(5) << endl;
    cout << "f(n), n=16 : " << f(16) << endl;

	return 0;
}