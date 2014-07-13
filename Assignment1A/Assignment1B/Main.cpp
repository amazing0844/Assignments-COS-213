// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 1B (Question 1)
//	Write a program using a function and a switch statement. The user 
//	should be prompted to enter a number in main.The function is called
//	and the number entered is passed tothe function.This function
//	parameter will then be used in a switchto discover and print out the
//	number word within the function(for example, 1 = one, 2 = two, 3 = three,
//	etc.)

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Class defining methods to convert an integer type into its string representation
// in the American English format (ex. 1,234,567 => one million two hundred thirty-four
// thousand five hundred sixty-seven)
class NumberStringMaker
{
public:
	void MakeIntoString(unsigned int numberToConvert)
	{
		string result = "";

		string onesPart = "";
		string tensPart = "";
		string hundredsPart = "";

		// Get the numeric value of the number under 1000
		unsigned int hundreds = numberToConvert % 1000;

		// Get the thousands part of the number
		unsigned int thousands = ((numberToConvert - hundreds) / 1000) % 1000;

		// get the millions part of the number
		unsigned int millions = numberToConvert / 1000000;

		// output text of millions
		if (millions > 0)
		{
			cout << BuildText(millions) << " million";
		}

		// output text of thousands
		if (thousands > 0)
		{
			cout << (millions > 0 ? " " : "") << BuildText(thousands) << " thousand";
		}

		// output text of hundreds
		if (hundreds > 0)
		{
			cout << ((millions + thousands) > 0 ? " " : "") << BuildText(hundreds);
		}
	};

private:
	// takes a number less than 1000 and convert it to its text and return the value
	string BuildText(unsigned int numberToConvert)
	{
		string onesPart = "";
		string tensPart = "";
		string hundredsPart = "";

		// Get the numeric value of the number under 1000
		unsigned int hundreds = numberToConvert % 1000;

		unsigned int onesCount = hundreds % 10;
		unsigned int tensCount = ((hundreds - onesCount) / 10) % 10;
		unsigned int hundredsCount = (hundreds - (onesCount + tensCount)) / 100;

		// if the tens count == 1 (10 -> 19), handle the ones and tens specially
		if (tensCount == 1)
		{
			onesPart = GetTeensName(onesCount);
		}
		else
		{
			onesPart = GetOnesName(onesCount);
			tensPart = GetTensName(tensCount) + (onesCount > 0 && tensCount > 0 ? "-" : "");
		}

		if (hundredsCount > 0)
		{
			hundredsPart = GetOnesName(hundredsCount) + " hundred";
		}

		string result = hundredsPart
			+ (tensCount >= 2 && hundreds > 0 ? " " : "") + tensPart
			+ (onesPart != "" && tensPart == "" && hundredsCount > 0 ? " " : "") + onesPart;

		return result;
	};

	// returns the string representation of a number from one to ten
	string GetOnesName(unsigned int numberToConvert) const
	{
		switch (numberToConvert)
		{
		case 0:
			return "";
			break;

		case 1:
			return "one";
			break;

		case 2:
			return "two";
			break;

		case 3:
			return "three";
			break;

		case 4:
			return "four";
			break;

		case 5:
			return "five";
			break;

		case 6:
			return "six";
			break;

		case 7:
			return "seven";
			break;

		case 8:
			return "eight";
			break;

		case 9:
			return "nine";
			break;

		default: // this is a bad thing. If we were doing this for real, we'd throw an exception
			return "unknown";
		}
	};

	// Convert a teen (10 -> 19) number to its string
	string GetTeensName(unsigned int numberToConvert) const
	{
		switch (numberToConvert)
		{
		case 0:
			return "ten";

		case 1:
			return "eleven";

		case 2:
			return "twelve";

		case 3:
			return "thirteen";

		case 4:
			return "fourteen";

		case 5:
			return "fifteen";

		case 6:
			return "sixteen";

		case 7:
			return "seventeen";

		case 8:
			return "eighteen";

		case 9:
			return "nineteen";

		default: // this is a bad thing. If we were doing this for real, we'd throw an exception
			return "unknown";
		};
	};

	// Returns the "tens" name by ordinal. 1 is ignored because it should be handled specially for "teen" values.
	string GetTensName(unsigned int numberToConvert) const
	{
		switch (numberToConvert)
		{
		case 0:
			return "";

		case 2:
			return "twenty";

		case 3:
			return "thirty";

		case 4:
			return "forty";

		case 5:
			return "fifty";

		case 6:
			return "sixty";

		case 7:
			return "seventy";

		case 8:
			return "eighty";

		case 9:
			return "ninety";

		default: // this is a bad thing. If we were doing this for real, we'd throw an exception
			return "unknown";
		};
	};
};

// Program execution 
int main()
{
	NumberStringMaker maker;

	unsigned int numberToConvert = 0;
	char endChar;

	cout << "Enter a number (1 to 999,999,999): ";

	cin >> numberToConvert;

	cout << "You entered the number ";
	
	maker.MakeIntoString(numberToConvert);

	cout << "\n\nPress any key and 'enter' to exit...";

	cin >> endChar;
	
	return 0;
}