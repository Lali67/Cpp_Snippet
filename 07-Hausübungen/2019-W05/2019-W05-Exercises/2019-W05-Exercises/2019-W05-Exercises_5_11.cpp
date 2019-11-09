/* 2019-W02-Exercise_5_11.cpp :

Exercise 5.11
  Schreiben Sie eine Funktion, die einen String als Parameter erhält und einen "vermixten" String retourniert. 
  Dabei sollen im Ergebnis zunächst alle Zeichen mit ungeradem Index im Parameter in der ursprünglichen Reihenfolge 
  enthalten sein und daran anschließend alle Zeichen mit geradem Index im Parameter in umgekehrter Reihenfolge, 
  
  z.B.:
     Parameter: "abcdefghi"
     Returnwert: "bdfhigeca"

  Verwenden Sie keine Schleife in der Funktion.


Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
//#include <vector>
#include <string>
//#include <cmath>
//#include <cassert>
//#include <exception> 

using namespace std;

string remixedString(string str, string oddStr, string evenStr, int n=0) {
    if (n < str.length()) {

        if( (n+1) %2 == 0)
            evenStr.push_back(str.at(n));
        if( (str.length()-n) % 2 == 1)
            oddStr.push_back(str.at(str.length()-n-1));

        return remixedString(str, oddStr, evenStr, ++n);
    }
    else
        return evenStr + oddStr;
}

string remixedString(string str) {
    
    return remixedString(str,"","",0);
}

int main()
{
	string aString;

	cout << "This program...\n";
	cout << "-------- Test --------\n";
    string str1{ "abcdefghi" };
    cout << "abcdefghi :" << remixedString(str1) << endl;

    string str2{ "einen \"vermixten\" String" };
    cout << "einen \"vermixten\" String :" << remixedString(str2) << endl;

	return 0;
	
}
