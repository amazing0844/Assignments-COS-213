// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Comprehensive Assignment (Question 3)
//	Define a class called Date that has 3 private members that represent the month, day, and year respectively.  
//	They will be represented as integers.Include a constructor and a public void function called print that prints
//	out the date. (For example, if the month is 2, the day is 25, and the year is 1946, print provides as output
//	2/25/1946.) Include the class in a program that prints out the date 2/25/1946

#include <exception>
#include <iostream>
#include <iomanip>

using namespace std;

// Class defining a date object as year, month, and day and providing methods to alter the date and print it out
// in U.S. format (i.e. 12/23/1900)
class Date
{
public:
	// Instantiates a new instance of Date. If no values are provided for the arguments, defaults are added
	explicit Date(int year = 1900, int month = 1, int day = 1)
	{
		this->setDate(year, month, day);
	}

	// Sets the year for the Date. The allowed values are 1900 to 2100
	void setYear(int year)
	{
		if (year < 1900 && year > 2100)
		{
			throw invalid_argument("year must be from 1900 to 2100");
		}

		this->year = year;
	}

	// Returns the year value for the current date
	int getYear()
	{
		return this->year;
	}

	// Sets the month for the Date. The allowed values are 1 to 12
	void setMonth(int month)
	{
		if (month < 1 && month > 12)
		{
			throw invalid_argument("month must be from 1 to 12");
		}

		this->month = month;

	}

	// Returns the month value for the current date
	int getMonth()
	{
		return this->month;
	}

	// Sets the month for the Date. The allowed values depend on the month and year. For January, March, May,
	// July, August, October, and December 1 to 31. For April, June, September, and November, 1 to 30. For February,
	// if the year is not a leap yearz
	void setDay(int day)
	{
		int maxDay = 0;
		switch (this->month)
		{
		case 1: // January
		case 3: // March
		case 5: // May
		case 7: // July
		case 8: // August
		case 10: // October
		case 12: // December
			maxDay = 31;
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			maxDay = 30;
			break;

		case 2:
			maxDay = this->isLeapYear() ? 29 : 28;
			break;

		default:
			throw out_of_range("Month is out of range");
		}

		if (day < 1 && day > maxDay)
		{
			throw invalid_argument("day must be from 1 to 28, 29, 30, or 31 depending upon the month and year");
		}

		this->day = day;

	}

	// Returns the day value for the current date
	int getDay()
	{
		return this->day;
	}

	// Sets the year, month, and day for the current Date instance
	void setDate(int year, int month, int day)
	{
		this->setYear(year);
		this->setMonth(month);
		this->setDay(day);
	}

	// Prints the date in U.S. format (i.e. 12/23/1900)
	void print()
	{
		cout << this->getMonth() << "/" << this->getDay() << "/" << this->getYear() << endl;
	}

	// Checks whether or not the year of the Date is a leap year. Leap years are any year that is evenly divisible
	// by 4 but not 100 OR evenly divisible by 400. For example, 1928 and 2000 are leap years, but 2100 is not.
	bool isLeapYear() const
	{
		if ((this->year % 4 == 0 && this->year % 100 != 0) 
			|| this->year % 400 == 0)
		{
			return true;
		}

		return false;
	}

private:
	// The year of the date
	int year;
	// The month of the date
	int month;
	// The day of the date
	int day;
};

// Program execution 
int main()
{
	Date testDate;

	cout << "Welcome to the Date manager. \n"
		"This program will create a default Date item and display it's value.\n"
		"Then it will set the Date to have a Month = 2, Day = 25, and Year = 1946\n"
		"and display that date.\n"
		"Let's begin..." << endl;

	cout << "The default date is: ";
	testDate.print();

	cout << "\nChanging the date...\n\n";

	testDate.setDate(1946, 2, 25);

	cout << "The new date is: ";
	testDate.print();

	return 0;
}