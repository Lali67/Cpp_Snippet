/* Implementation for the class Book (Book.cpp) */

#include "Book.h"
#include <iostream>

using namespace std;

// Constructor, with member initializer list to initialize the
//  component Author instance

Book::Book(const string& name, const Author& author, double price, int qtyInStock)
	: name(name), author(author) { // Init object reference in member initializer list
 // Call setters to validate price and qtyInStock
	setPrice(price);
	setQtyInStock(qtyInStock);
}

string Book::getName() const {
	return name;
}

Author Book::getAuthor() const {
	return author;
}

double Book::getPrice() const {
	return price;
}

// Validate price, which shall be positive
void Book::setPrice(double price) {
	if (price > 0) {
		this->price = price;
	}
	else {
		cout << "price should be positive! Set to 0" << endl;
		this->price = 0;
	}
}

int Book::getQtyInStock() const {
	return qtyInStock;
}

// Validate qtyInStock, which cannot be negative
void Book::setQtyInStock(int qtyInStock) {
	if (qtyInStock >= 0) {
		this->qtyInStock = qtyInStock;
	}
	else {
		cout << "qtyInStock cannnot be negative! Set to 0" << endl;
		this->qtyInStock = 0;
	}
}

// print in the format ""Book-name" by author-name (gender) at email"
void Book::print() const {
	cout << "'" << name << "' by ";
	author.print();
}

// Return the author' name for this Book
string Book::getAuthorName() const {
	return author.getName();   // invoke the getName() on instance author
}
