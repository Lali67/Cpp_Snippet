/*
	Description: c-tutorial-stringstream-English.pdf
	Link: https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem

	Sample Input
		23,4,56

	Sample Output
		23
		4
		56

*/

#include <sstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<int> parseInts(string str) {
	vector<int> arr_int;
	stringstream ss(str);
	int n;
	char sign;

	while (ss >> n) {
		arr_int.push_back(n);
		ss >> sign;
	}

	return arr_int;
}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}

	return 0;
}