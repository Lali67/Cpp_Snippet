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

Game::Game(std::string name, std::shared_ptr<Player> host) :name(name), host(host)
{
    if (name == "" || !host)
        throw std::runtime_error("Game Konstruktor");
}

std::string Game::get_name() const { return name; }

bool Game::is_allowed(int n) const
{
    if (n / double(host->get_mmr()) > 0.9 && n / double(host->get_mmr()) < 1.1)
        return true;
    else
        return false;
}

bool Game::remove_player(const GameKey&, std::shared_ptr<Player> p)
{
    for (auto it = players.begin(); it != players.end(); it++)
        if (it->first == p->get_name())
        {
            players.erase(it);
            return true;
        }

    return false;
}

bool Game::add_player(const GameKey&, std::shared_ptr<Player> p)
{
    bool ret{ true };
    for (auto it = players.begin(); it != players.end(); it++)
        if (it->first == p->get_name()) ret = false;

    if (ret && this->is_allowed(p->get_mmr()))
        players.insert({ p->get_name(), p });
    else
        ret = false;

    return ret;
}

std::shared_ptr<Player> Game::best_player()
{
    if (!this->players.size())
        throw std::runtime_error("Game::best_player() error");

    auto best = players.begin();
    for (auto it = players.begin(); it != players.end(); it++)
        if (it->second->get_mmr() > best->second->get_mmr()) best = it;

    return best->second;
}

std::size_t Game::number_of_players() const
{
    return this->players.size();
}

MGame::MGame(std::string s, std::shared_ptr<Player> p) :Game(s, p) { i = 0; }

std::shared_ptr<Player> Game::play(std::size_t i)
{
    auto winner = players.begin();
    //find Winner
    for (auto it = players.begin(); it != players.end(); it++) {
        if (i == 0) winner = it;
        i--;
    }

    //change mmr of Losers from players list
    for (auto it = players.begin(); it != players.end(); it++)
        if (it != winner) {
            if (it->second->get_mmr() > winner->second->get_mmr())
                it->second->change_mmr(2 * change(false));
            else
                it->second->change_mmr(1 * change(false));
        }

    winner->second->change_mmr(change(true));

    return winner->second;
}

std::ostream& Game::print(std::ostream& o) const
{
    o << "[" << this->name << ", " << host->get_name() << ", " << host->get_mmr() << ", player: {";

    if (players.begin() != players.end()) // players not empty
        for (auto it = players.begin(); it != players.end();)
        {
            o << "[" << it->first << ", " << it->second->get_mmr();
            if (++it == players.end()) o << "]}]";
            else o << "], ";
        }
    else
        o << "}]";

    return o;
}

std::ostream& operator<< (std::ostream& out, const Game& g)
{
    g.print(out);

    return out;
}

bool RGame::testi_test() const
{
    if (get_host()->get_mmr() % 2 == 0)  return true;
    else
        return false;
};

bool UGame::testi_test() const
{
    if (get_host()->get_mmr() % 2 == 0)  return true;
    else
        return false;
};

int MGame::i = 0;