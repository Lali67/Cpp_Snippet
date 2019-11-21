/* 2019-W02-Exercise_4_2.cpp :

Exercise 4.2
  Schreiben Sie eine Funktion, die einen String und eine ganze Zahl n als Parameter erhält und 
  die Cäsar-Kodierung des Eingangsstrings retourniert. Dabei ist jedes Zeichen im Eingangsstring 
  durch seinen n-ten Nachfolger zu ersetzen. Das Alphabet stellt man sich dabei zyklisch vor. 
  Ist n z.B. 3, so wird aus einem 'A' ein 'D' etc., 'Z' wird zu 'C'. 
  Testen Sie Ihre Funktion mit einem Hauptprogramm, das immer wieder einen String und 
  eine ganze Zahl einliest und den entsprechend codierten String ausgibt, so lange bis EOF gelesen wird, 
  z.B.:
	Eingabe: Test 1
	Ausgabe: Uftu
	Eingabe: Zar 2
	Ausgabe: Bct
	Eingabe: Ctrl-D
	Programmende

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
#include <string>
//#include <cmath>
//#include <exception> 

using namespace std;

// Function for Caesar Cypher 
string stringEncryptByCaesar(string msg, unsigned key)
{
	char ch; string encryptedMsg;

	for (int i = 0; msg[i] != '\0'; ++i) {
		ch = msg[i];
		//encrypt for lowercase letter
		if(ch >= 'a' && ch <= 'z') {
			ch = ch + key;
			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}
			encryptedMsg.push_back( ch );
		}
		//encrypt for uppercase letter
		 else if (ch >= 'A' && ch <= 'Z') {
		 ch = ch + key;
		 if (ch > 'Z') {
			 ch = ch - 'Z' + 'A' - 1;
		 }
		 encryptedMsg.push_back(ch);
		 }
	}
	
	return encryptedMsg;
}

int main()
{
	string aString; unsigned key;

	cout << "This program...\n";
	cout << "-------- Test --------\n";
	cout << "Test 1         : " << stringEncryptByCaesar("Test", 1) << endl;
	cout << "Zar 2          : " << stringEncryptByCaesar("Zar", 2) << endl;
	cout << "DanielSzoke 3  : " << stringEncryptByCaesar("DanielSzoke", 3) << endl;
	cout << endl;

	cout << "Get string      : "; cin >> aString;
	cout << "Get secret key  : "; cin >> key;
	cout << "Encrypted string: " << stringEncryptByCaesar(aString, key) << endl << endl;
	
	return 0;
	
}
