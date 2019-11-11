/* 2019-W02-Exercise_5_15.cpp :

Exercise 5.15
  Schreiben Sie eine Funktion int stack(), durch deren Aufruf der Stack zum Überlaufen gebracht wird. 
  (Anmerkung: Dieser Überlauf, der normalerweise als "stack overflow" bezeichnet wird, 
  wird auf den Übungsrechnern durch den Abbruch des Programms und die Ausgabe der Fehlermeldung "Segmentation fault" 
  angezeigt.) 
  Wie oft muss die Funktion stack() rekursiv aufgerufen werden, bis es zum stack overflow kommt? 
  Wie können Sie das beschleunigen und wie können Sie aus Ihren Ergebnissen die Größe des Stacks abschätzen?

Dániel Szöke (11913915)
08.11.2019

*/

#include <iostream>
//#include <vector>
//#include <algorithm>
#include <cmath>
//#include <exception>

using namespace std;


// These will be set at the top of main()
static char* _topOfStack;
static int _maxAllowedStackUsage;

int GetCurrentStackSize()
{
    char localVar;
    int curStackSize = (&localVar) - _topOfStack;
    // in case the stack is growing down
    if (curStackSize < 0) curStackSize = -curStackSize;
    return curStackSize;
}

int stack()
{
    int curStackSize = GetCurrentStackSize();
    cout << "MyRecursiveFunction:  curStackSize= " << curStackSize << endl;

    if (curStackSize < _maxAllowedStackUsage) 
        return 1+stack();
    else
    {
        printf(" Segmentation fault: stack is overflowed!\n");
    }
    return 0;
}

int main()
{
    char topOfStack;
    _topOfStack = &topOfStack;
    _maxAllowedStackUsage = pow(2,16);  // or whatever amount you feel comfortable allowing

    cout << "\nStack Funktion heisst " << stack() << " times!\n";

    return 0;
}