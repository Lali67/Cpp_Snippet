/* 2019-W05-Exercise_5_01.cpp :

Exercise 5.1
  Schreiben Sie zwei Funktionen, die jeweils eine Zeichenkette als Parameter erhalten und 
  die umgekehrte Zeichenkette (also die ursprüngliche Zeichenkette von rechts nach links gelesen) retournieren. 
  Verwenden Sie dazu in der ersten Funktion eine Schleife und in der zweiten Funktion keine Schleife. 
  Es dürfen nur die in der Legende angeführten Methoden der Klasse string verwendet werden.

Dániel Szöke (11913915)
08.11.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;

string reverseStringbyLoop(string aString) {
	string result{ "" }; int counter{0};
	
	counter = aString.length();
	while (0 < counter)
		result.push_back(aString[--counter]);

	return result;
}

string reverseStringbyRecursion(string aString) {
		if (aString.length() - 2 > 0) {
			string first_char = aString.substr( 0, 1 );
			string last_char  = aString.substr( aString.length() - 1, 1);
			string middle     = aString.substr( 1, aString.length() - 2);

			return last_char + reverseStringbyRecursion(middle) + first_char;
		}
		else
			return "";
}

int main()
{
	string aString; bool flip{true};

	//On a Unix - based machine, signal EOF by typing Ctrl + D and Enter.
	//On a Windows machine, signal EOF by typing Ctrl + Z and Enter.
	cout << "Geben Sie hier einen String ein: ";  
	while (cin >> aString) {
		if(flip)
			cout << "String (Loop)       ->" << reverseStringbyLoop(aString) << endl;
		else 
			cout << "String (Recursion)  ->" << reverseStringbyRecursion(aString) << endl;

		if (flip) 
			flip = false;
		else
			flip = true;

		cout << "Geben Sie hier einen String ein: ";
	}
}
