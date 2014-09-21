// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Final Project Problem 5
//
// Derive the cylinder class from the base circle class. Assume the circle class has a protected
// member variable representing the radius called radius and declared as a double with a default
// value of 1.0. It also has a public function called calcVal that evaluates the area of a circle as PI *
// radius * radius where PI is a constant 3.14.
//
// In your derived class include an additional protected member representing the length of the
// cylinder. Call this variable length. Have the default values for the cylinder class be 1 for both the
// radius and the length. For this derived cylinder class include a public function calcVal that
// evaluates the volume of the cylinder. (Hint : The volume of the cylinder is length * circle::calcVal())

#include <iomanip>
#include <iostream>

using namespace std;

// Constants namespace including math and other type constant
namespace Constants
{
	// Constant value of PI
	const double PI = 3.14;
}

class Circle
{
public:
	// Default constructor for the Circle class.
	Circle()
	{
		this->setRadius(1);
	}

	// Constructor for a Circle taking a value for its radius
	Circle(double radius)
	{
		this->setRadius(radius);
	}

	// Sets the radius of the circle
	void setRadius(double radius)
	{
		if (radius <= 0)
		{
			throw invalid_argument("Radius must be greater than 0");
		}

		this->radius = radius;
	}

	// Returns the radius of the circle
	double getRadius() const
	{
		return this->radius;
	}

	// Returns the radius of the circle
	virtual double calcVal() const
	{
		return this->getRadius() * this->getRadius() * Constants::PI;
	}

protected:
	// The radius of the circle. This defaults to 1
	double radius = 1;
};

// Class defining a Cylinder. This includes the circle of the top and bottom face as well as a length
class Cylinder : Circle
{
public:
	// Default constructor for the Cylinder
	Cylinder()
	{
		this->setRadius(1);
		this->setLength(1);
	}

	// Constructor for a Cylinder taking the radius and length
	Cylinder(double radius, double length)
	{
		this->setRadius(radius);
		this->setLength(length);
	}

	// Sets the length of the Cylinder
	void setLength(double length)
	{
		if (length <= 0)
		{
			throw invalid_argument("Length must be greater than 0");
		}

		this->length = length;
	}

	// Gets the length of the Cylinder
	double getLength() const
	{
		return this->length;
	}

	// Returns the volume of the Cylinder
	virtual double calcVal() const override
	{
		return this->getLength() * Circle::calcVal();
	}

protected:
	// The length of the cylinder. This defaults to 1
	double length = 1;
};

// main execution method
int main()
{
	double radius;
	double length;

	cout << "Final Project Problem 5\n"
		<< "Displaying different behaviors for derived classes.\n"
		<< "Let's begin.\n\n";

	cout << "Creating a circle.";
	cout << "Radius: ";
	cin >> radius;

	Circle circle(radius);

	cout << "Area: " << circle.calcVal() << "\n" << endl;

	cout << "Creating a cylinder with the circle's radius of " << radius << endl;
	cout << "Length: ";
	cin >> length;

	Cylinder cylinder(radius, length);

	cout << "Volume: " << cylinder.calcVal() << endl;

	return 0;
}
