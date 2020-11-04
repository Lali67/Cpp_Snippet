#ifndef TASK_H
#define TASK_H

#include "vector.h"
#include "gossip_girl.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;



Vector<string> get_names(const Vector<Gossip_Girl>& v) {
    Vector<string> temp;

    for (auto it = v.begin(); it != v.end(); it++)
    {
        temp.push_back(it->get_name());
    }
    return temp;
}


/*
Gossip_Girl longest_name(const Vector<Gossip_Girl>& v){
}

*/

/*
std::string max_str(const Vector<Gossip_Girl> v){

}
*/
#endif

