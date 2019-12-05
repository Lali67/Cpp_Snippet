#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include<iostream>
//#include<string>
#include<vector>
#include"Board.h"


class Warehouse {
	vector<Board> stock_Buche;
	vector<Board> stock_Eiche;
	vector<Board> stock_Mahagoni;
	int minimalLength;				// minimal length (mm) of board to remove from stock

	public:
		Warehouse(int minL = 500) : minimalLength(minL) {};
		~Warehouse() { stock_Buche.clear(); stock_Eiche.clear(); stock_Mahagoni.clear(); };

		void setMinimalLength(int minL) { minimalLength = minL; };
		int getMinimalLength() { return minimalLength; };

		// fill stock
		void FillStock(vector<Board> boards);
		// add Board to right stock
		void addToStock(const Board piece);
		// remove a Board from right stock. If Board is not found returning false, otherwise true
		bool removeFromStock(const Board piece, int number = 1);
		// remove Board from stock below minimalLength
		bool removeBoardsBelowMinimalLength(woodTypes woodT);
		// sell a piece (with or without cutting)
		bool sellBoard(const Board piece);
		
		//print stock
		void printStockByTypes(woodTypes woodT, ostream& output = std::cout);
		void printStockAll(ostream& output = std::cout);

};
#endif
