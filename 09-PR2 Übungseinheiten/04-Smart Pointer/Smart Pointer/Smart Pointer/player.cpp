#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<iostream>
#include<memory>
#include<vector>
#include<map>
#include<exception>
#include <experimental/generator>

class Game;

enum class Mode { Ranked, Unranked };

std::string Player::get_name() const {}

int Player::get_mmr() const {}

std::shared_ptr<Game> Player::get_hosted_game() const 
{
}

void Player::change_mmr(int n)
{
}

bool Player::host_game(std::string s, Mode m)
{
}

bool Player::join_game(std::shared_ptr<Game> g)
{
}

bool Player::leave_game(std::shared_ptr<Game> g)
{
}

std::vector<std::weak_ptr<Player>> Player::invite_players(const std::vector<std::weak_ptr<Player>>& v)
{
}

bool Player::close_game()
{
}

std::ostream& Player::print(std::ostream& o) const
{
	o << "[" << this->name << ", " << this->mmr << "hosts: ";

	if (!this->get_hosted_name()) o << "nothing, games: {";
	else o << this->get_hosted_name()->get_name() << ", games: {";

	std::transform(games.begin(), games.end(), std::experimental::make_ostream_joiner(o, ", "),
		[](const auto x) {return x.first; });
 
	o << "}]";

	return o;
}

std::ostream& operator <<(std::ostream& out, const Player& p) 
{
	p.print(out);

	return out;
}
#endif

