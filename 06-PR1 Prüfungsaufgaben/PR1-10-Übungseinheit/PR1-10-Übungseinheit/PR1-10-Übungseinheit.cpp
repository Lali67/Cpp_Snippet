/*Schreiben Sie eine Funktion int maxi(int* vals1, int* vals2, int len), 
die zwei Arrays von Integer Werten und deren Länge als Parameter erhält 
und jene Indexposition zurückliefert, an der die Summe der Werte 
aus den beiden Eingangsarrays maximal wird.
Eingabe: 2482  7352   4    
Ergebnis : 2 (weil 8 + 5 = 13 größer als alle anderen Summen ist)*/

#include <iostream>
using namespace std;
class X {
protected:
int x;
public:
	X(int i = 6): x {i} {}
	virtual void print() const { cout << x; }
	void operator-(const X rop) { this->print(); rop.print();}
};

class Y : 
	public X {void print() const { cout << '=' << x; }};

int main() {
	X x {9};
	Y y;
	x -y;
	y -x;
	return 0;
}


