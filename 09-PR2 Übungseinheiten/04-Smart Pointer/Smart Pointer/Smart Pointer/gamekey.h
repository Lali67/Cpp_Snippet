#ifndef GAMEKEY_H
#define GAMEKEY_H
#include "player.h"
#include "game.h"
#include "gamekey.h"
#include<string>
#include<iostream>
#include<memory>
#include<algorithm>
#include<vector>
#include<map>

class Game;

class GameKey {

	GameKey() {} // Private. Implementierung kann auch in gamekey.cpp erfolgen.

	friend bool Player::join_game(std::shared_ptr<Game> g);
	friend bool Player::leave_game(std::shared_ptr<Game> g);
};

#endif