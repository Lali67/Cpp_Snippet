/*
	Description: c-tutorial-for-loop-English.pdf
	Link: https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem

	Sample Input
		3
		4
		6
		5

	Sample Output

		6


*/
#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d)
{
	int arr[4];
	int max = a;
	arr[0] = a; arr[1] = b; arr[2] = c; arr[3] = d;
	for (int i = 0; i < 4; i++)
	{
		if (max < arr[i]) { max = arr[i]; }
	}
	return max;
};

int main() {
	int a, b, c, d;
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	int ans = max_of_four(a, b, c, d);
	printf("%d", ans);

	return 0;
}

