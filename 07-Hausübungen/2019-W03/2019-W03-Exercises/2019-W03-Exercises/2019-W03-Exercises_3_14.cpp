/* 2019-W02-Exercise_3_14.cpp :

Exercise 3.14
  Schreiben Sie ein Programm, das eine ganze Zahl einliest und die Anzahl der Inversionen 
  in der eingegebenen Zahl ausgibt. Als Inversionen für eine bestimmte Ziffer (Ausgangsziffer) 
  der Zahl bezeichnen wir alle Ziffern, die in der Zahl nach der Ausgangsziffer stehen und 
  kleiner sind als diese. 
  Zum Beispiel:
	Eingabe: 53278     Ausgabe: 3
	Da 3 hinter 5 steht, 2 hinter 5 steht und 2 hinter 3 steht.

Dániel Szöke (11913915)
26.10.2019

*/

#include <iostream>
#include <string>

using namespace std;

int CountInversion(unsigned long n) {
	string numberString;
	int result{ 0 };

	numberString = std::to_string(n);
	for(int i=0; i<numberString.length(); i++)	{	
		for (int j = i; j > -1; j--) {
			if (numberString[j] > numberString[i]) result++;
		}
	}
	
	return result;
}

int main()
{
	unsigned long n{1};

	cout << "Dieses Programm gibt die Anzahl der Inversionen in der eingegebenen Zahl aus.\n";
	cout << "Geben Sie hier einen Integer-Wert ein (n, n>0): "; cin >> n;
	cout << "Resultat :" << CountInversion(n) << endl;

	return 0;
}
