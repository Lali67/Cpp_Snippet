/* 2019-W02-Exercise_4_3.cpp :

Exercise 4.3
  Schreiben Sie eine Funktion, die einen String und ein Zeichen als Parameter erhält und 
  eine ganze Zahl retourniert. Der Retourwert soll die Anzahl des Auftretens des Zeichens im String sein. 
  Testen Sie ihre Funktion mit einem Hauptprogramm, das immer wieder einen String einliest und 
  dann eine Liste der Häufigkeiten aller im String verwendeten Zeichen ausgibt, 
  bis EOF eingelesen wird, 
  z.B.:
	Eingabe: achtung,test
	Ausgabe: ,(1) a(1) c(1) e(1) g(1) h(1) n(1) s(1) t(3) u(1)
	Eingabe: blabla
	Ausgabe: a(2) b(2) l(2)
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
const int MAX_ASCII_CHAR = 255;

int getCharFreq(string str, char ch)
{
	return std::count(str.begin(), str.end(), ch);
}

//  getCharsWithFreq(string str) 
//  gets the character and its frequency
string getCharsWithFreq(string str)
{
	string result{ "" };
	// 'freq[]' implemented as hash table 
	int freq[MAX_ASCII_CHAR];

	// initialize all elements of freq[] to 0
	// char(32)=White space
	for (int i = 32; i < MAX_ASCII_CHAR; i++) {
		freq[i] = getCharFreq(str, i);
		string s;
		if (freq[i]) {
			s = (char)i;
			if (i == 32)//white space
				result.append("' '");
			else
				result.append(s);
			result.append("("+ std::to_string(freq[i])+") ");
		}
	}

	return result;
}


int main()
{
	string aString;

	cout << "This program...\n";
	cout << "-------- Test --------\n";
	cout << "Test 1         : " << getCharsWithFreq("Test 1         :") << endl;
	cout << "Zar 2          : " << getCharsWithFreq("Zar 2          :") << endl;
	cout << "DanielSzoke 3  : " << getCharsWithFreq("DanielSzoke 3  :") << endl;
	cout << endl;
	cout << "Get string      : ";
	
	while (cin >> aString) {
		cout << " " << getCharsWithFreq(aString) << endl;
		cout << "Get string      : ";
	}

	return 0;
	
}
