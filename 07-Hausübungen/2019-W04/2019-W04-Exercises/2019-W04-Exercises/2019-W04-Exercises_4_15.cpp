/* 2019-W02-Exercise_4_15.cpp :

Exercise 4.15
(*) Schreiben Sie eine Funktion, die zwei Strings als Parameter erhält. 
Jeder der Eingangsstrings soll eine natürliche Zahl in Dezimalschreibweise enthalten. 
Zu retournieren ist ein String, der das Ergebnis der Addition der beiden Zahlen 
in Dezimalschreibweise enthält. Die Strings dürfen aber nicht in Zahlen umgewandelt werden, 
es ist vielmehr der in der Schule gelernte Algorithmus zum Addieren von zwei Zahlen 
(Ziffer für Ziffer von rechts nach links) zu implementieren.

Prüfen Sie, dass Sie auf diese Weise wesentlich größere Zahlen korrekt addieren können, 
als es Ihnen im Datenbereich int möglich ist.


Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

// Function for finding sum of larger numbers 
string find10BaseSumFrom(string numStr1, string numStr2)
{
	string result{ "" };
	int n1{ 0 }, n2{ 0 }, diff{ 0 }, carry{0};
	int sum2Digits{ 0 };

	// Make sure length of numStr2 is larger due to for-cycle 
	if (numStr1.length() > numStr2.length()) swap(numStr1, numStr2);
	
	// Init values
	n1 = numStr1.length();
	n2 = numStr2.length();
	diff = n2 - n1;

	// Traverse from end of both strings 
	for (int i = n1 - 1; i >= 0; i--)	{
		// According to school math, compute sum of current digits and carry 
		sum2Digits = ((numStr1[i] - '0') +	(numStr2[i + diff] - '0') + carry);
		result.push_back(sum2Digits % 10 + '0');
		carry = sum2Digits / 10;
	}

	// Add remaining digits of numStr2[] 
	for (int i = n2 - n1 - 1; i >= 0; i--)	{
		sum2Digits = ((numStr2[i] - '0') + carry);
		result.push_back(sum2Digits % 10 + '0');
		carry = sum2Digits / 10;
	}

	// Add remaining carry 
	if (carry) result.push_back(carry + '0');

	// reverse resultant string 
	reverse(result.begin(), result.end());

	return result;
}

int main()
{
	string num1, num2;

	cout << "This program...\n";
	cout << "-------- Test --------\n";
	cout << "a= 12 b= 198111; a+b= " << find10BaseSumFrom("12","198111") <<endl;
	cout << "a= 9986 b= 46 ;  a+b= " << find10BaseSumFrom("9986", "46") << endl;
	cout << endl;

	cout << "Get first integer number (n>0) : "; cin >> num1;
	cout << "Get second integer number (n>0): "; cin >> num2;
	cout << "Sum of two nummbers: " << find10BaseSumFrom(num1, num2) << endl << endl;
}
