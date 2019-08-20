#include <iostream>
#include "IntArray.h"

/*
	https://www.learncpp.com/cpp-tutorial/106-container-classes/

	There are many different kinds of container classes, each of which has various advantages,
	disadvantages, and restrictions in their use. By far the most commonly used container
	in programming is the array, which you have already seen many examples of. Although C++ has
	built-in array functionality, programmers will often use an array container class
	(std::array or std::vector) instead because of the additional benefits they provide.
*/

int main()
{
	// Declare an array with 10 elements
	IntArray array(10);

	// Fill the array with numbers 1 through 10
	for (int i = 0; i < 10; i++)
		array[i] = i + 1;

	// Resize the array to 8 elements
	array.resize(8);

	// Insert the number 20 before element with index 5
	array.insertBefore(20, 5);

	// Remove the element with index 3
	array.remove(3);

	// Add 30 and 40 to the end and beginning
	array.insertAtEnd(30);
	array.insertAtBeginning(40);

	// Print out all the numbers
	for (int j = 0; j < array.getLength(); j++)
		std::cout << array[j] << " ";

	return 0;
}