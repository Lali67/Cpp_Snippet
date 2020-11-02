#include "miniatur.h"
#include <functional>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <stdexcept>
#include <iterator>

using namespace std;

int main(){
    try 

    {
        std::vector<Miniatur> v;
        {
            std::ifstream i{"objects.txt"};
            Miniatur m;
            string line;
            while (getline(i, line))
            {
                // note that the newline character is not included
                // in the getline() function
                cout << line << endl;
            }
            /*while (i >> m) {
                cout << m.get_name()<< endl;
                v.push_back(m);
            }*/
        }
        std::cout << "Size: " << v.size() << std::endl;
    }
    catch (std::runtime_error &e) 
    {
            std::cout << "Unerwartete Exception: " << e.what() << '\n';
    }

 return 0;
}
