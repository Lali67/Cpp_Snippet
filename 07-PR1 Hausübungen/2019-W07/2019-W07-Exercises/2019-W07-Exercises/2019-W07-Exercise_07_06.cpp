/*2019 - W07 - Exercise_7_04.cpp :


Exercise 7.6
  Schreiben Sie eine Funktion ''int count(int n)'', die die Anzahl der Einsen in der Binärdarstellung 
  der Zahl n retourniert. Verwenden Sie in der Funktion count weder Multiplikation (*,*=), 
  noch Division (/,/=)

*/

#include <iostream>

using namespace std;

// recursive function to count set bits 
int count(int n)
{
    // base case 
    if (n == 0)
        return 0;
    else
        // if last bit set add 1 else add 0 
        return (n & 1) + count(n >> 1);
}


int main()
{
    cout << " 8    set bits are " << count(8) << endl;
    cout << " 120  set bits are " << count(120) << endl;
    cout << " 1600 set bits are " << count(1600) << endl;

    return 0;
}