#ifndef TASKS_H
#define TASKS_H
#include<iostream>
#include<memory>
#include<vector>
#include<experimental/iterator>
#include<iterator>
#include<algorithm>
#include<cstdlib>
#include "game.h"
#include "player.h"
#include "gamekey.h"


using namespace std;


std::string get_longest_name(const std::vector<std::weak_ptr<Player>>& v) {
    std::string temp{ "" }; std::vector<std::weak_ptr<Player>>::size_type count{ 0 };
    if (v.empty())	throw std::runtime_error("get_longest_name Error");

    for (auto it = v.begin(); it != v.end(); it++)
        if (it->expired()) count++;
        else
            if (it->lock()->get_name().size() > temp.size()) temp = it->lock()->get_name();

    if (count == v.size()) throw std::runtime_error("get_longest_name Error");

    return temp;
}







#endif
