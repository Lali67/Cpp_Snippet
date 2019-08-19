/* 
	Test Driver for Account class (TestAccount.cpp)
	https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp3_OOP.html#zz-7.
*/
#include <iostream>
#include "Account.h"

using namespace std;

int main() {
	Account a1(8111, 99.99);
	a1.print();     // A/C no: 8111 Balance=$99.99
	a1.credit(20);
	a1.debit(10);
	a1.print();     // A/C no: 8111 Balance=$109.99

	Account a2(8222);  // default balance
	a2.print();        // A/C no: 8222 Balance=$0.00
	a2.setBalance(100);
	a2.credit(20);
	a2.debit(200);  // Amount withdrawn exceeds the current balance!
	a2.print();     // A/C no: 8222 Balance=$120.00
	return 0;
}