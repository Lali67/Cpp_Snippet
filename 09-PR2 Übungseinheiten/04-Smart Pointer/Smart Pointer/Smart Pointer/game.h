#ifndef GAME_H
#define GAME_H
#include<iostream>
#include<memory>
#include<vector>
#include<map>
#include<exception>
#include <experimental/generator>

class Game : std::enable_shared_from_this<Player>
{
private:
    std::string name; 											//Name des Spiels.
    std::shared_ptr<Player> host;		 						//Leiter des Spiels.
    std::map<std::string, std::shared_ptr<Player>> players;	    //Map von teilnehmenden Player-Objekten
public:
    Game(std::string name, std::shared_ptr<Player> host);
    std::string get_name() const;
    bool is_allowed(int n) const;
    bool remove_player(const GameKey& gk, std::shared_ptr<Player> p);
    bool add_player(const GameKey& gk, std::shared_ptr<Player> p);
    std::shared_ptr<Player> best_player();
    std::size_t number_of_players() const;
    std::shared_ptr<Player> play(std::size_t i);
    virtual int change(bool) const = 0;
    virtual ~Game() = default;

    virtual std::ostream& print(std::ostream& o) const;
    friend std::ostream& operator<< (std::ostream& out, const Game& g);
};

#endif