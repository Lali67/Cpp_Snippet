#pragma once
/*
		https://en.cppreference.com/w/cpp/language/static

		A static member is shared by all objects of the class. 
		All static data is initialized to zero when the first object is created, 
		if no other initialization is present. We can't put it in the class definition but 
		it can be initialized outside the class as done in the following example by 
		redeclaring the static variable, using the scope resolution operator :: to identify 
		which class it belongs to.

		By declaring a function member as static, you make it independent of any particular object of 
		the class. A static member function can be called even if no objects of the class exist 
		and the static functions are accessed using only the class name and the scope 
		resolution operator ::.

		A static member function can only access static data member, other static member functions 
		and any other functions from outside the class.

		Static member functions have a class scope and they do not have access to the this pointer of 
		the class. You could use a static member function to determine whether some objects of 
		the class have been created or not.
*/
#include <string>
using namespace std;

class Date {
	private:
		int year;    // 1753-9999
		int month;   // 1-12
		int day;     // 1-31
		const static string STR_MONTHS[]; //only one data item for all objects
		const static string STR_DAYS[];
		const static int DAYS_IN_MONTHS[];
		const static int YEAR_MIN = 1753;
		const static int YEAR_MAX = 9999;

	public:
		static bool	isLeapYear(int y);
		static bool isValidDate(int y, int m, int d);
		static int  getDayOfWeek(int y, int m, int d);

		Date(int y, int m, int d);
		void	setDate(int y, int m, int d);
		int		getYear() const;
		int		getMonth() const;
		int		getDay() const;
		void	setYear(int y);
		void	setMonth(int m);
		void	setDay(int d);
		void	print() const;

		Date& nextDay();
		Date& previousDay();
		Date& nextMonth();
		Date& previousMonth();
		Date& nextYear();
		Date& previousYear();
};
