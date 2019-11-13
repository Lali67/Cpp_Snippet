/* 2019-W05-Exercise_5_18.cpp :

Exercise 5.18
  Schreiben Sie eine Funktion, die als Parameter einen String (Datentyp string) erhält und 
  alle möglichen Permutationen der im String enthaltenen Zeichen ausgibt. (Sie können davon ausgehen, 
  dass jedes Zeichen nur einmal auftritt.)
  Z.B.:
    Parameter: abc
    Ausgabe: abc acb bac bca cab cba

Dániel Szöke (11913915)
11.11.2019

*/

#include <iostream>
//#include <vector>
//#include <algorithm>
#include <cmath>
//#include <exception>
#include <string>

using namespace std;

void permutationOfString(string str, int i, int n)
{
    // base condition
    if (i == n - 1)
    {
        cout << str << " ";
        return;
    }

    // process each character of the remaining string
    for (int j = i; j < n; j++)
    {
        // swap character at index i with current character
        swap(str[i], str[j]);     
        // recur for string [i+1, n-1]
        permutationOfString(str, i + 1, n);
        // backtrack (restore the string to its original state)
        swap(str[i], str[j]);
    }
}
int main()
{
    int i{ 123 }, j{ 2468 };

    cout << "-------- Test --------\n";

    cout << "123  : ";
    permutationOfString(to_string(i), 0, 3);
    cout << endl;

    cout << "2468 : ";
    permutationOfString(to_string(j), 0, 4);
    cout << endl;


    return 0;
}