#include <iostream>
#include <algorithm>
#include "Warehouse.h"

using namespace std;

// fill stock
void Warehouse::FillStock(vector<Board> boards) {
	for (const Board& aBoard : boards) addToStock(aBoard);
}

// add Board to right stock
void Warehouse::addToStock(Board piece) {
	switch (piece.getMaterial()) {
		case woodTypes::Buche:	
			stock_Buche.push_back(piece);
			break;
		case woodTypes::Eiche:
			stock_Eiche.push_back(piece);
			break;
		case woodTypes::Mahagoni:
			stock_Mahagoni.push_back(piece);
			break;
	}
}

// remove a Board from right stock. If Board is not found returning false, otherwise true
bool Warehouse::removeFromStock(Board piece, int number) {
	std::vector<Board>::iterator it;
	bool ret{ false };
	
	//sort will use operators from Board
	switch (piece.getMaterial()) {
	
	case woodTypes::Buche:
		sort(stock_Buche.begin(), stock_Buche.end());
		for (int i = 0; i < number; i++) {
			it = std::find(stock_Buche.begin(), stock_Buche.end(), piece);
			if (it != stock_Buche.end()) {
				stock_Buche.erase(it);
				ret = true;
			}	
		}
		break;

	case woodTypes::Eiche:
		sort(stock_Eiche.begin(), stock_Eiche.end());
		for (int i = 0; i < number; i++) {
			it = std::find(stock_Eiche.begin(), stock_Eiche.end(), piece);
			if (it != stock_Eiche.end()) {
				stock_Eiche.erase(it);
				ret = true;
			}
		}
		break;

	case woodTypes::Mahagoni:
		sort(stock_Mahagoni.begin(), stock_Mahagoni.end());
		for (int i = 0; i < number; i++) {
			it = std::find(stock_Mahagoni.begin(), stock_Mahagoni.end(), piece);
			if (it != stock_Mahagoni.end()) {
				stock_Mahagoni.erase(it);
				ret = true;
			}
		}
		break;
	}
	
	return ret;
}

// remove Board from stock below minimalLength
bool Warehouse::removeBoardsBelowMinimalLength(woodTypes woodT){
	std::vector<Board>::iterator it;
	bool ret{ false };

	switch (woodT)
	{
		case woodTypes::Buche:
			sort(stock_Buche.begin(), stock_Buche.end());
			it = stock_Buche.begin();
			while ((*it).getLength() < minimalLength) it++; 
			if (it > stock_Buche.begin()) { stock_Buche.erase(stock_Buche.begin(), it); ret = true; }
			break;

		case woodTypes::Eiche:
			sort(stock_Eiche.begin(), stock_Eiche.end());
			it = stock_Eiche.begin();
			while ((*it).getLength() < minimalLength) it++;
			if (it > stock_Eiche.begin()) {stock_Eiche.erase(stock_Eiche.begin(), it); ret = true; }
			break;

		case woodTypes::Mahagoni:
			sort(stock_Mahagoni.begin(), stock_Mahagoni.end());
			it = stock_Mahagoni.begin();
			while ((*it).getLength() < minimalLength) it++;
			if (it > stock_Mahagoni.begin()) {stock_Mahagoni.erase(stock_Mahagoni.begin(), it); ret = true;	}
			break;

		default:
			break;
	}
	
	return ret;
}

// sell a piece (with or without cutting)
bool Warehouse::sellBoard(Board piece){
	bool ret{ false };

	switch (piece.getMaterial())
	{
		case woodTypes::Buche:
			sort(stock_Buche.begin(), stock_Buche.end());
			for (Board& aBoard: stock_Buche) {
				if (aBoard == piece || aBoard > piece) {
					aBoard.setLength(aBoard.getLength() - piece.getLength());
					ret = true;
					break;
				}
			}
			break;

		case woodTypes::Eiche:
			sort(stock_Eiche.begin(), stock_Eiche.end());
			for (Board& aBoard : stock_Eiche) {
				if (aBoard == piece || aBoard > piece) {
					aBoard.setLength(aBoard.getLength() - piece.getLength());
					ret = true;
					break;
				}
			}
			break;

		case woodTypes::Mahagoni:
			sort(stock_Mahagoni.begin(), stock_Mahagoni.end());
			for (Board& aBoard : stock_Mahagoni) {
				if (aBoard == piece || aBoard > piece) {
					aBoard.setLength(aBoard.getLength() - piece.getLength());
					ret = true;
					break;
				}
			}
			break;
	}

	return ret;
}

//print stock
void Warehouse::printStockByTypes(woodTypes woodT, ostream& output){
	switch (woodT){
	case woodTypes::Buche:
		output << "----- Buche -----\n";
		for (Board aBoard : stock_Buche) aBoard.printBoardData();
		output << endl;
		break;
	case woodTypes::Eiche:
		output << "----- Eiche -----\n";
		for (Board aBoard : stock_Eiche) aBoard.printBoardData();
		output << endl;
		break;
	case woodTypes::Mahagoni:
		output << "----- Mahagoni -----\n";
		for (Board aBoard : stock_Mahagoni) aBoard.printBoardData();
		output << endl;
		break;
	default:
		break;
	}
}

void Warehouse::printStockAll(ostream& output) {
	printStockByTypes(woodTypes::Buche);
	printStockByTypes(woodTypes::Eiche);
	printStockByTypes(woodTypes::Mahagoni);
}
;