/* 2019-W06-Exercise_6_02.cpp :

  Exercise 6.2
  Schreiben Sie eine Funktion, die einen Vektor von double-Werten als Referenzparameter erhält und die Werte in diesem Vektor sortiert 
  (verwenden Sie dazu das Selection Sort Verfahren). Die Funktion soll folgende statistische Größen ermitteln und 
  an die aurufende Funktion zurückliefern: Summe der Werte, Mittelwert der Werte, Standardabweichung, Median und die übrigen Quartile. 
  (Es ist vorteilhaft, mehrere Hilfsfunktionen zu definieren, die jeweils eine Teilaufgabe durchführen.)

Dániel Szöke (11913915)
15.11.2019

*/

#include <iostream>     // cout
#include <vector>       // vector
//#include <cstdlib>      // qsort
//#include <string>       // string
#include <algorithm>    // sort
#include <cmath>        // sqrt
//#include <exception>    
#include <stdexcept>    // runtime_error

using namespace std;

double calculateSum(vector<double> vec) {
    double sum{0};

    for (auto const& item : vec) sum += item;
    return sum;
}
double calculateMean(vector<double> vec) {
    double sum{ 0 };
    if (vec.size() == 0)  
        throw runtime_error("calculateMean: Die Vektorgroesse muss groesse sien als Null!");
    
    for (auto const& item : vec) sum += item;
    
    return sum / vec.size();
}

double calculateMedian(vector<double> data)
{
    size_t size{ data.size() };

    if (size == 0)
        return 0;  // Undefined, really.
    else
    {
        sort(data.begin(), data.end());
        if (size % 2 == 0)
            return (data.at(size / 2 - 1) + data.at(size / 2)) / 2;
        else
            return data.at(size / 2);
    }
}

double calculateVariance(vector<double> data) {
    //link: https://de.wikipedia.org/wiki/Varianz_(Stochastik)
    //link: https://en.wikipedia.org/wiki/Variance

    double var{ 0 };
    double mean{ calculateMean(data) };
    for (auto const& item : data)  var += (item - mean) * (item - mean);

    return var / data.size();
}

double calculateStandardDeviation(vector<double> data) {
    // link: https://de.wikipedia.org/wiki/Empirische_Varianz#Abgeleitete_Begriffe
    // link: https://en.wikipedia.org/wiki/Standard_deviation

    return  sqrt(calculateVariance(data));
}

double calculateFirstQuatile(vector<double> data) {
    // link: https://en.wikipedia.org/wiki/Quartile

    size_t size{ data.size() };

    if (size == 0)
        return 0;  // Undefined, really.
    
    sort(data.begin(), data.end());
    return data.at(size / 4);
}

double calculateThirdQuatile(vector<double> data) {
    // link: https://en.wikipedia.org/wiki/Quartile

    size_t size{ data.size() };

    if (size == 0)
        return 0;  // Undefined, really.
   
    sort(data.begin(), data.end());
    return data.at(size * 3 / 4);
}

string basicStatistics(vector<double> data) {
    
    cout << "Die einen Vektor von double-Werten: "; for (auto const& item : data) cout << item << ", "; cout << endl;
    cout << "Summe der Werte                : " << calculateSum(data) << endl;
    cout << "Mittelwert der Werte           : " << calculateMean(data)   << endl;
    cout << "Median der Werte               : " << calculateMedian(data) << endl;
    cout << "Standardabweichung der Werte   : " << calculateStandardDeviation(data) << endl;
    cout << "Die uebrigen Quartile          : " << calculateFirstQuatile(data) << endl;
    cout << "Die richtigen Quartile         : " << calculateThirdQuatile(data) << endl;
    cout << endl;

    return "";
}

int main()
{
    vector<double> a{2,1,3,4,6,5,7,8,9};
    cout << basicStatistics(a);

    vector<double> b;
    for (int i = 10; i < 20; i++) {
        b.push_back(i*3.14 + std::rand() % 100);
    }
    cout << basicStatistics(b);

    return 0;
}
