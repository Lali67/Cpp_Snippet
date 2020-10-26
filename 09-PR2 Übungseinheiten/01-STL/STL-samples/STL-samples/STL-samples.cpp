/* STL-samples.cpp : This file contains the 'main' function. Program execution begins and ends there.
* 
* https://www.geeksforgeeks.org/the-c-standard-template-library-stl/?ref=lbp
*/
 
#include <iostream> 
#include <utility> //pair STL
#include <list> 
#include <iterator> 
#include <deque>
using namespace std;

//function for printing the elements in a list 
void showlist(list <int> g)
{
    list <int> ::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

void showdq(deque <int> g)
{
    deque <int> ::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main()
{
    //CPP program to illustrate pair STL
    pair <int, char> PAIR1;

    PAIR1.first = 100;
    PAIR1.second = 'G';

    cout << "--------- Pair in C++ Standard Template Library (STL) " << endl;
    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;
    
    //-------- - List in C++ Standard Template Library(STL)-------- -
    cout << "--------- List in C++ Standard Template Library (STL)--------- " << endl;
    list <int> gqlist1, gqlist2;

    for (int i = 0; i < 10; ++i)
    {
        gqlist1.push_back(i * 2);
        gqlist2.push_front(i * 3);
    }
    cout << "\nList 1 (gqlist1) is : ";
    showlist(gqlist1);

    cout << "\nList 2 (gqlist2) is : ";
    showlist(gqlist2);

    cout << "\ngqlist1.front() : " << gqlist1.front();
    cout << "\ngqlist1.back() : " << gqlist1.back();

    cout << "\ngqlist1.pop_front() : ";
    gqlist1.pop_front();
    showlist(gqlist1);

    cout << "\ngqlist2.pop_back() : ";
    gqlist2.pop_back();
    showlist(gqlist2);

    cout << "\ngqlist1.reverse() : ";
    gqlist1.reverse();
    showlist(gqlist1);

    cout << "\ngqlist2.sort(): ";
    gqlist2.sort();
    showlist(gqlist2);
    
    //--------- List in C++ Standard Template Library (STL)---------
    cout << "--------- List in C++ Standard Template Library (STL)--------- " << endl;
    deque <int> gquiz;
    gquiz.push_back(10);
    gquiz.push_front(20);
    gquiz.push_back(30);
    gquiz.push_front(15);
    cout << "The deque gquiz is : ";
    showdq(gquiz);

    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.max_size() : " << gquiz.max_size();

    cout << "\ngquiz.at(2) : " << gquiz.at(2);
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();

    cout << "\ngquiz.pop_front() : ";
    gquiz.pop_front();
    showdq(gquiz);

    cout << "\ngquiz.pop_back() : ";
    gquiz.pop_back();
    showdq(gquiz);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
