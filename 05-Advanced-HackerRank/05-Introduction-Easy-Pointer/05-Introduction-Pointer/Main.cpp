/*
	Description: c-tutorial-pointer-English.pdf
	Link: https://www.hackerrank.com/challenges/c-tutorial-pointer/problem

	Sample Input
		4
		5

Sample Output
		9
		1
*/

#include <stdio.h>

void update(int* a, int* b) {
	// Complete this function 
	int sum = (*a) + (*b);
	int abs_diff = 0;

	if ((*a) > (*b))
	{
		abs_diff = (*a) - (*b);
	}
	else
	{
		abs_diff = (*b) - (*a);
	}

	(*a) = sum; (*b) = abs_diff;
}

int main() {
	int a, b;
	int* pa = &a, * pb = &b;

	scanf_s("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d", a, b);

	return 0;
}


