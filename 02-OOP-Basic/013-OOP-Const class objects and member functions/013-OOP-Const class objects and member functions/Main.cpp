/*
	https://www.learncpp.com/cpp-tutorial/810-const-class-objects-and-member-functions/

	--- Const classes ---
		Similarly, instantiated class objects can also be made const by using the const keyword. 
		Initialization is done via class constructors:
			const Date date1; // initialize using default constructor
			const Date date2(2020, 10, 16); // initialize using parameterized constructor
			const Date date3 { 2020, 10, 16 }; // initialize using parameterized constructor (C++11)

		Once a const class object has been initialized via constructor, any attempt to modify the member
		variables of the object is disallowed, as it would violate the const-ness of the object.

	--- Const member functions ---
		A const member function is a member function that guarantees it will not modify the object or
		call any non-const member functions (as they may modify the object). Initialization is:
			int getValue() const { return m_value; }
		Now, consider the following line of code:
		    std::cout << something.getValue();
	
		Perhaps surprisingly, this will also cause a compile error, even though getValue() doesn’t do 
		anything to change a member variable! It turns out that const class objects can only explicitly 
		call const member functions, and getValue() has not been marked as a const member function.
*/

#define _CRT_SECURE_NO_WARNINGS		// for localtime function

#include <iostream>
#include <string>
#include <ctime>

using namespace std;


class Something
{
	private:
		string m_value;

	public:
		Something(const string& value = "") 
				{ m_value = value; }
		// getValue() for const objects
		const string& getValue() const 
				{ return m_value; }
		// getValue() for non-const objects
		string& getValue() 
				{ return m_value; } 
		friend ostream& operator << (ostream& os, const Something& st)
				{
					os<< st.m_value;
					return os;
				}
};


class Date
{
	private:
		int		m_year;
		int		m_month;
		int		m_day;
		string	m_msg;

	public:
		Date(int year, int month, int day, string dt_msg):
			m_year(year), m_month(month), m_day(day), m_msg(dt_msg)
		{
		}

		// setDate() cannot be const, modifies member variables
		void setDate(int year, int month, int day, string dt_msg)
		{
			m_year = year;
			m_month = month;
			m_day = day; 
			m_msg = dt_msg;
		}

		// The following getters can all be made const
		int getYear() const
				{ return m_year; }
		int getMonth() const 
				{ return m_month; }
		int getDay() const 
				{ return m_day; }
		string getDt_Msg() const
			{ return m_msg; }
};

/* 
	note: We're passing date by const reference here to avoid making a copy of date
	printDate function, date is treated as a const object -->
			make getYear(), getMonth() and getDay() const
*/
void printDate(const Date& date)
{
	std::cout << "\n"<< date.getDt_Msg() << date.getYear() << "/" << date.getMonth() 
		<< "/" << date.getDay() << "\n";
}

int main()
{
	Something something;
	// calls non-const getValue()
	something.getValue() = "Test Non-Const getValue() \n";	
	std:cout << something.getValue();
	std::cout << something;

	// const class
	const Something something2 ("Test const Class and Const getValue()\n");
	// calls const getValue();
	std::cout << something2.getValue();
	std::cout << something2;

	// current date/time based on current system
	time_t now = time(0);
	tm* ltm = localtime(&now);
	Date date_ld(	1900 + ltm->tm_year, 
					1+ltm->tm_mon, 
					ltm->tm_mday, 
					"Local Date: ");
	printDate(date_ld);

	return 0;
}