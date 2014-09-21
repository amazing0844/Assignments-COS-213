// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Final Project Problem 4
//
// The following function compares integers of type int and gives as a result the smaller number :
//
// int min(int a, int b)
// {
//		if (a < b)
//			return a;
//		else
//			return b;
// }
//
// Convert this function to a template

#include <iomanip>
#include <iostream>

using namespace std;

// Template method to determine the minimum of two items of type T
template <typename T>
T min(T a, T b)
{
	if (a < b)
	{
		return a;
	}

	return b;
}

// main execution method
int main()
{
	int firstInt = 0;
	int secondInt = 0;

	cout << "Enter two integers: ";
	cin >> firstInt >> secondInt;

	cout << "The minimum of " << firstInt << " and " << secondInt << " is " << min(firstInt, secondInt) << "\n";

	char firstChar = 'a';
	char secondChar = 'a';

	cout << "Enter two characters: ";
	cin >> firstChar >> secondChar;

	cout << "The minimum of " << firstChar << " and " << secondChar << " is " << min(firstChar, secondChar) << "\n";

	return 0;
}