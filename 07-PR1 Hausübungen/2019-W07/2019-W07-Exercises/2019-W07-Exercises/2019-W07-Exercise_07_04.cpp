/*2019 - W07 - Exercise_7_04.cpp :

Exercise 7.4
  Schreiben Sie eine Funktion, welche die Fakultät einer gegebenen Zahl n berechnet, 
  ohne dass Sie eine ''if''-Anweisung, eine ''switch''-Anweisung oder eine Schleife verwenden.

*/

#include <iostream>

using namespace std;

long long factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main()
{
    cout << " 8  Factorial is " << factorial(8) << endl;
    cout << " 12 Factorial is " << factorial(12) << endl;
    cout << " 16 Factorial is " << factorial(16) << endl;

    return 0;
}