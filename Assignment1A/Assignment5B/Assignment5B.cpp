// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 5B (Question 1)
// Create a function template that computes and displays the absolute value
// of a passed argument. (By "absolute value" we mean that the template
// returns the number with no sign, whether the passed argument number
// is positive or negative.)
//
// Create a program that uses this function template, passing in two
// arguments of type int, float, and double variable.
// Have the template produce as output "The absolute value of number is (put 
// in absolute value of number here)."

#include <iomanip>
#include <iostream>

using namespace std;

// Determines the absolute value of an item. 
template <typename T>
void absolute(T value)
{
	T absValue = value >= 0 ? value :  value * (T)-1;

	cout << "The absoluate value of " << value << " is " << absValue << endl;
}

// main execution method
int main()
{
	cout << "Welcome to the absolute finder!\n"
		<< "Here we will demonstrate a template method that is able to\n"
		<< "take an integer, float, or double and display the absolute\n"
		<< "value of the number.\n\n"
		<< "Let's begin...\n\n";

	int testInt = -123;
	int testPositiveInt = 7899;
	
	float testFloat = -123.456;
	float testPositiveFloat = 3233.12;

	double testDouble = -456.123;
	double testPositiveDouble = 874.1234;

	cout << "Integers:\n";
	absolute(testInt);
	absolute(testPositiveInt);

	cout << "\nFloats:\n";
	absolute(testFloat);
	absolute(testPositiveFloat);

	cout << "\nDoubles:\n";
	absolute(testDouble);
	absolute(testPositiveDouble);

	return 0;
}