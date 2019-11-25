/* 2019-W02-Exercise_3_5.cpp :

Erstellen Sie die Additionstabelle und die Multiplikationstabelle modulo n. 
 Die Ausgabe für n=4 könnte zum Beispiel so aussehen:
Addition:
0 1 2 3
1 2 3 0
2 3 0 1
3 0 1 2

Multiplikation:
0 0 0 0
0 1 2 3
0 2 0 2
0 3 2 1


Dániel Szöke (11913915)
24.10.2019

*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

void calculateModulo(long n, int type = 0){
	//count leading space to print a number
	string max_leading_space{ "" };
	for (long i = 0; i <= to_string(n).length(); ++i) max_leading_space += " ";

	if( type==0)
		cout << endl << "Additionstabelle modulo " << n << endl;
	else
		cout << endl << "Multiplikationstabelle modulo " << n << endl;

	for (long i = 0; i < n; ++i) {
		for (long j = 0; j < n; ++j)
		{
			long value;
			if (type == 0) value= (i + j) % n;
			else value = (i * j) % n;
			string  leading_space = max_leading_space.substr(0,
				max_leading_space.length() - to_string(value).length());
			cout << leading_space << value;
		}
		cout << endl;
	}
}
int main()
{
	long n{ 1 };
	cout << "Dieses Programm erstellt eine Additions- und eine Multiplikationstabelle modulo n.\n";
	cout << "Geben Sie hier einen positiven Integer-Wert ein (n>1): ";	cin >> n;
	//Check n value
	if (n < 1)
		throw("n muss ein positiver Integer sein (n>1)");
	
	calculateModulo(n, 0);
	calculateModulo(n, 1);

	return 0;
}
