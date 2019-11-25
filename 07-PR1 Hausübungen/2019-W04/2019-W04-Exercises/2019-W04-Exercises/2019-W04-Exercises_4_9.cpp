/* 2019-W02-Exercise_4_9.cpp :


Exercise 4.9
  Schreiben Sie eine Funktion bool intTest(int n, char c), die prüft, ob die Ziffer c in der Zahl n vorkommt.


Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
//#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

bool intTest(int n, char c) {
	for (n; n; n /= 10) {
		if (n % 10 == (int(c) - '0')) return true;
	}
	return false;
}


int main()
{
	string aString;

	cout << "This program...\n";
	cout << "-------- Test --------\n";
	cout << "a=8 char=6     : " << intTest(8,'6') << endl;
	cout << "a=105 char=5   : " << intTest(105, '5') << endl;
	cout << "a=1024 b=2     : " << intTest(1024, '2') << endl;
	cout << endl;
	
	int a; char c;
	cout << "Get a (a>0 integer)  : "; cin >> a;
	cout << "Get char             : "; cin >> c;
	cout << intTest(a,c);
	return 0;
	
}
