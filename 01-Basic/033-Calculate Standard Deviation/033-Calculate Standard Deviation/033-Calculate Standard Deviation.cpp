// 033-Calculate Standard Deviation.cpp 

/*
	This program calculates the standard deviation of 10 data using arrays. 
		https://www.programiz.com/cpp-programming/examples/standard-deviation

	To understand this example, you should have the knowledge of following C++ programming topics:

		C++ Arrays(https://www.programiz.com/cpp-programming/arrays)
		C++ for Loop(https://www.programiz.com/cpp-programming/for-loop)
		C++ Functions(https://www.programiz.com/cpp-programming/function)
		C++ while and do...while Loop(https://www.programiz.com/cpp-programming/do-while-loop)

	This program calculates the standard deviation of a individual series using arrays. 
	Visit this page to learn about Standard Deviation
		(http://www.mathsisfun.com/data/standard-deviation.html).

	To calculate the standard deviation, calculateSD() function is created. 
	The array containing 10 elements is passed to the function and this function calculates 
	the standard deviation and returns it to the main() function.

*/

#include <iostream>
#include <cmath>

using namespace std;

float calculateSD(float data[]);

int main()
{
	int i;
	float data[10];
	cout << "Enter 10 elements: ";
	for (i = 0; i < 10; ++i)
		cin >> data[i];
	cout << endl << "Standard Deviation = " << calculateSD(data) << "\n\n";
	return 0;
}

float calculateSD(float data[])
{
	float sum = 0.0, mean, standardDeviation = 0.0;
	int i;
	for (i = 0; i < 10; ++i)
	{
		sum += data[i];
	}
	mean = sum / 10;
	for (i = 0; i < 10; ++i)
		standardDeviation += pow(data[i] - mean, 2);
	return sqrt(standardDeviation / 10);
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
