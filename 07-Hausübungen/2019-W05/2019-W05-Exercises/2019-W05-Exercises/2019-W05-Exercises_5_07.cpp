/* 2019-W02-Exercise_5_07.cpp :


Exercise 5.7
 Schreiben Sie eine Funktion int binomial(int n, int k), die den Binomialkoeffizienten n über k nach der Formel (...) berechnet.
 Verwenden Sie zur Berechnung der Fakultät, die aus der Vorlesung bekannte rekursive Funktion.
 Schreiben Sie eine Variante der Funktion binomial, die eine Rekursion für die Binomialkoeffizienten verwendet, 
 die sich aus dem Pascalschen Dreieck und dem binomischen Lehrsatz leicht herleiten lässt. 
 Welchen Vorteil hat diese rekursive Variante gegenüber der Berechnung nach obiger Formel?
			   1
			1     1
		1      2     1
   1        3     3     1
1      4       6     4     1

Dániel Szöke (11913915)
08.11.2019

*/

#include <iostream>
#include <vector>
//#include <cmath>
//#include <exception>

using namespace std;

int pascalTriangle(int row, int column)
{
    if (column == 0) // The 0th column element is assumed to 0
        return 0;
    else if (row == 1 && column == 1)
        return 1;
    else if (column > row) // assuming the element is zero (no of columns> no of rows)
        return 0;
    else
        return (pascalTriangle(row - 1, column - 1) + pascalTriangle(row - 1, column));
}

void spaceBetweenElements(int num, int mul)
{
    num *= mul;
    for (int i{ 0 }; i < num; i++) printf(" ");
}
// main function
int main(void)
{
    int number, i, j;
    cout << ("\nGeben Sie hier die Nummer der Reihen ein: "); cin >> number;
    for (i = 1; i <= number; i++)
    {
        spaceBetweenElements(number - i, 3);
        for (j = 1; j <= i; j++)
        {
            printf("%4d", pascalTriangle(i, j));
            spaceBetweenElements(1, 4);
        }
        cout << endl;
    }

	return 0;
}


