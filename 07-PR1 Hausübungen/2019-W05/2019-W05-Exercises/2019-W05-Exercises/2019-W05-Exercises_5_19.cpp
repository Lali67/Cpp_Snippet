/* 2019-W05-Exercise_5_19.cpp :

Exercise 5.19
  Schreiben Sie eine Funktion, die als Parameter eine natürliche Zahl erhält und alle möglichen Permutationen 
  der in der Zahl vorkommenden Ziffern ausgibt. (Sie können davon ausgehen, 
  dass jede Ziffer nur einmal eingegeben wird.)


Dániel Szöke (11913915)
11.11.2019

*/

#include <iostream>
#include <vector>
//#include <algorithm>
#include <cmath>
//#include <exception>
#include <string>

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

    vector<char> str;
    int i{ 123 }, j{2468};

    for (auto const& item : std::to_string(i)) str.push_back(item);
    cout << "Alle Permutationen mit Repetition von ";
    for (auto const& item : str) cout << item; cout << " sind: " << endl;
    allpermutationOfString(str);
    cout << endl;

    vector<char> str2;
    for (auto const& item : std::to_string(j)) str2.push_back(item);
    cout << "Alle Permutationen mit Repetition von ";
    for (auto const& item : str2) cout << item; cout << " sind: " << endl;
    allpermutationOfString(str2);
    cout << endl;

    return 0;
}