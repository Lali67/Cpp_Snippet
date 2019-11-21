/* 2019-W02-Exercise_6_01.cpp :

Exercise 6.1
 Im Rahmen eines Versuchs werden Testreihen durchgeführt. Jede Testreihe liefert als Ergebnis einen Vektor 
 von ganzzahligen Messwerten. Alle Ergebnisse werden in einem Vektor vom Typ vector<vector<int>> zusammengefasst], 
 dessen Elemente jeweils ein Testreihenergebnis enthalten. Für die statistische Untersuchung ist es notwendig, 
 die Zahlen derart in Gruppen zu teilen, dass in jeder Gruppe nur Zahlen der gleichen Größenordnung 
 (mit gleich vielen Dezimalstellen) liegen. Schreiben Sie dazu eine Funktion, 
 die einen Vektor vom Typ vector<vector<int>> als Parameter erhält und die Zahlen so umordnet, 
 dass alle einstelligen Zahlen im ersten Element des Vektors enthalten sind, alle zweistelligen im zweiten usw. 
 (Gruppen, die gar keine Elemente enhalten, können ignoriert werden. Die Reihenfolge der Zahlen in den einzelnen Gruppen 
 ist nicht von Bedeutung) Die Funktion soll als return Wert einen Vektor von double Werten liefern, 
 der die Mittelwerte der Gruppen beinhaltet. 
 Z.B.:
	Testreihe 1: 5 12 2430 1 17
	Testreihe 2: 5219 22 9 12
	Testreihe 3: 7 9 18 4231

	umgeordneter Vektor : {{5, 1, 9, 7, 9}, {12, 17, 22, 12, 18}, {2430, 5219, 4231}}
	Returnwert: {6.2, 16.2, 3960}

Dániel Szöke (11913915)
15.11.2019

*/

#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <exception> 

using namespace std;

// compare is used by the library qsort() function to sort an array of int
int compare(const void* a, const void* b);

double calculateMean(vector<int> vec) {
    double sum{ 0 };

    for (auto const& item : vec) sum += item;
    return sum / vec.size();
}

double calculateMedian(vector<int> data)
{
    size_t size{ data.size() };

    if (size == 0)
        return 0;  // Undefined, really.
    else
    {
        qsort(data.data(), size, sizeof(int), compare);
        if (size % 2 == 0)
            return (data.at(size / 2 - 1) + data.at(size / 2)) / 2;
        else
            return data.at(size / 2);
    }
}

vector<double> analyzeAttemptResults(vector<vector<int>> scores) {
    vector<double> meansOfGroup;
    vector<int> temp, aGroup; 
    long tens{ 1 }, counter{0};
    
    // copy elements from vectors of "scores" to temp
    for (auto const& vec : scores)
        for (auto const& item : vec) {
            temp.push_back(item);
        }
    //sort "temp" elements, ascending
    qsort(temp.data(), temp.size(), sizeof(int), compare);
    
    //calculate next degree multiply "tens" with 10
    while (temp.at(counter) / tens > 0) tens *= 10;

    //separate element to different group
    do {
        
        if (temp.at(counter) / tens == 0) {
            //store value
            aGroup.push_back(temp.at(counter));
        }
        if (temp.at(counter) / tens != 0 ) {
            meansOfGroup.push_back(calculateMean(aGroup)); 
            //for (auto const& item : aGroup) cout << item << ", "; cout << endl;
            aGroup.clear();
            while (temp.at(counter) / tens != 0) tens *= 10;
            aGroup.push_back(temp.at(counter));
        }
        //evaluate Mean from last Group
        if(counter == temp.size() - 1) 
            meansOfGroup.push_back(calculateMean(aGroup));

    } while (++counter < temp.size());

    return meansOfGroup;
}
// Needed for library function qsort()  
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    vector<vector<int>> a{ { 5, 12, 2430, 1, 17 }, {5219, 22, 9, 12}, {7, 9, 18, 4231 } };

    cout << "Umgeordneter Vektor : " << "{ {5, 1, 9, 7, 9}, { 12, 17, 22, 12, 18 }, { 2430, 5219, 4231 }}\n";
    cout << "Returnwert          : "; for (auto const& item : analyzeAttemptResults(a)) cout << item << ", ";
    cout << endl <<endl;

    vector<vector<int>> b{ { 23, 122, 2430, 18, 17776 }, {5219, 223, 9, 12}, {7, 90, 18, 4231 } };

    cout << "Umgeordneter Vektor : " << "{ {23, 122, 2430, 18, 17776 }, {5219, 223, 9, 12}, {7, 90, 18, 4231 }}\n";
    cout << "Returnwert          : "; for (auto const& item : analyzeAttemptResults(b)) cout << item << ", ";
    cout << endl << endl;
}
