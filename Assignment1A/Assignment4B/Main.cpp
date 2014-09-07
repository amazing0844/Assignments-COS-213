// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 4B (Question 2)
//	Create a person class to represent a person. (You may call the class
//		personType.) To simplify things, have the class have 2 variable members
//		for the person’s first and last name. Include 2 constructors. One should be
//		a default constructor and the other should be one with parameters. Include
//		respective functions for:
//	-  setting the name,
//	-  getting the name, and
//	-  printing the name on the screen.
//	Have your main program call these functions to demonstrate how they work.
//	Explain in a comment at the top of your program how you can replace
//	both constructors with one constructor by using a single constructor with
//	default parameters.

// In order to reduce the number of constructors to one, default arguments can be
// provided for the constructor with parameters. In this way, default values are
// assigned to the first and last name fields preventing the problem where a nul
// reference might occur if the fields are accessed before they're set. Ex.
//		class PersonTypeAlt
//		{
//		public:
//			PersonTypeAlt(string firstName = "John", string lastName = "Doe")
//			{
//				this->firstName = firstName;
//				this->lastName = lastName;
//			}
//		private:
//			string firstName;
//			string lastName;
//		};

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// The maximum name size allowed
const size_t maxNameSize = 20;

class PersonType
{
public:
	// Initializes a new instance of the PersonType with default values for
	// first and last names. We're using the classic default names for an unknown
	// person in the U.S.
	PersonType()
	{
		this->setFirstName("John");
		this->setLastName("Doe");
	}

	// Initializes a new instance of the PersonType with the provided values for
	// first and last names
	PersonType(string firstName, string lastName)
	{
		this->setFirstName(firstName);
		this->setLastName(lastName);
	}

	// Sets the first name of the PersonType instance to the provided string value
	void setFirstName(string value){
		this->firstName = value;
	}

	// Gets the first name of the PersonType instance
	string getFirstName(){
		return this->firstName;
	}

	// Sets the last name of the PersonType instance to the provided string value
	void setLastName(string value)
	{
		this->lastName = value;
	}

	// Gets the last name of the PersonType instance
	string getLastName(){
		return this->lastName;
	}

	void printFullName()
	{
		cout << "Name: " << this->getFirstName() << " " << this->getLastName() << endl;
	}

private:
	string firstName;
	string lastName;
};

// Program execution method
int main()
{
	cout << "Welcome to the PersonType demonstration.\n"
		"In this program, we'll demonstrate a class that has a first and\n"
		"name, and allows for printing out the full name of the instance.\n"
		"Let's begin...\n\n";

	cout << "Creating a default instance of Persontype." << endl;
	
	PersonType personOne;

	cout << "personOne was instantiated using the default values...\n";
	personOne.printFullName();

	cout << "Now let's try it with user input...\n\n";

	char firstName[maxNameSize];
	char lastName[maxNameSize];

	cout << "Enter information for a new PersonType.\n"
		"First Name (max 50 characters): ";

	cin.getline(firstName, maxNameSize);
	cin.clear();
	cin.sync();

	cout << "Last Name (max 50 characters): ";
	cin.getline(lastName, maxNameSize);
	cin.clear();
	cin.sync();

	PersonType personTwo(firstName, lastName);

	cout << "personTwo was instantiated using the values provided...\n";
	personTwo.printFullName();

	cout << "\n\nAll done. Thanks for playing." << endl;

	return 0;
}