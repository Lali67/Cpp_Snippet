/* 2019-W02-Exercise_5_10.cpp :

Exercise 5.10
  Schreiben Sie eine Funktion, die einen Vektor von double Werten als Parameter erhält und 
  den Mittelwert (arithmetisches Mittel) der Werte retourniert. Verwenden Sie keine Schleife in der Funktion.

Dániel Szöke (11913915)
29.10.2019

*/

#include <iostream>
#include <vector>
//#include <string>
//#include <cmath>
#include <cassert>
//#include <exception> 

using namespace std;


double vecSum(std::vector<double>::iterator begin, std::vector<double>::iterator end)
{
	if (begin != end)
		return *begin +vecSum(++begin, end );
	return 0;
}

double vecSum(std::vector<double> list)
{
	return vecSum(list.begin(), list.end());
}

double vecMean(vector<double> list)
{
	assert(list.size()>0);

	return vecSum(list) / list.size();
}


int main()
{
	string aString;

	cout << "This program...\n";
	cout << "-------- Test --------\n";
	vector<double> test1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << "{1,2,3,4,5,6,7,8,9}  : " << vecMean(test1) << endl;
	vector<double> test2{ 1,1,1 };
	cout << "{1,1,1}              : " << vecMean(test2) << endl;
	vector<double> test3{ 2,4,8,16 };
	cout << "{ 2,4,8,16 }         : " << vecMean(test3) << endl;
	
	return 0;
	
}
