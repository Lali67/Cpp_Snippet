#pragma once

/*
	https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp3_OOP.html#zz-7.
	A class called Account, which models a bank account. 
	It contains:

    Two private data members: accountNumber (int) and balance (double), 
		which maintains the current account balance.
    Public functions credit() and debit(), which adds or subtracts the given amount from the balance, 
		respectively. The debit() function shall print "amount withdrawn exceeds the current balance!" 
		if amount is more than balance.
		A public function print(), which shall print "A/C no: xxx Balance=xxx" 
		(e.g., A/C no: 991234 Balance=$88.88), with balance rounded to two decimal places.

*/

class Account {
	private:
		int accountNumber;
		double balance;

	public:
		Account(int accountNumber, double balance = 0.0);

		int		getAccountNumber() const;
		double	getBalance() const;
		void	setBalance(double balance);
		void	credit(double amount);
		void	debit(double amount);
		void	print() const;
};

