#include <iostream>
#include "Book.h"
using namespace std;

int main() {
	Author paul("Paul Jones", "@somewhere.com", 'n');
	// Invalid email! Set to empty string.
	// Invalid gender! Set to 'u' (unknown).
	paul.setEmail("paul@");
	// Invalid email! Set to empty string.
	paul.print();
	// Paul Jones (u) at
	cout << "------------------------------------\n\n";

	// Declare and construct an instance of Author
	Author peter("Peter Jones", "peter@somewhere.com", 'm');
	peter.print();  // Peter Jones (m) at peter@somewhere.com

	peter.setEmail("peter@xyz.com");
	peter.print();   // Peter Jones (m) at peter@xyz.com
	// 'C++ for Dummies' by Peter Jones (m) at peter@somewhere.com

	// Declare and construct an instance of Book
	Book cppDummy("C++ for Dummies", peter, 19.99);
	cppDummy.setQtyInStock(88);
	cppDummy.getAuthor().setEmail("peter@abc.com");
	cppDummy.print();

	cout << "------------------------------------\n\n";
	cout << cppDummy.getQtyInStock() << endl;  // 88
	cout << cppDummy.getPrice() << endl;       // 19.99
	cout << cppDummy.getAuthor().getName() << endl;  // "Peter Jones"
	cout << cppDummy.getAuthor().getEmail() << endl; // "peter@somewhere.com"
	cout << cppDummy.getAuthorName() << endl;        // "Peter Jones"

	cout << "------------------------------------\n\n";

	Book moreCpp("More C++ for Dummies", peter, -19.99);
	// price should be positive! Set to 0
	cout << moreCpp.getPrice() << endl;   // 0
}