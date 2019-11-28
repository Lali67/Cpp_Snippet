#ifndef BOARD_H
#define BOARD_H

#include<iostream>
#include<string>
#include<vector>

enum class woodTypes { Buche, Eiche, Mahagoni };
const vector<string> woodTypes_names{"Buche", "Eiche", "Mahagoni"};

class Board {
	int length;				// length in m
	int crossSection;		// crossSection in cm2
	woodTypes material;		// material of board
	double price;			// price (EUR) of meter

	public:
		Board(int aLength, woodTypes aMaterial = woodTypes::Buche, 
				int acrossSection = 0.25, double aPrice = 1.0)
			: length(aLength), crossSection(acrossSection), 
				material(aMaterial), price(aPrice) {};
		//Copy constructor 
		Board(const Board& aBoard) { 
			length = aBoard.length; 
			crossSection = aBoard.crossSection;
			material = aBoard.material;
			price = aBoard.price;
		}

		//getter function
		int getLength() { return length; };
		int getCrossSection() { return crossSection; };
		woodTypes getMaterial() { return material; };
		double getPrice() { return price; };

		//setter function
		void setLength(int aLength) { length = aLength; };
		void setCrossSection(int aCross) { crossSection = aCross; };
		void setMaterial(woodTypes aType) { material = aType; };
		void setPrice(double aPrice) { price = aPrice; };

		// operator overloading when adds two Board objects
		bool operator == (Board const& obj) {
			return	length == obj.length &&
					crossSection == obj.crossSection &&
					material == obj.material &&
					price == obj.price;
		}

		// print data
		void printBoardData(ostream& output = std::cout) {
			cout << woodTypes_names.at(static_cast<size_t>(material)) << 
				"- Length: " << length << "\n";
		};
};
#endif
