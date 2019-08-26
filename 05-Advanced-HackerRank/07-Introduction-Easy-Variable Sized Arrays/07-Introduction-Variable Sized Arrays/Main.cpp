/*
	Description: variable-sized-arrays-English.pdf
	Link: https://www.hackerrank.com/challenges/variable-sized-arrays/problem

	Sample Input
		2 2
		3 1 5 4
		5 1 2 8 9 3
		0 1
		1 3
	Sample Output
		5
		9
*/

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;


int main() {
	//--- 1. read  n(the number of variable-length arrays), q(the number of queries)
	int n, q;  std::cin >> n >> q;

	//--- 2. read n-element array of variable-sized array
	std::vector<int> arr[500];
	for (int i = 0; i < n; i++)
	{
		int n_k; std::cin >> n_k;
		for (int j = 0; j < n_k; j++)
		{
			int a_n_k; std::cin >> a_n_k;
			arr[i].push_back(a_n_k);
		}
	}
	//--- 3. read queries
	for (int i = 0; i < q; i++)
	{
		int arr_num, index_in_arr;
		std::cin >> arr_num >> index_in_arr;
		std::cout << arr[arr_num][index_in_arr] << endl;
	}
	return 0;
}