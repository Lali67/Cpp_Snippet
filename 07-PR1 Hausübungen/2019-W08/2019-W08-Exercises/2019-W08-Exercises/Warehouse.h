#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include<iostream>
#include<string>
#include<vector>
#include"Board.h"


class Warehouse {
	vector<Board> Stock_Buche;
	vector<Board> Stock_Eiche;
	vector<Board> Stock_Mahagoni;

	public:
		Warehouse();
		//add Board to right stock
		void addToStock(const Board& piece);
		//remove Board from right stock. If Board is not found returning false, otherwise true
		bool removeFromStock(const Board& piece, int number = 1);
		// empty stock under defined Board length
		// sell a piece (with or without cutting)

};
#endif
