#include "game.h"
#include "player.h"
#include "gamekey.h"
#include<string>
#include<iostream>
#include<algorithm>
#include<memory>
#include<numeric>
#include<vector>
#include<map>
#include<exception>
#include <experimental/generator>

std::ostream& print(std::ostream& o) const 
{
	o << "[" << this->name << ", " << host->get_name() << ", " << host->get_mmr() << ", player: {";

	for (auto it = players.begin(); it != players.end();)
	{
		o << "[" << it->first << ", " << it->second->get_mmr();
		if (++it == players.end()) o << "]";
		else o << "], ";
	}

	return o;
}

std::ostream& operator<< (std::ostream& out, const Game& g) 
{
	g.print(out);

	return out;
}