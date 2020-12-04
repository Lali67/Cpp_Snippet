#ifndef GAME_H
#define GAME_H

#include<string>
#include<iostream>
#include<memory>
#include<vector>
#include<map>

class Game :public
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
    friend std::ostream& operator<< (std::ostream& o, const Game& g);
};

class RGame : public Game
{
public:
    RGame(std::string s, std::shared_ptr<Player> p) :Game(s, p) {};
    int change(bool x) const { if (x) return 5; else - 5; };
    std::ostream& print(std::ostream& o) { Game::print(o); return o; } const
};

class UGame : public Game
{
public:
    UGame(std::string s, std::shared_ptr<Player> p) :Game(s, p) {};
    int change(bool) const { return 0; };
    std::ostream& print(std::ostream& o) { Game::print(o); return o; } const
};
#endif
