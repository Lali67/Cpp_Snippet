/* 2019-W02-Exercise_5_03.cpp :

Exercise 5.3
   Schreiben Sie eine Funktion, die zwei Vektoren von double Werten als Parameter erhält und 
   einen Vektor von double Werten als Returnwert liefert. 
   Der retournierte Vektor soll immer abwechselnd einen Wert aus dem ersten Parameter und 
   einen Wert aus dem zweiten Parameter enthalten (beginnend mit dem ersten Wert aus dem ersten Parameter). 
   Die relative Reihenfolge der Werte soll im Ergebnisvektor gleich sein, wie in den Eingangsvektoren. 
   Sind die beiden Eingangsvektoren verschieden lang, 
   so ist der Rest des längeren Vektors unverändert an das Ergebnis anzuhängen. 
   Z.B.:
	Parameter:                          Ergebnis:
	{1,2,3} {4,5,6}                     {1,4,2,5,3,6}
	{1,2,3,4,5,6} {7,8,9}               {1,7,2,8,3,9,4,5,6}

Dániel Szöke (11913915)
08.11.2019

*/

#include <iostream>
#include <vector>
//#include <cmath>
//#include <exception>

using namespace std;


std::vector<double> insertVectorToVector(std::vector<double> vector1, std::vector<double> vector2) {
	
	unsigned int n1{ vector1.size() }, n2{ vector2.size() };
	unsigned int counter1{ 0 }, counter2{ 0 };
	std::vector<double> result;

	if (n1 >= n2) {
		while (counter1 < n1) {
			result.push_back(vector1.at(counter1));
			if (counter2 < n2)
				result.push_back(vector2.at(counter2));
			counter1++; counter2++;
		}
	}
	else {
		while (counter2 < n2) {
			if (counter1 < n1)
				result.push_back(vector1.at(counter1));
			result.push_back(vector2.at(counter2));
			counter1++; counter2++;
		}
	}
	
	return result;
}

int main()
{
	cout << "---------- Test ----------\n";
	std::vector<double> vec1{ 1,2,3,4,5,6 }, vec2{7, 8, 9};

	vec1 = insertVectorToVector(vec1, vec2);
	cout << "vec1{ 1, 2, 3, 4, 5, 6 }, vec2{7, 8, 9} --> Ergebnis: ";
	for (auto const& i : vec1) std::cout << i << " ";
	cout << endl;

	std::vector<double> vec3{ 1,2,3 }, vec4{ 4, 5, 6, 7, 8, 9 };

	vec3 = insertVectorToVector(vec3, vec4);
	cout << "vec1{ 1, 2, 3 }, vec2{4, 5, 6, 7, 8, 9} --> Ergebnis: ";
	for (auto const& i : vec3) std::cout << i << " ";
	cout << endl;


}
