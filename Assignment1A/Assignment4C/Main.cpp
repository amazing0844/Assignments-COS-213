// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 4C (Question 2)
// 
// Develop the class Polynomial. The internal representation of a Polynomial
// is an array of terms. Each term contains a coefficient and an exponent.
// The term :
//	2x^4
// has the coefficient of 2 and the exponent 4. Develop a complete class
// containing proper constructor and destructor functions as well as set and
// get functions. The class should also provide the following overloaded
// operator capabilities :
//	-  Overload the addition operator (+) to add two Polynomials.
//	-  Overload the subtraction operator (-) to subtract two Polynomials.

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// The maximum number of terms allowed in a polynomial
const size_t maxPolynomialSize = 200;

// Class defining the elements of a term for a polynomial. A term consists of a coefficient
// an indeterminate (for our example, this will always be x,) and an exponent
class Term
{
public:
	// Constructor for the Term class
	Term(int coefficient = 1, char indeterminate = 'x', int exponent = 1)
	{
		this->setCoefficient(coefficient);
		this->setIndeterminate(indeterminate);
		this->setExponent(exponent);
	}

	// sets the coefficient value for the Term instance
	void setCoefficient(int coefficient)
	{
		this->coefficient = coefficient;
	}

	// gets the coefficient value of the Term instance
	int getCoefficient()
	{
		return this->coefficient;
	}

	// sets the indeterminate value for the Term instance. This needs to be a lower case letter
	void setIndeterminate(char indeterminate)
	{
		if (indeterminate < 'a' || indeterminate > 'z')
		{
			throw out_of_range("indeterminate must be a lower case letter [a-z].");
		}

		this->indeterminate = indeterminate;
	}

	// gets the indeterminate of the Term instance
	char getIndeterminate()
	{
		return this->indeterminate;
	}

	// sets the exponent value for the Term instance
	void setExponent(int exponent)
	{
		this->exponent = exponent;
	}

	// gets the exponent value of the Term instance
	int getExponent()
	{
		return this->exponent;
	}
	
	friend std::ostream &operator<<(std::ostream &, const Term &);

private:
	// The coeffient of the Term
	int coefficient;

	// the Indeterminate of the Term
	char indeterminate;

	// The exponent of the term
	int exponent;
};

// Overloaded stream insertion operator for Term items.
ostream &operator<<(ostream &output, const Term &term)
{
	Term targ = term;

	// nothing to do here. The value is always 0
	if (targ.getCoefficient() == 0)
	{
		return output;
	}

	// output the coeffienct
	if (targ.getCoefficient() == -1)
	{
		output << "-";
	}
	else if (targ.getCoefficient() != 1)
	{
		output << targ.getCoefficient();
	}

	if (targ.getExponent() == 0)
	{
		return output;
	}

	output << targ.getIndeterminate();

	if (targ.getExponent() != 1)
	{
		output << "^" << targ.getExponent();
	}
	
	return output;
}

// Class defining the elements of a Polynomial. A polynomial consists of a set of Terms
class Polynomial
{
public:
	// default constructor
	Polynomial()
	{
		this->initializeTerms();
	}

	// Constructor taking an array of terms. This will assign all of the terms (up to
	// the maximum number allowed in a polynomial) to the Polynomial's array
	Polynomial(Term* terms[], size_t length)
	{
		this->initializeTerms();

		for (int i = 0; i < maxPolynomialSize && i < length; i++)
		{
			this->terms[i] = terms[i];
		}
	}

	// Constructor taking a single term and assigning it to the first item in the terms
	// array
	Polynomial(Term term)
	{
		this->initializeTerms();
		this->AddTerm(&term);
	}

