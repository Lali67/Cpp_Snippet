/* 2019-W06-Exercise_6_04.cpp :

Exercise 6.4
   Schreiben Sie eine Funktion, die als Parameter zwei Matrizen von ganzen Zahlen (Datentyp vector<vector<int>>), 
   entspricht einem Vektor von Zeilen, die wieder aus einem Vektor von Spalten mit jeweils einem int-Wert bestehen) 
   erhält und das Produkt der beiden Matrizen retourniert. Falls einer der Eingangsparameter 
   keine gültige Matrix darstellt (weil die Zeilen z.B. unterschiedlich lang sind) oder 
   das Produkt nicht berechnet werden kann, ist eine Exception vom Typ runtime_error zu werfen.

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

using namespace std;

// multiplies two matrixes: matrix1 and matrix2 --> product  
vector<vector<int>> multiplyMatrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
    //If matrix1 is (m × r) matrix and matrix2 is (r × n) matrix, then the product matrix is m × n matrix
    unsigned m = matrix1.size();
    unsigned r = matrix2.size();
    unsigned n = matrix2.at(0).size();

    vector<vector<int>> result(m, vector<int>(n, 0));

    for (auto const& row : matrix1)
        if (row.size() != r)
            throw runtime_error("Error: Matrix1 is not (m x r) matrix!");
    for (auto const& row : matrix2)
        if (row.size() != n)
            throw runtime_error("Error: Matrix2 is not (r x n) matrix!");

    for (unsigned i = 0; i < m; i++)
        for (unsigned j = 0; j < n; j++)
            for (unsigned k = 0; k < r; k++)
                result.at(i).at(j) += matrix1.at(i).at(k) * matrix2.at(k).at(j);
    
    return result;
        
}

void printMatrix(vector<vector<int>>mat1) {
    for (auto const& row : mat1) {
        for (auto const& item : row)
            cout << item << " ";
        cout << "\n";
    }
    cout << endl;
}

// Driver Code 
int main()
{
    vector<vector<int>> result;
    vector<vector<int>>mat1 = { 
        {1, 2 },
        {3, 4 } };

    vector<vector<int>>mat2 = {
        {5, 6, 9 },
        {7, 8, 9 } };

    result = multiplyMatrix(mat1, mat2);

    cout << "Matrix1 is \n";
    printMatrix(mat1);

    cout << "Matrix2 is \n";
    printMatrix(mat2);

    cout << "Product of two matrixes is \n";
    printMatrix(result);

    return 0;
}
