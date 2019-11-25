/* 2019-W06-Exercise_6_03.cpp :

Exercise 6.3
  Schreiben Sie eine Funktion, die eine natürliche Zahl n als Parameter erhält und einen Vektor retourniert, 
  der alle Primzahlen < = n enthält. Verwenden Sie das Sieb des Erathostenes um die Primzahlen zu ermitteln.

Dániel Szöke (11913915)
15.11.2019

Algorithm: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    1. Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
    2. Initially, let p equal 2, the smallest prime number.
    3. Enumerate the multiples of p by counting in increments of p from 2p to n, and 
       mark them in the list (these will be 2p, 3p, 4p, ...; the p itself should not be marked).
    4. Find the first number greater than p in the list that is not marked. If there was no such number, stop. 
       Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.
    5. When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.

*/

#include <iostream>     // cout
#include <vector>       // vector
#include <cstdlib>      // qsort
//#include <string>       // string
//#include <algorithm>    // sort
//#include <cmath>        // sqrt
//#include <exception>    
//#include <stdexcept>    // runtime_error> 

using namespace std;

vector<int> SieveOfEratosthenes(int n){
    vector <bool> prime(n+1, true);
    vector <int> result;

    for (int p = 2; p * p <= n; p++)
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p) prime.at( i ) = false;

    // Get all prime numbers 
    for (int p = 2; p <= n; p++)
        if (prime.at(p)) result.push_back(p);

    return result;
}

int main()
{
    cout << "Der alle Primzahlen < = 30 : \n";
    for (auto const& item : SieveOfEratosthenes(30)) cout << item <<" ";
    cout << endl << endl;

    cout << "Der alle Primzahlen < = 300 : \n";
    for (auto const& item : SieveOfEratosthenes(300)) cout << item << " ";
    cout << endl;

    return 0;
}
