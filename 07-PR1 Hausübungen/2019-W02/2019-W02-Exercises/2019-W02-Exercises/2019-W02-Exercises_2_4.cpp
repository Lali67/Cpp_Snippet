/* 2019-W02-Exercise_2_4.cpp :

Exercise 2.4
 m Arbeiter k�nnen x St�ck eines Produktes in einer Stunde fertigen. 
 Wieviel St�ck k�nnen n Arbeiter in der gleichen Zeit herstellen?
 F�r diese einfache Schlussechnung hat ein (unbedarfter) Programmierer folgendes Programm geschrieben:

#include
using namespace std;
main() {
  int Arbeiter, Stueck, ArbeiterFrage;
  cin >> Arbeiter >> Stueck >> ArbeiterFrage;
  cout << Stueck/Arbeiter*ArbeiterFrage;
}

Nun erh�lt er aber f�r m=10 x=5 und n=2 die (mathematisch) falsche Antwort 0. 
Schlagen Sie zwei verschiedene M�glichkeiten vor, den auszugebenden Ausdruck so zu ver�ndern, 
dass die Reihenfolge der Operationen unver�ndert bleibt, 
das Programm aber (f�r beliebige Eingaben) das korrekte Ergebnis liefert. 
Beweisen Sie das, indem Sie ein entsprechend verbessertes Programm implementieren.

D�niel Sz�ke (11913915)
16.10.2019

*/

#include <iostream>

using namespace std;

void solution1() {
	double Arbeiter, Stueck, ArbeiterFrage;
	cout << "Geben Sie die drei Zahlen hier ein: \n";
	cin >> Arbeiter >> Stueck >> ArbeiterFrage;
	// Arbeiter=10(m) Stueck=5(x) ArbeiterFrage=2(n) -> 1
	cout << Stueck / Arbeiter * ArbeiterFrage;
}

void solution2() {
	int Arbeiter, Stueck, ArbeiterFrage;
	cout << "Geben Sie die drei Zahlen hier ein: \n";
	cin >> Arbeiter >> Stueck >> ArbeiterFrage;
	// Arbeiter=10(m) Stueck=5(x) ArbeiterFrage=2(n) -> 1
	cout << double(Stueck) / double(Arbeiter) * double(ArbeiterFrage); // cast the expression to double
}

int main()
{
	cout << "-----Solution 1 -----" << endl;
	solution1();
	cout << endl;
	cout << "-----Solution 2 -----" << endl;
	solution2();
	cout << endl;
}
