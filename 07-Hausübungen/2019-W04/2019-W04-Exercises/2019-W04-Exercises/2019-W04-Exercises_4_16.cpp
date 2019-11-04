/* 2019-W02-Exercise_4_16.cpp :

Exercise 4.16
  (*) Schreiben Sie eine Funktion, die zwei Strings als Parameter erhält. 
  Jeder der Eingangsstrings soll eine natürliche Zahl in Dezimalschreibweise enthalten. 
  Zu retournieren ist ein String, der das Ergebnis der Multiplikation der beiden Zahlen 
  in Dezimalschreibweise enthält. Die Strings dürfen aber nicht in Zahlen umgewandelt werden, 
  es ist vielmehr der in der Schule gelernte Algorithmus zum Multiplizieren von zwei Zahlen 
  zu implementieren. 
  (Zur Realisierung der nowendigen Additionen kann die Funktion aus Beispiel 15 eingesetzt werden.)
  
  Prüfen Sie, dass Sie auf diese Weise wesentlich größere Zahlen korrekt multiplizieren können, 
  als es Ihnen im Datenbereich int möglich ist.

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

// Calculate sum of "large" numbers 
string get10BaseSumFrom(string numStr1, string numStr2)
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
	int n = result.length();
	for (int i = 0; i < n / 2; i++)
		swap(result[i], result[n - i - 1]);

	return result;
}

// Calculate sum of "large" numbers 
string get10BaseMultiplyFrom(string numStr1, string numStr2)
{
	string result{ "0" }, zeros{ "" }, partialResult{""};
	int n1{ 0 }, n2{ 0 }, sum{ 0 }, carry{0};

	// Make sure length of numStr1 is larger due to shorter time of for-cycle 
	if (numStr2.length() > numStr1.length()) swap(numStr1, numStr2);
	n1 = numStr1.length(); 
	n2 = numStr2.length();

	// Go from right to left in num2 
	for (int i = n2 - 1; i >= 0; i--)
	{
		carry = 0; partialResult = "";
		// Go from right to left in num1              
		for (int j = n1 - 1; j >= 0; j--)
		{
			// Compute sum of current, multiplicated digits and carry 
			sum = ((numStr1[j] - '0') * (numStr2[i] - '0') + carry);
			partialResult.push_back(sum% 10 + '0');
			carry = sum / 10;
		}
		// Add remaining carry 
		if (carry) partialResult.push_back(carry + '0');
		// reverse resultant string 
		reverse(partialResult.begin(), partialResult.end());
		// Add zeros to the end
		partialResult += zeros;
		zeros += "0";
		// Add partialResult to result
		result = get10BaseSumFrom(result, partialResult);
		
	}

	return result;
}

int main()
{
	string num1, num2;
	cout << "-------- Test --------\n";
	cout << "a= 12 b= 198111; a*b= " << get10BaseMultiplyFrom("12","198111") <<endl;
	cout << "a= 9986 b= 46 ;  a*b= " << get10BaseMultiplyFrom("9986", "46") << endl;
	cout << endl;

	cout << "Erster Integer (n>0) : "; cin >> num1;
	cout << "Zweiter Integer (n>0): "; cin >> num2;
	cout << "Summe der beiden Zahlen: " << get10BaseMultiplyFrom(num1, num2) << endl << endl;
}
