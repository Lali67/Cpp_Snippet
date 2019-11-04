#include <iostream>
using namespace std;

bool f(int a, int b) {
	cout << a;
	return a > b;
}

int main()
{
	int a{ 8 };
	int b{ 1 };
	int c{ 4 };

	if (f(a, 814) + f(b, -814) - f(c, a)) {
		a = a + 100;
		cout << a + c * 10;
	}
	else {
		c = c + 200;
		cout << c + b * 10;
	}

	return 0;
}