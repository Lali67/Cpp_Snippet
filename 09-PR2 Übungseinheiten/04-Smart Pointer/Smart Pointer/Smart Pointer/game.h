#ifndef GAME_H
#define GAME_H

#include<string>
#include<iostream>
#include<memory>
#include<vector>
#include<map>

class Player;
class GameKey;

class Game :public std::enable_shared_from_this<Game>
{
private:
    std::string name; 												//Name des Spiels.
    std::shared_ptr<Player> host;		 						//Leiter des Spiels.
    std::map<std::string, std::shared_ptr<Player>> players;	  //Map von teilnehmenden Player-Objekten

public:
    Game(std::string name, std::shared_ptr<Player> host);
    std::string get_name() const;
    std::shared_ptr<Player> get_host() const { return this->host; };
    bool is_allowed(int n) const;
    bool remove_player(const GameKey& gk, std::shared_ptr<Player> p);
    bool add_player(const GameKey& gk, std::shared_ptr<Player> p);
    std::shared_ptr<Player> best_player();
    std::size_t number_of_players() const;
    std::shared_ptr<Player> play(std::size_t i);
    virtual int change(bool) const = 0;
    virtual bool testi_test() const { return false; };
    virtual ~Game() = default;

    virtual std::ostream& print(std::ostream& o) const;
    friend std::ostream& operator<< (std::ostream& o, const Game& g);
};

class RGame : public Game
{
public:
    RGame(std::string s, std::shared_ptr<Player> p) :Game(s, p) {};
    int change(bool x) const { if (x) return 5; else return -5; };
    bool testi_test() const;
    std::ostream& print(std::ostream& o) const { o << "Ranked Game: "; Game::print(o); return o; }
};

class UGame : public Game
{
public:
    UGame(std::string s, std::shared_ptr<Player> p) :Game(s, p) {};
    int change(bool) const { return 0; };
    bool testi_test() const;
    std::ostream& print(std::ostream& o) const { o << "Unranked Game: "; Game::print(o); return o; }
};

class MGame : public Game
{
private:
    static int i;

public:
    MGame(std::string s, std::shared_ptr<Player> p);
    static void increase_counter()
    {
        ++i;
        if (i > 10) i = 0;
    }

    int change(bool) const { return i; }

    std::ostream& print(std::ostream& o) const { o << "Mixed Game: "; Game::print(o); return o; }
};

#endif
