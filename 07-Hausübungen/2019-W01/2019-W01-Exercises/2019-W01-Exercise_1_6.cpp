/* 2019-W01-Exercise_1_6.cpp: 

Exercise 1.6
Lesen Sie eine Zahl n ein und berechnen Sie die Summe aller nat�rlichen Zahlen bis n. (Probleme?) 

D�niel Sz�ke (11913915)
12.10.2019
*/

#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	double n, Summe;
	cout << "Dieses Programm berechnet die Summe aller natuerlichen Zahlen bis n.\n";
	cout << "n: ";	cin >> n;
	Summe = n*(n+1)/2;
	cout << "Summe: "<<Summe<<endl;

	return 0;
}

