#include <iostream>
#include <memory>
#include <vector>
#include <experimental/generator>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include "game.h"
#include "player.h"
#include "gamekey.h"
#include<exception>


constexpr int RANDO_SEED{ 78 };

int main() {
    std::srand(RANDO_SEED);
    std::cout << std::boolalpha;
    std::vector<std::shared_ptr<Player>> v{ std::make_shared<Player>("Florian",1000),std::make_shared<Player>("Lisa",500),std::make_shared<Player>("Leia",110),
    std::make_shared<Player>("Lara",100), std::make_shared<Player>("Finn",10),std::make_shared<Player>("Karo",550),std::make_shared<Player>("Christoph",1500),
    std::make_shared<Player>("Heinrich",500), std::make_shared<Player>("Helmut",600),std::make_shared<Player>("Martin",650),std::make_shared<Player>("Konstantin",450),
    std::make_shared<Player>("Juergen",901), std::make_shared<Player>("Georg",520) };
    std::vector<std::weak_ptr<Player>> vw{ v.begin(),v.end() };
    const std::vector<std::string> game_names{ "DotA 2","Rimworld","Pokemon","Civilization VI","X-COM","Zelda","NBA 2k21","FTL","Cities Skylines" };

    std::cout << "{";
    std::transform(v.begin(), v.end(), std::experimental::make_ostream_joiner(std::cout, ", "), [](const auto& x) {return *x; });
    std::cout << "}\n";
    /*
    // Host games

    std::cout << "Host: " << (v.at(5)->host_game("DotA 2", Mode::Ranked)) << "\n";
    std::cout << "Host: " << (v.at(5)->host_game("LoL", Mode::Ranked)) << "\n";

    try {
        std::cout << "Host: " << (v.at(0)->host_game("", Mode::Ranked)) << "\n";
        std::cout << "Should not be here\n";
    }
    catch (std::runtime_error& e) {
        std::cout << "Error 1\n";
    }

    std::cout << "Host: " << (v.at(1)->host_game("Rimworld", Mode::Unranked)) << "\n";
    std::cout << "Host: " << (v.at(1)->host_game("LoL", Mode::Unranked)) << "\n";


    std::cout << "{";
    std::transform(v.begin(), v.end(), std::experimental::make_ostream_joiner(std::cout, ", "), [](const auto& x) {return *x; });
    std::cout << "}\n";

    // Best Player

    try {
        std::cout << "Best: " << *(v.at(1)->get_hosted_game()->best_player()) << "\n";
        std::cout << "Should not be here\n";
    }
    catch (std::runtime_error& e) {
        std::cout << "Error Best\n";
    }

    // Join games

    {
        auto g{ v.at(5)->get_hosted_game() };
        if (g) {
            std::cout << "Game: " << *g << "\n";
            std::cout << "Join: " << (v.at(5)->join_game(g)) << "\n";
            std::cout << "Join: " << (v.at(5)->join_game(g)) << "\n";
            std::cout << "Join: " << (v.at(0)->join_game(g)) << "\n";
            std::cout << "Join: " << (v.at(1)->join_game(g)) << "\n";
            std::cout << "Join: " << (v.at(8)->join_game(g)) << "\n";
            std::cout << "Game: " << *g << "\n";
        }
        g = v.at(0)->get_hosted_game();
        if (g) {
            std::cout << "Game: " << *g << "\n";
            std::cout << "Join: " << (v.at(5)->join_game(g)) << "\n";
            std::cout << "Join: " << (v.at(5)->join_game(g)) << "\n";
            std::cout << "Join: " << (v.at(0)->join_game(g)) << "\n";
            std::cout << "Join: " << (v.at(1)->join_game(g)) << "\n";
            std::cout << "Join: " << (v.at(8)->join_game(g)) << "\n";
            std::cout << "Game: " << *g << "\n";
        }
        g = v.at(1)->get_hosted_game();
        if (g) {
            std::cout << "Game: " << *g << "\n";
            for (auto x : v)
                std::cout << "Join: " << (x->join_game(g)) << "\n";
            std::cout << "Game: " << *g << "\n";
        }
    }

    std::cout << "{";
    std::transform(v.begin(), v.end(), std::experimental::make_ostream_joiner(std::cout, ", "), [](const auto& x) {return *x; });
    std::cout << "}\n";


    // Invite Players

    auto invite_test{ v[5]->invite_players(vw) };

    std::cout << "Rejected Players: {";
    std::transform(invite_test.begin(), invite_test.end(), std::experimental::make_ostream_joiner(std::cout, ", "), [](const auto& x) {return *x.lock(); });
    std::cout << "}\n";

    invite_test = v[5]->invite_players(vw);
    std::cout << "Rejected Players: {";
    std::transform(invite_test.begin(), invite_test.end(), std::experimental::make_ostream_joiner(std::cout, ", "), [](const auto& x) {return *x.lock(); });
    std::cout << "}\n";

    std::cout << "{";
    std::transform(v.begin(), v.end(), std::experimental::make_ostream_joiner(std::cout, ", "), [](const auto& x) {return *x; });
    std::cout << "}\n";

    // Play the Game
    std::cout << "-------------------------------------------------------------\n";
    std::cout << "Play the Game\n";
    {
        auto g{ v.at(5)->get_hosted_game() };
        if (g) {
            std::cout << "Game: " << *g << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Game: " << *g << "\n";
        }
        g = v.at(0)->get_hosted_game();
        if (g) {
            std::cout << "Game: " << *g << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Game: " << *g << "\n";
        }
        g = v.at(1)->get_hosted_game();
        if (g) {
            std::cout << "Game: " << *g << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Winner: " << *g->play(std::rand() % g->number_of_players()) << "\n";
            std::cout << "Game: " << *g << "\n";
        }
    }
    std::cout << "-------------------------------------------------------------\n";

    // Leave Game
    std::cout << "-------------------------------------------------------------\n";
    std::cout << "Leave Game\n";
    {
        auto g{ v.at(5)->get_hosted_game() };
        if (g) {
            std::cout << "Game: " << *g << "\n";
            std::cout << "Leave: " << (v.at(5)->leave_game(g)) << "\n";
            std::cout << "Leave: " << (v.at(5)->leave_game(g)) << "\n";
            std::cout << "Leave: " << (v.at(0)->leave_game(g)) << "\n";
            std::cout << "Leave: " << (v.at(1)->leave_game(g)) << "\n";
            std::cout << "Leave: " << (v.at(8)->leave_game(g)) << "\n";
            std::cout << "Game: " << *g << "\n";
        }
        g = v.at(0)->get_hosted_game();
        if (g) {
            std::cout << "Game: " << *g << "\n";
            std::cout << "Leave: " << (v.at(5)->leave_game(g)) << "\n";
            std::cout << "Leave: " << (v.at(5)->leave_game(g)) << "\n";
            std::cout << "Leave: " << (v.at(0)->leave_game(g)) << "\n";
            std::cout << "Leave: " << (v.at(1)->leave_game(g)) << "\n";
            std::cout << "Leave: " << (v.at(8)->leave_game(g)) << "\n";
            std::cout << "Game: " << *g << "\n";
        }
    }

    std::cout << "{";
    std::transform(v.begin(), v.end(), std::experimental::make_ostream_joiner(std::cout, ", "), [](const auto& x) {return *x; });
    std::cout << "}\n";


    // Close all Games

    std::cout << "-------------------------------------------------------------\n";
    std::cout << "Close Game\n";
    for (auto x : v)
        std::cout << "Close: " << (x->close_game()) << "\n";
    std::cout << "{";
    std::transform(v.begin(), v.end(), std::experimental::make_ostream_joiner(std::cout, ", "), [](const auto& x) {return *x; });
    std::cout << "}\n";

    // Host games again

    std::cout << "-------------------------------------------------------------\n";
    std::cout << "Host Game Part II\n";

    for (size_t i{ 0 }; i < game_names.size() && i < v.size(); ++i)
        std::cout << "Host: " << (v.at(i)->host_game(game_names.at(i), Mode::Ranked)) << "\n";

    std::cout << "-------------------------------------------------------------\n";
    std::cout << "Invite all to everyhing \n";
    for (auto x : v)
        if (x->get_hosted_game())
            x->invite_players(vw);

    // Best Player II

    for (auto x : v)
        if (x->get_hosted_game())
            try {
            std::cout << "Best: " << *(x->get_hosted_game()->best_player()) << "\n";
        }
    catch (std::runtime_error& e) {
        std::cout << "Error BestX\n";
    }
    std::cout << "{";
    std::transform(v.begin(), v.end(), std::experimental::make_ostream_joiner(std::cout, ", "), [](const auto& x) {return *x; });
    std::cout << "}\n";

    std::cout << "-------------------------------------------------------------\n";
    std::cout << "Play 100 games and close again\n";

    for (size_t i{ 0 }; i < 100; ++i) {
        auto g{ v.at(std::rand() % v.size())->get_hosted_game() };
        if (g)
            g->play(std::rand() % g->number_of_players());
    }
    for (auto x : v)
        x->close_game();

    std::cout << "{";
    std::transform(v.begin(), v.end(), std::experimental::make_ostream_joiner(std::cout, ", "), [](const auto& x) {return *x; });
    std::cout << "}\n";
    */
    return 0;
}