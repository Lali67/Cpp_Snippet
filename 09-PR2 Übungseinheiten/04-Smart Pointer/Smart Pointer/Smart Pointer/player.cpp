#include "player.h"
#include "game.h"
#include "gamekey.h"
#include<string>
#include<iostream>
#include<memory>
#include<algorithm>
#include<vector>
#include<map>
#include<experimental/iterator>

std::string Player::get_name() const
{
    return name;
}

int Player::get_mmr() const
{
    return mmr;
}

std::shared_ptr<Game> Player::get_hosted_game() const
{
    return hosted_game;
}

void Player::change_mmr(int n)
{
    if (mmr >= 0 && mmr <= 9999) mmr += n;
}

bool Player::host_game(std::string s, Mode m)
{
    if (!this->hosted_game)
    {
        if (m == Mode::Ranked)
            this->hosted_game = std::make_shared<RGame>(s, shared_from_this());
        else
            this->hosted_game = std::make_shared<UGame>(s, shared_from_this());
        return true;
    }
    return false;
}

bool Player::join_game(std::shared_ptr<Game> g)
{
    bool ret(true);
    for (auto it = games.begin(); it != games.end(); it++)
        if (it->first == g->get_name()) ret = false;

    if (ret) {
        GameKey gk{};
        if (g->add_player(gk, shared_from_this()))
            games.insert({ g->get_name(), g });
        else
            ret = false;
    }

    return ret;
}

bool Player::leave_game(std::shared_ptr<Game> g)
{
    for (auto it = games.begin(); it != games.end(); it++)
        if (it->first == g->get_name())
        {
            GameKey gk{};
            if (g->remove_player(gk, shared_from_this())) {
                games.erase(it);
                return true;
            }
        }
    return false;
}

std::vector<std::weak_ptr<Player>> Player::invite_players(const std::vector<std::weak_ptr<Player>>& v)
{
    std::vector<std::weak_ptr<Player>> noJoined;

    for (auto it_p = v.begin(); it_p != v.end(); it_p++) {
        if (it_p->expired() || !it_p->lock()->join_game(get_hosted_game()))
            noJoined.push_back(*it_p);
    }

    return noJoined;
}

bool Player::close_game()
{
    games.clear();
    if (get_hosted_game())
    {
        hosted_game.reset();
        return true;
    }
    return false;
}

std::ostream& Player::print(std::ostream& o) const
{
    o << "[" << this->name << ", " << this->mmr << ", hosts: ";

    if (!this->get_hosted_game()) o << "nothing, games: {";
    else o << this->get_hosted_game()->get_name() << ", games: {";

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