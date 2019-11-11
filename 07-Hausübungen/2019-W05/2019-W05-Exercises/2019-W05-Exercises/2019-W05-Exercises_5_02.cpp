/* 2019-W02-Exercise_5_01.cpp :

Exercise 5.2
  Schreiben Sie eine Funktion, die einen Vektor von ganzen Zahlen als Parameter erhält und 
  einen entsprechenden Vektor von ganzen Zahlen retourniert, 
  in dem jeweils zwei benachbarte Einträge vertauscht sind. 
  Verwenden Sie keine Schleife in Ihrer Funktion. 
   Z.B.:
     Ausgangsvektor: {1,2,3,4,5,6}    Ergebnisvektor: {2,1,4,3,6,5}

Dániel Szöke (11913915)
08.11.2019

*/

#include <iostream>
#include <vector>
//#include <cmath>
//#include <exception>

using namespace std;


std::vector<int> swapPairbyRecursion(std::vector<int> intVec, unsigned int counter=0) {

	if (counter <= intVec.size() - 2 ) {
		std::swap(intVec[counter], intVec[counter + 1]);
		counter += 2;
		intVec = swapPairbyRecursion(intVec, counter);
	}

	return intVec;
}

int main()
{
	cout << "---------- Test ----------\n";
	std::vector<int> vec1{ 1, 2, 3, 4, 5, 6, 7 };
	vec1 = swapPairbyRecursion(vec1);
	cout << "vector1: {1,2,3,4,5,6,7} --> Ergebnis: ";
	for (auto const& i : vec1) std::cout << i << " ";
	cout << endl;

	std::vector<int> vec2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vec2 = swapPairbyRecursion(vec2);
	cout << "vector2: {1,2,3,4,5,6,7,8,9,10} --> Ergebnis: ";
	for (auto const& i : vec2) std::cout << i << " ";
	cout << endl;

}
