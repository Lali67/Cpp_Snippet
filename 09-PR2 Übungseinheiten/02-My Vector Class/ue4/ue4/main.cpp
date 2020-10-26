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


int main(){
  try {
    std::vector<Miniatur> v;
    {
      std::ifstream i{"objects.txt"};
      Miniatur m;
      while(i >> m)
        v.push_back(m);
    }
    std::cout << "Size: " << v.size() << std::endl;
 }
 catch (std::runtime_error &e) {
   std::cout << "Unerwartete Exception: " << e.what() << '\n';
 }

 return 0;
}
