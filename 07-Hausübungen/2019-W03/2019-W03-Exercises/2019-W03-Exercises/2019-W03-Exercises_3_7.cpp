/* 2019-W02-Exercise_3_7.cpp :

Exercise 3.7
Überprüfen Sie, ob die Folge
n_i+1 = n_i / 2 für gerade n_i
n_i+1 = 3*n_i + 1 für ungerade n_i
für unterschiedliche (beliebige) positive Startwerte n_1 immer den Wert 1 erreicht.

Dániel Szöke (11913915)
26.10.2019

*/

#include <iostream>
//#include <cmath>
//#include <exception> 

using namespace std;


int main()
{
	long n{ 0 };

	cout << "This program...\n";
	cout << "Enter the starter (positive integer) value: ";	cin >> n;
	//Check n
	if (n < 1)
		throw("n must be positive");


	while (n > 1) {
		cout << n << " ";
		if (n % 2 == 0) n = n / 2;
		else
			n = 3 * n + 1;
	}
	cout << n;
	cout << endl;
	

	return 0;
}
