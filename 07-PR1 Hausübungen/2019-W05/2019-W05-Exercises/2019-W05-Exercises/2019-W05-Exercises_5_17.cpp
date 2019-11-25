/* 2019-W05-Exercise_5_17.cpp :

Exercise 5.16
  Schreiben Sie eine Funktion, die als Parameter einen String (Datentyp string) erhält und 
  alle möglichen Permutationen der im String enthaltenen Zeichen ausgibt. (Sie können davon ausgehen, 
  dass jedes Zeichen nur einmal auftritt.)
  Z.B.:
    Parameter: abc
    Ausgabe: abc acb bac bca cab cba


Exercise 5.17
  Wie Aufgabe 16, allerdings dürfen Zeichen auch mehrfach auftreten.


Dániel Szöke (11913915)
11.11.2019

*/

#include <iostream>
#include <vector>
//#include <algorithm>
#include <cmath>
//#include <exception>

using namespace std;


// compare is used by the library qsort() function to sort an array of chars 
int compare(const void* a, const void* b);

//recursively prints all repeated permutations of the given string. 
void allpermutationOfStringRecur(vector<char> str, vector<char> data, int last, int index) {
    
    // One by one fix all characters at the given index 
    for (int i = 0; i < str.size(); i++)
    {
        // Fix the ith character at index and if this is not the last index 
        // then recursively call  for higher indexes  
        data[index] = str[i];
        if (index == last) {
            for (auto const& item : data) cout << item;
            cout << " ";
        }
        else 
            allpermutationOfStringRecur(str, data, last, index + 1);
    }
}

// allpermutationOfString sorts input string and
// calls allpermutationOfStringRecur() for printing all permutations
void allpermutationOfString(vector<char> str)
{ 
    qsort(str.data(), str.size(), sizeof(char), compare);
    // Now print all permutations 
    vector<char> data( str.size(), ' ' ); 
    allpermutationOfStringRecur(str, data, str.size() - 1, 0);
}

// Needed for library function qsort()  
int compare(const void* a, const void* b)
{
    return (*(char*)a - *(char*)b);
}


int main()
{

    cout << "-------- Test --------\n";

    vector<char> str{ 'A','B','C' };
    cout << "Alle Permutationen mit Repetition von ";
    for (auto const& item : str) cout << item; cout << " sind: " << endl;
    allpermutationOfString(str);
    cout << endl;

    vector<char> str2{ 'H','E','L','P' };
    cout << "Alle Permutationen mit Repetition von ";
    for (auto const& item : str2) cout << item; cout << " sind: " << endl;
    allpermutationOfString(str2);
    cout << endl;

    return 0;
}