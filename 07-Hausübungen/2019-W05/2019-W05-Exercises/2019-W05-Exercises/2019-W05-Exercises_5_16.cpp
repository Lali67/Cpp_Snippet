/* 2019-W02-Exercise_5_16.cpp :

Exercise 5.16
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
    cout << "This program...\n";
    cout << "-------- Test --------\n";

    cout << "abc   (startPos=0 endPos=3)  : ";
    permutationOfString("abc", 0, 3);
    cout << endl;

    cout << "abcde (startPos=0 endPos=3)  : ";
    permutationOfString("abcde", 0, 3);
    cout << endl;

    cout << "abcde (startPos=2 endPos=5)  : ";
    permutationOfString("abcde", 2, 5);
    cout << endl;

    cout << "abcde (startPos=1 endPos=4)  : ";
    permutationOfString("abcde", 1, 4);
    cout << endl;

    return 0;
}