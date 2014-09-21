// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 6A (Question 1)
// Division by Zero Problem : Create a program titled Division. Have the
// program prompt the user "Enter numerator and denominator" and store
// the two values entered.
//
// (If you wish the user to "Enter numerator/denominator" be sure to adjust
// your data gathering variables to include a holder variable for the slash
// character.)
//
// Include a function titled Quotient that takes 2 integers as input and
// provides the quotient of the 2 integers as integer output. (The remainder
// is truncated.Thus, 5 / 3 will be 1.)
//
// Define an exception class divByZero and have the function Quotient use
// throw for an exception of this type if the denominator is 0. Display output
// "You cannot have a denominator that is equal to 0."
//
// Quotient throws an exception to the higher - level function main to decide
// whether or not the program should be terminated.Main catchesthe
// divByZero and prints out an appropriate comment on the screen. Also
// include in main a try block to catch the divide - by - zero error.
//
//If no exception occurs, print out a message "The quotient is xxxxx."

#include <iomanip>
#include <iostream>

using namespace std;

// Exception to handle case where a division operation is attempted when the
// denominator is zero.
class divByZero : public std::runtime_error
{
public:
	divByZero()
		: std::runtime_error("You cannot have a denominator that is equal to 0.") {}
};

int Quotient(int numerator, int denominator)
{
	if (denominator == 0)
	{
		throw divByZero();
	}

	return numerator / denominator;
}

// Main execution path
int main()
{
	cout << "Welcome to the Division program.\n "
		<< "In this program, you'll be prompted for a numerator and denominator\n"
		<< "and the quotient will be returned.\n"
		<< "Let's begin...\n\n";

	int numerator = 0;
	int denominator = 0;

	cout << "Enter numerator and denominator: ";
	cin >> numerator >> denominator;

	try
	{
		int quotient = Quotient(numerator, denominator);
		cout << "The quotient is " << quotient;
	}
	catch (divByZero &divByZero)
	{
		cout << divByZero.what() << endl;
	}

	return 0;
}