#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<iostream>
#include<memory>
#include<vector>
#include<map>


class Game;
enum class Mode { Ranked, Unranked };

class Player : public std::enable_shared_from_this<Player>
{
private:
    std::string name;
    int mmr;
    std::shared_ptr<Game> hosted_game;
    std::map<std::string, std::weak_ptr<Game>> games;

public:
    Player(std::string name, int mmr) : name(name), mmr(mmr)
    {
        if (name == "" || mmr < 0 || mmr > 9999)
            throw std::runtime_error("Player Konstruktor");
    }

    std::string get_name() const;
    int get_mmr() const;
    std::shared_ptr<Game> get_hosted_game() const;

    void change_mmr(int n);
    bool host_game(std::string s, Mode m);
    bool join_game(std::shared_ptr<Game> g);
    bool leave_game(std::shared_ptr<Game> g);
    std::vector<std::weak_ptr<Player>> invite_players(const std::vector<std::weak_ptr<Player>>& v);
    //bool close_game();

    std::ostream& print(std::ostream& o) const;
    friend std::ostream& operator << (std::ostream& out, const Player& p);
};

#endif