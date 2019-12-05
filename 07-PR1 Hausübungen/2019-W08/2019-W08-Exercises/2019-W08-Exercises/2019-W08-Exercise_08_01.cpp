/*2019 - W08 - Exercise_8_01.cpp :

Exercise 8.1
  (+) Ein Tischler hat ein Lager mit Brettern in drei Holzsorten (Buche, Eiche u. Mahagoni). 
  Alle Bretter haben den selben Querschnitt, sind aber unterschiedlich lang. 
  Wird ein Brett einer bestimmten L�nge verkauft, so wird, falls die entsprechende L�nge nicht 
  vorr�tig ist, einfach das passende St�ck von einem der vorhandenen Bretter abgeschnitten. 
  Um den Verschnitt nicht allzu gro� werden zu lassen, soll dabei immer das k�rzest m�gliche Brett 
  zers�gt werden. Schreiben Sie ein Programm, das dem Tischler hilft, sein Lager zu verwalten. 
  Folgende Funktionen sind unabdingbar: Erfassung des aktuellen Bestandes, 
  Einkauf von Brettern beliebiger L�nge, Verkauf von Brettern beliebiger L�nge 
  (das Programm soll das k�rzest m�gliche Brett automatisch vorschlagen), 
  Aufr�umen des Lagers (dabei werden alle Bretter, die eine vom Benutzer festzulegende L�nge 
  unterschreiten, aus dem Lager entfernt).

  M�gliche Klassenkandidaten: Brett, Lager

*/

#include <iostream>
#include "Warehouse.h"

using namespace std;

int main() {

    vector<Board> list{
        {1200}, {1500}, {1800},
        {1200, woodTypes::Eiche}, {1800, woodTypes::Eiche}, {2200, woodTypes::Eiche},
        {1200, woodTypes::Mahagoni}, {1600, woodTypes::Mahagoni}
    };
    Warehouse warehouse;

    // Fill Stock
    std::cout << "\n-------- Actual level of Stocks ---------\n";
    warehouse.FillStock(list);
    warehouse.printStockAll();

    cout << "Remove a Board :\n ";
    int tSize{ 0 }, tType{ 0 };
    cout << "  Give the size of board in mm (>0)                     : "; cin >> tSize;
    cout << "  Give the type of Board (0-Buche, 1-Eiche, 2-Mahagoni) :"; cin >> tType;
    Board tBoard{ tSize, (woodTypes)(tType) };
    warehouse.removeFromStock(tBoard);
    warehouse.printStockByTypes((woodTypes)(tType));

    cout << "Add a Board :\n ";
    cout << "  Give the size of board in mm (>0)                     : "; cin >> tSize;
    cout << "  Give the type of Board (0-Buche, 1-Eiche, 2-Mahagoni) :"; cin >> tType;
    Board tBoard1{ tSize, (woodTypes)(tType) };
    warehouse.addToStock(tBoard1);
    warehouse.printStockByTypes((woodTypes)(tType));

    cout << "Sell a Board :\n ";
    cout << "  Give the size of board in mm (>0)                     : "; cin >> tSize;
    cout << "  Give the type of Board (0-Buche, 1-Eiche, 2-Mahagoni) :"; cin >> tType;
    Board tBoard2{ tSize, (woodTypes)(tType) };
    warehouse.sellBoard(tBoard2);
    warehouse.printStockByTypes((woodTypes)(tType));

    cout << "Remove Boards Below MinimalLength :\n ";
    cout << "  Give the MinimalLength in mm (>0)                     : "; cin >> tSize;
    cout << "  Give the type of Board (0-Buche, 1-Eiche, 2-Mahagoni) :"; cin >> tType;
    warehouse.setMinimalLength(tSize);
    warehouse.removeBoardsBelowMinimalLength((woodTypes)(tType));
    warehouse.printStockByTypes(woodTypes::Buche);

    

	return 0;
}