// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 5A (Question 1)
//
// Design a fraction class. The class should have 2 data members to represent
// the numerator and denominator. Both of these numbers should obviously
// be integers. It should be able to display a fraction and include an operator
// for performing multiplication of fractions.
//
// Construct the fractionclass with 3 constructors. The first is the default.
// The second constructor should allow us to create a fraction that
// represents a whole number. The third constructor should allow us to
// specify the numerator and denominator of a new fraction object. The
// public functions should include functions for respectively getting the
// numerator and denominator, setting the respective numerator and
// denominator, multiplying fractions, and displaying the fraction.
//
// You should then use this class in a program that multiplies fractions.
// (Hint : you can create 3 fractionobjects f1, f2, and f3. You can use the
// public function readFraction that reads 2 fractions f1 and f2. You can then
// use the statement f3 = f1.multiply(f2) to calculate f1 * f2 and assign the
// result to f3.)
//
// The function's input prompts should be "Enter 1st fraction" and "Enter 
// 2nd fraction" where the user enters the appropriate fractions. In addition, 
// the program needs to display the resultof the multiplication operation in
// the readable format:
//
// 3/4 * 5/6 = 15/24
//
// This result should be displayed on one line.
//
// Test the function with the fractions 3/4 and 5/6 and also with 1/2 and 1.
// (Note that your result will not provide the fraction in reduced form and
// you do not have to write code to reduce the fraction.Also note that we
// have not restricted a fraction with a denominator of 0, but this would be a
// nice addition to your program.)


#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Class representing a fraction (x/y)
class Fraction
{
public:
	// Default constructor. This initializes the numerator and denominator to 1.
	Fraction()
	{
		this->setNumerator(1);
		this->denominator = 1;
	}

	// Constructor initializing the Fraction as a whole number, numerator equals denominator.
	Fraction(int wholeNumber)
	{
		this->setNumerator(wholeNumber);
		this->denominator = 1;
	}

	// Constructor initializing the Fraction with a numerator and a denominator.
	Fraction(int numerator, int denominator)
	{
		this->setNumerator(numerator);
		this->denominator = denominator;
	}

	// Sets the numerator for the Fraction
	void setNumerator(int numerator)
	{
		this->numerator = numerator;
	}

	// Gets the denominator of the Fraction
	int getNumerator()
	{
		return this->numerator;
	}

	// Sets the denominator of the fraction
	void setDenominator(int denominator)
	{
		if (denominator == 0)
		{
			throw out_of_range("A fraction's denominator cannot be 0.");
		}

		this->denominator = denominator;
	}

	// Gets the denominator of the fraction
	int getDenominator()
	{
		return this->denominator;
	}

	// Takes a Fraction operand and multiplies it by the current Fraction and returns the result.
	// The operation does not reduce the resulting fraction.
	Fraction multiply(Fraction op2)
	{
		int newNumerator = this->getNumerator() * op2.getNumerator();
		int newDenominator = this->getDenominator() * op2.getDenominator();

		return Fraction(newNumerator, newDenominator);
	}

	// Converts the Fraction to a string and returns the result. If the numerator and denominator
	// equal each other return 1. Otherwise, the fraction.
	string display()
	{
		stringstream ss;

		if (this->getDenominator() != 1)
		{
			ss << this->getNumerator() << "/" << this->getDenominator();
		}
		else
		{
			ss << this->getNumerator();
		}

		return ss.str();
	}

private:
	// The numerator for the Fraction
	int numerator;

	// The denominator for the Fraction
	int denominator;
};

// Main execution method
int main()
{
	cout << "Welcome to the Fraction multiplier application.\n"
		<< "This application will demonstrate a Fraction class that is\n"
		<< "able to define fractions as numerator and denominator pairs,\n"
		<< "multiply two fractions, and display the fraction in numerator/denominator\n"
		<< "format or as a whole number when the denominator is one.\n\n"
		<< "Let's begin...\n\n";

	cout << "Working with two fractions with different numerators and denominators...\n";

	Fraction f1(3, 4);
	Fraction f2(5, 6);

	Fraction f3 = f1.multiply(f2);

	cout << f1.display() << " * " << f2.display() << " = " << f3.display() << endl;

	cout << "\nWorking with a fraction defined as a whole number...\n";

	f1 = Fraction(1, 2);
	f2 = Fraction(1);

	f3 = f1.multiply(f2);

	cout << f1.display() << " * " << f2.display() << " = " << f3.display() << endl;

	return 0;
}