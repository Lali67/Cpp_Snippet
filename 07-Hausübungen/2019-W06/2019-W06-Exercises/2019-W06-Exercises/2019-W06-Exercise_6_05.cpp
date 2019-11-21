/* 2019-W06-Exercise_6_04.cpp :

Exercise 6.5
    Schreiben Sie eine Funktion, die zwei Vektoren von double Werten als Parameter erhält. 
    Die beiden Vektoren sind als Koordinaten von Punkten zu interpretieren, wobei der erste Vektor die x-Koordinaten und 
    der zweite Vektor an der entsprechenden Indexposition die jeweils zugehörige y-Koordinate enthält. 
    Die Funktion soll die Parameter a und b der Regressionsgeraden y=ax+b zu den gegebnen Punkten ermitteln und 
    an die aufrufende Funktion zurückliefern. Weiters ist der Indexwert jenes Punktes zurückzuliefern, 
    der am weitesten von der Regressionsgeraden entfernt ist (bei mehreren gleich weit enfernten Punkten kann 
    einer davon beliebig gewählt werden). 
    Sollten die Anzahlen von x- und y-Koordinaten verschieden sein, oder sich die Regressionsgerade nicht 
    in der Form ax+b darstellen lassen, so ist eine Exception vom Typ runtime_error zu werfen.


Dániel Szöke (11913915)
15.11.2019

*/

#include <iostream>     // cout
#include <vector>       // vector
//#include <cstdlib>      // qsort
//#include <string>       // string
//#include <algorithm>    // sort
//#include <cmath>        // sqrt
//#include <exception>    
#include <stdexcept>    // runtime_error
//#include <cassert>      // assert
#include <numeric>      // inner_product, accumulate

using namespace std;

//https://towardsdatascience.com/introduction-to-machine-learning-algorithms-linear-regression-14c4e325882a


double getSlopeofRegressionLine(vector<double>& x, vector<double>& y){

    if (x.size() != y.size())
        throw runtime_error("The size of x and y vecttor must be same!!!");

    double sx  = accumulate(x.begin(), x.end(), 0);
    double sy  = accumulate(y.begin(), y.end(), 0);
    double sxx = inner_product(x.begin(), x.end(), x.begin(), 0);
    double sxy = inner_product(x.begin(), x.end(), y.begin(), 0);


    int n      = static_cast<int>(x.size());

    // (n*sxy — sx*sy)/(n*sxx — sx*sx)
    double nor   = n * sxy - sx * sy;
    double denor = n * sxx - sx * sx;
    
    if (denor != 0) return nor / denor;
    return numeric_limits<double>::max();
}

double getInterceptofRegressionLine(vector<double>& x, vector<double>& y, double slope){
    if (x.size() != y.size())
        throw runtime_error("The size of x and y vecttor must be same!!!");

    double sx = accumulate(x.begin(), x.end(), 0);
    double sy = accumulate(y.begin(), y.end(), 0);
    int n     = static_cast<int>(x.size());

    return (sy - slope * sx) / n;
}


double getCost(vector<double>& x, vector<double>& y, double a, double b, double& da, double& db){
    // slope:a, intercept:b,  derivative of slope: da, derivative of intercept: db

    if (x.size() != y.size())
        throw runtime_error("The size of x and y vecttor must be same!!!");

    int n       = static_cast<int>(x.size());
    double sx   = accumulate(x.begin(), x.end(), 0);
    double sy   = accumulate(y.begin(), y.end(), 0);
    double sxx  = inner_product(x.begin(), x.end(), x.begin(), 0);
    double sxy  = inner_product(x.begin(), x.end(), y.begin(), 0);
    double syy  = inner_product(y.begin(), y.end(), y.begin(), 0);

    double cost = syy - 2 * a * sxy - 2 * b * sy + a * a * sxx + 2 * a * b * sx + n * b * b;

    cost /= n;
    da = 2 * (-sxy + a * sxx + b * sx) / n;
    db = 2 * (-sy + a * sx + n * b) / n;

    return cost;

}

void simpleLinearRegression(vector<double>& x, vector<double>& y, double slope = 1, double intercept = 0,
                        double lrate = 0.0002, double threshold = 0.01){

    int iter{ 0 };

    if (x.size() != y.size())
        throw runtime_error("The size of x and y vecttor must be same!!!");

    while (true){

        double da{ 0 }, db{ 0 }, cost{ 0 };

        da = 0;  db = 0;
        cost = getCost(x, y, slope, intercept, da, db);

        if (iter % 500000 == 0){
            cout << "Iter: " << iter << " cost = " << cost << " da = " << da << " db = " << db << endl;
        }

        iter++;
        if (abs(da) < threshold && abs(db) < threshold){
            cout << "\n2. Regression line with Machine Learning method: " << endl;
            cout << "y = " << slope << " * x + " << intercept << endl;
            break;
        }

        slope -= lrate * da;
        intercept -= lrate * db;
    }
}

int main() {

    vector<double> x = { 71, 73, 64, 65, 61, 70, 65, 72, 63, 67, 64 };
    vector<double> y = { 160, 183, 154, 168, 159, 180, 145, 210, 132, 168, 141 };

    // initialize with random two points
    cout << "x coordinates: ";
    for (auto const& item : x) cout << item << ", "; cout << endl;
    cout << "y coordinates: ";
    for (auto const& item : y) cout << item << ", "; cout << endl;
    cout << "\n1. Regression line from two random 2 points -> x{ 71, 73 }, y{ 160, 183 }" << endl;
    vector<double> xSub = { 71, 73 };
    vector<double> ySub = { 160, 183 };

    double slopeSub = getSlopeofRegressionLine(xSub, ySub);
    double interceptSub = getInterceptofRegressionLine(xSub, ySub, slopeSub);
    cout << "y = " << slopeSub << " * x + " << interceptSub << endl;
    cout << "------------------------------------------\n\n";

    simpleLinearRegression(x, y, slopeSub, interceptSub);

    cout << "------------------------------------------\n\n";
    cout << "3. Regression line from all (x,y) points :" << endl;
    double slope = getSlopeofRegressionLine(x, y);
    double intercept = getInterceptofRegressionLine(x, y, slope);
    cout << "y = " << slope << " * x + " << intercept << endl;

    return 0;

}
