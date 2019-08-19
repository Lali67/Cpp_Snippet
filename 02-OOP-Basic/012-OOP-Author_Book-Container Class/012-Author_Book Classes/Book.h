#pragma once
#include <string>
#include "Author.h"   // Use the Author class
using namespace std;

class Book {
	private:
		string	name;
		Author	author;
		double	price;
		int		qtyInStock;

	public:
		Book(const string& name, const Author& author, double price, int qtyInStock = 0);

		string	getName() const;
		Author	getAuthor() const;
		double	getPrice() const;
		void	setPrice(double price);
		int		getQtyInStock() const;
		void	setQtyInStock(int qtyInStock);
		void	print() const;
		string	getAuthorName() const;
};