	// Cycles through the terms already defined. If it finds a term where the indeterminate
	// and exponent are equal, it adds the coefficients together. Otherwise, it inserts the new
	// term at the end of the array. If there are no more empy spots in the terms array, an
	// exception is thrown.
	void AddTerm(Term* term)
	{
		for (int i = 0; i < maxPolynomialSize; i++)
		{
			Term *curTerm = this->terms[i];

			// if the current location in the terms array is empty, insert the term passed as an argument
			if (curTerm == nullptr)
			{
				this->terms[i] = term;
				return;
			}

			// if the inderminate and exponent of the current term match the term passed as an argument, add the
			// coefficients together
			if (curTerm->getIndeterminate() == term->getIndeterminate() && curTerm->getExponent() == term->getExponent())
			{
				this->terms[i]->setCoefficient(curTerm->getCoefficient() + term->getCoefficient());
				return;
			}
		}

		throw out_of_range("Exceeded maximum allowable number of terms");
	}

	// overloaded subscript operator for the terms array
	Term* operator [](size_t subscript) const
	{
		if (subscript < 0 || subscript >= maxPolynomialSize)
		{
			throw out_of_range("Subscript out of range");
		}

		return this->terms[subscript];
	}

	// Overloads the addition operator to add the terms of the current polynomials to
	// the terms of the second operand and returns the results
	Polynomial operator +(const Polynomial& op2)
	{
		Polynomial result(this->terms, maxPolynomialSize);

		for (int i = 0; i < maxPolynomialSize; i++)
		{
			Term* newTerm = op2[i];
			
			if (newTerm == nullptr)
			{
				break;
			}

			result.AddTerm(newTerm);
		}

		return result;
	}

	friend std::ostream &operator<<(std::ostream &, const Polynomial &);

private:
	// Array of terms for the polynomial
	Term* terms[maxPolynomialSize];

	// Initializing the array to be nullptrs so that empty cells can be identified
	void initializeTerms()
	{
		for (int i = 0; i < maxPolynomialSize; i++)
		{
			this->terms[i] = nullptr;
		}
	}
};

// Overloaded binary output operator for the Polynomial class
ostream &operator<<(ostream &output, const Polynomial &polynomial)
{
	for (int i = 0; i < maxPolynomialSize; i++)
	{
		if (polynomial.terms[i] != nullptr)
		{
			Term currentTerm = *polynomial.terms[i];

			if (i > 0)
			{
				if (currentTerm.getCoefficient() < 0)
				{
					output << " + (" << currentTerm << ")";
				}
				else
				{
					output << " + " << currentTerm;
				}
			}
			else
			{
				output << currentTerm;
			}
		}
		else
		{
			return output;
		}
	}

	return output;
}

// Program execution method
int main()
{
	cout << "\n\nWelcome to the Polynomial demonstrator. In this app, we will\n"
		<< "create polynomials using coefficients, indeterminates, and exponents.\n"
		<< "(ex. 2x^4). We will also show how you can add the terms together and\n"
		<< "view the adjusted terms.\n\n"
		<< "Let's begin...\n\n";

	cout << "Creating new terms: \n";

	Term newTerm(2, 'a', 3);
	Term newTerm2(1, 'x', 1);
	Term newTerm3(-1, 'y', -3);
	Term newTerm4(-100, 'z', 0);
	Term newTerm2a(2, 'x', 1);

	cout << "First term: " << newTerm << endl;
	cout << "Second term: " << newTerm2 << endl;
	cout << "Third term: " << newTerm3 << endl;
	cout << "Fourth term: " << newTerm4 << endl;
	cout << "Fifth term: " << newTerm2a << endl;

	Polynomial polynomialOne;

	cout << "\nCreating PolynomialOne from the first and second terms:\n";

	polynomialOne.AddTerm(&newTerm);
	polynomialOne.AddTerm(&newTerm2);

	cout << polynomialOne << endl;

	Polynomial polynomialTwo;

	cout << "\nCreating PolynomialTwo from the third and fourth terms:\n";

	polynomialTwo.AddTerm(&newTerm3);
	polynomialTwo.AddTerm(&newTerm4);

	cout << polynomialTwo << endl;

	cout << "\nAdding PolynomialTwo to PolynomialOne:\n";

	Polynomial polynomialThree = polynomialOne + polynomialTwo;

	cout << polynomialThree << endl;

	cout << "\nAdding the fifth term to PolynomialThree to show how indeterminates\n"
		<< "and coeffiecients are preserved:\n";

	polynomialThree.AddTerm(&newTerm2a);

	cout << polynomialThree << endl;

	return 0;
}