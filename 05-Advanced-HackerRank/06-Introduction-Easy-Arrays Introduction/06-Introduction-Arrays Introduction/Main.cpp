/*
	Description: arrays-introduction-English.pdf
	Link: https://www.hackerrank.com/challenges/arrays-introduction/problem

	Sample Input
		4
		1 4 3 2

	Sample Output
		2 3 4 1

*/


#include <iostream>
using namespace std;

int main() {
	int N = 1;
	cin >> N;
	// 1<=N<=1000 -> Max array size
	int arr[1000];
	for (int i = 0; i < N; i++) { cin >> arr[i]; }
	for (int i = N - 1; i >= 0; i--) { cout << arr[i] << ' '; }

	return 0;
}
