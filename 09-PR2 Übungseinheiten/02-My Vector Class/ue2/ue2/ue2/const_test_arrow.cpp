#include<iostream>
#include"vector.h"
using namespace std;

int main() {
  //Vector v{1,2,2.5,3,5};
  const Vector v{ 1,2,2.5,3,5 };
  for (auto it = v.begin(); it != v.end(); ++it) {
      cout << *(it.operator->()) <<' ';
      *(it.operator->()) = 7;
  }
  cout << "\n";
  //for (auto& elem : v)
  //  elem=7;
  for (auto& elem: v) cout << elem <<' ';
  cout << '\n';

  return 0;
}
