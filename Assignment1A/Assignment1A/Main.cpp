// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 1A (Question 1)
//	Create a program to determine the largest number out of 15 numbers
//	entered(numbers entered one at a time).This should be done in a
//	function using this prototype:
//		double larger(double x, double y);
//	Make sure you use a forloop expression inside your function.
#include <iostream>
#include <iomanip>

using namespace std;

// Class defining methods and properties required for implementing a maximum value finder
class MaxFinder
{
public:
	// Returns the larger of two doubles. If they are equal, the first value is returned.
	double larger(double x, double y)
	{
		return x >= y ? x : y;
	}
};

// Program execution 
int main()
{
	// Instance of MaxFinder class used to determine the maximum number
	MaxFinder maxFinder;

	// The maximum number currently defined. This defaults to the minimum value for a double type.
	double currentMax = -DBL_MAX;

	// The currentNumber being considered as a possible candidate for the maximum
	double currentNumber = currentMax;

	cout << "Welcome to the MaxFinder. "
		"This program will take in a set of 15 numbers and display the maximum value "
		"in the set. Although doubles are allowed, the result will be displayed with a 0 precision " <<
		"(ex. 1, 2, 10002)\n\n" << 
		"Let's begin..." << endl;
	
	// Prompt the user for 15 numbers and update the currentMax value based on the provided values
	for (unsigned int i = 1; i <= 15; i++)
	{
		cout << "Number " << i << ": ";
		cin >> currentNumber;

		currentMax = maxFinder.larger(currentMax, currentNumber);
	}

	cout << setprecision(0) << fixed;
	cout << "Max value: " << currentMax;

	cin;

	return 0;
}

