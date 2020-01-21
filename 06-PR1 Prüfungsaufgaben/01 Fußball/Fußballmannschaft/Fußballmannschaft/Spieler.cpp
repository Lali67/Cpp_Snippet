#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include "Spieler.h"
using namespace std;

bool Spieler::operator==(const Spieler&) const {

	return true;
};

ostream& operator << (ostream& out, const Spieler& sp) {

	return out;
};