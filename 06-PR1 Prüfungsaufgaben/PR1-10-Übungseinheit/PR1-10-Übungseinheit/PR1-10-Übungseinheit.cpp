/*Schreiben Sie eine Funktion int maxi(int* vals1, int* vals2, int len), 
die zwei Arrays von Integer Werten und deren Länge als Parameter erhält 
und jene Indexposition zurückliefert, an der die Summe der Werte 
aus den beiden Eingangsarrays maximal wird.
Eingabe: 2482  7352   4    
Ergebnis : 2 (weil 8 + 5 = 13 größer als alle anderen Summen ist)*/

#include <iostream>
using namespace std;
class X {
	int a;
public:
	X(int n = 3) : a(n) { cout << a; cout << " X(int n = 3)" <<endl; }
	X(const X& x): a {x.a} {
		cout << 7*a; 
		cout << " X(const X& x)" << endl;
	}
	~X() {cout << a; 
	cout << " ~X()" << endl;
	}
	X& operator=(const X& x) {
		cout << a << x.a;
		cout << " X& operator=" << endl;
		return *this;}
};

void f(X a, const X& b) {
	a = b;
}

int main() {
	X x, y {5};
	f(x,y);
	return 0;
}
