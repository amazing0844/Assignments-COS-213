// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Comprehensive Assignment (Question 1)
//	Create a program to determine the largest number out of 15 numbers
//	entered(numbers entered one at a time).This should be done in a
//	function using this prototype:
//		double larger(double x, double y);
//	Make sure you use a forloop expression inside your function.
#include <iostream>
#include <iomanip>

using namespace std;

// Class defining methods and properties required for implementing a number comparing class
class NumberComparator
{
public:
	// Returns the larger of two doubles. If they are equal, the first value is returned.
	static double larger(double x, double y)
	{
		return x >= y ? x : y;
	}

	// Retruns the smaller of two doubles.
	static double smaller(double x, double y) 
	{
		return x < y ? x : y;
	}
};

// Program execution 
int main()
{
	// Instance of NumberComparator class used to compare numbers
	NumberComparator comparator;

	// The minimum number currently defined. This defaults to the maximum value for a double type.
	double currentMin = DBL_MAX;

	// The currentNumber being considered as a possible candidate for the maximum
	double currentNumber = currentMin;

	cout << "Welcome to the MinFinder. "
		"This program will take in a set of 15 numbers and display the minimum value "
		"in the set. Although doubles are allowed, the result will be displayed with a 0 precision " <<
		"(ex. 1, 2, 10002)\n\n" <<
		"Let's begin..." << endl;

	// Prompt the user for 15 numbers and update the currentMax value based on the provided values
	for (unsigned int i = 1; i <= 15; i++)
	{
		cout << "Number " << i << ": ";
		cin >> currentNumber;

		currentMin = NumberComparator::smaller(currentMin, currentNumber);
	}

	cout << setprecision(0) << fixed;
	cout << "Minimum value: " << currentMin;

	cin;

	return 0;
}

