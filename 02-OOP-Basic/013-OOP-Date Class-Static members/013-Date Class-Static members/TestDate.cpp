/* 
	Test Driver Program (TestDate.cpp) 
	https://en.cppreference.com/w/cpp/language/static
	https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp5_OOPExamples.html#zz-5.
*/
#include <iostream>
#include <stdexcept>
#include "Date.h"

int main() {
	Date d1(2012, 1, 1);
	d1.print();  // Sunday, 1 Jan 2012
	d1.nextDay().print();  // Monday, 2 Jan 2012
	d1.print();  // Monday, 2 Jan 2012

	d1.setDate(2012, 1, 31);
	d1.print();  // Tuesday, 31 Jan 2012
	d1.nextDay().print();  // Wednesday, 1 Feb 2012

	d1.setDate(2012, 2, 28);
	d1.print();  // Tuesday, 28 Feb 2012
	d1.nextDay().print();  // Wednesday, 29 Feb 2012

	d1.setDate(2012, 12, 31);
	d1.print();  // Monday, 31 Dec 2012
	d1.nextDay().print();  // Tuesday, 1 Jan 2013

 //   Date d2(2011, 2, 29);  // abrupt termination!
 //   d2.print();

	try {  // graceful handling of exception
		Date d3(2011, 2, 29);
		d3.print();
	}
	catch (invalid_argument & ex) {
		cout << ex.what() << endl;  // Error: Invalid day (1-28|29|30|31)!
	}
	cout << "Next Statement after try-catch" << endl;

	try {  // graceful handling of exception
		Date d4(9999, 12, 30);
		d4.nextDay().print(); // Friday, 31 Dec 9999
		d4.nextDay();
		d4.print();
	}
	catch (out_of_range & ex) {
		cout << ex.what() << endl;  // Error: Next day is outside the valid range!
	}

	Date d5(2012, 1, 1);
	d5.previousDay().print();  // Saturday, 31 Dec 2011

	Date d6(2012, 3, 31);
	d6.nextMonth().print();  // Monday, 30 Apr 2012

	Date d7(2012, 3, 31);
	d7.previousMonth().print();  // Wednesday, 29 Feb 2012

	Date d8(2012, 2, 29);
	d8.nextYear().print(); // Thursday, 28 Feb 2013

	Date d9(2012, 2, 29);
	d9.previousYear().print();  // Monday, 28 Feb 2011
}