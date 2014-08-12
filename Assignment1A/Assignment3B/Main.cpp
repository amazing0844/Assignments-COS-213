// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 3B (Question 1)
//	Define a class called Plot that has private members of length and width.
//	Include a constructor and a public function that calculates the area and the
//	length of the boundary of the field. Use public functions in a program that
//	computes and displays the area and the length of the boundary of the
//	plot where the length and width are 7 and 9 respectively. Hint: The
//	length of the boundary is 2 * (length + width).

#include <iostream>
#include <iomanip>

using namespace std;

// Class defining methods and properties for a rectangular plot consisting of
// a length and width.
class Plot
{
public:
	// Default constructor. If no parameters are provided, it will default to having a
	// length and width of 1.
	Plot(int l = 1, int w = 1)
	{
		if (l <= 0 || w <= 1)
		{
			throw invalid_argument("Length and width must be > 0.");
		}

		length = l;
		width = w;
	}

	// Returns the area of the plot. this is equal to length * width
	int GetArea() const
	{
		return length * width;
	}

	// Returns the perimeter of the plot. This is equal to 2 * (length + width)
	int Perimeter() const
	{
		return 2 * (length + width);
	}
private:
	// The length of the plot
	int length;

	// The width of the plot
	int width;
};

// Program execution method 
int main()
{
	cout << "Welcome to the Plot class assignment. In this program, we will take a\n"
		"Plot defined as an object with a length and a width and determine their\n"
		"area and perimeter. For this test, we will use a plot with a length of 9\n"
		"and a width of 7." 
		"\n\nLets begin...\n\n";

	Plot test(7, 9);

	cout << "Area: " << test.GetArea() << endl;
	cout << "Perimeter: " << test.Perimeter() << endl;

	cout << "\n\nYour turn...\n\nEnter a length and width for a new plot...\n";

	int length;
	int width;

	cout << "Length: ";
	cin >> length;

	cout << "Width: ";
	cin >> width;

	Plot userTest(length, width);

	cout << "Area: " << userTest.GetArea() << endl;
	cout << "Perimeter: " << userTest.Perimeter() << endl;

	return 0;
}