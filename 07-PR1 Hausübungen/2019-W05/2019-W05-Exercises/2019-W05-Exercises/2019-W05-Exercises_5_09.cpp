/* 2019-W05-Exercise_5_09.cpp :

Exercise 5.9
  Schreiben Sie eine Funktion bool intTest(int n, char c), die pr�ft, ob die Ziffer c in der Zahl n vorkommt.
   Verwenden Sie keine Schleife in der Funktion.

D�niel Sz�ke (11913915)
08.11.2019

*/

#include <iostream>
//#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

bool intTest(int n, char c) {
	if(n/10){
		if (n % 10 == (int(c) - '0'))
			return true;
		else
			intTest(n/10,c);
	}
	else
	 return false;
}


int main()
{
	string aString;

	cout << "-------- Test --------\n";
	cout << "a=8 char=6     : " << intTest(8,'6') << endl;
	cout << "a=105 char=5   : " << intTest(105, '5') << endl;
	cout << "a=1024 b=2     : " << intTest(1024, '2') << endl;
	cout << endl;
	
	int a; char c;
	cout << "Geben Sie hier einen (a>0) Integer ein: "; cin >> a;
	cout << "Geben Sie hier einen Char ein         : "; cin >> c;
	cout << intTest(a,c);
	return 0;
	
}
