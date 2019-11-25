/* 2019-W02-Exercise_3_12.cpp :

Exercise 3.12
  Eine nat�rliche Zahl hei�t perfekt, wenn die Summe ihrer echten Teiler (das sind alle Teiler, 
  die kleiner als die Zahl selbst sind) gleich gro� ist, wie die Zahl. 
  Zum Beispiel ist 6 eine perfekte Zahl, da 6=1*2*3 und 1+2+3=6. Falls die Summe der echten Teiler 
  kleiner ist als die Zahl, hei�t die Zahl defizient. 
  Falls die Summe der echten Teiler gr��er ist als die Zahl, hei�t die Zahl abundant. 
  Schreiben Sie ein Programm, das eine nat�rliche Zahl einliest und ausgibt, ob die eingelesene Zahl perfekt,
  defizient oder abundant ist.
	Eingabe  Ausgabe   Begr�ndung
	5     defizient   1 ist einziger echter Teiler
	6     perfekt     1+2+3=6
	12    abundant    1+2+3+4+6=16>12

D�niel Sz�ke (11913915)
26.10.2019

*/

#include <iostream>

using namespace std;

string IsPerfectNumber(unsigned long n) {
	unsigned long divisor{ 1 }, sumDivisors{ 0 };
	string result{ "" };

	while (divisor < n ) {
		if (n % divisor == 0) sumDivisors += divisor;
		divisor++;
	}
	
	if (n == sumDivisors) result = "perfekt";
	else if (n > sumDivisors) result = "defizient";
			else  result = "abundant";
	
	return result;
}

int main()
{
	
	
	cout << "------------Test------------" << endl;
	cout << "5        :  " << IsPerfectNumber(5) << endl;
	cout << "6        :  " << IsPerfectNumber(6) << endl;
	cout << "12       :  " << IsPerfectNumber(12) << endl;
	cout << "28       :  " << IsPerfectNumber(28) << endl;
	cout << "496      :  " << IsPerfectNumber(496) << endl;
	cout << "8128     :  " << IsPerfectNumber(8128) << endl;
	cout << "33550336 :  " << IsPerfectNumber(33550336) << endl;
	// next perfect number: 8589869056
	cout << endl;
	
	// Get from the data from user to function
	unsigned long n;
	cout << "Ist die Zahl defizient, perfekt oder abundant?\n";
	cout << "Bitte geben Sie hier die Zahl ein: "; cin >> n;
	cout << "Resultat: " << IsPerfectNumber(n) << endl;
	
	return 0;
}
