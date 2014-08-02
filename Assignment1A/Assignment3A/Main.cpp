// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 3A
// Write a program that includes the following four steps: 
//		Step 1. Create a structure with the name StudentRecord containing a
//			Name stored as an array of 20 characters, an ID stored as an
//			integer, and a GPA stored as a floating - point number. Create
//			(instantiate) a variable from StudentRecord called TESCStudent.
//		Step 2. Assign the following values to the variable by assuming Name
//			is SuperProgrammer, with an ID of 1234, and a GPA of 4.0.
//		Step 3. The program should print out on the screen that
//			SuperProgrammer with an Identification number of 1234 has a
//			4.0 GPA. (Of course, your program needs to use the structure
//			you defined in step 1.)
//		Step 4. Generalize the program so that you can input the student’s
//			name, ID, and GPA when the program is run. Please do not
//			forget to include prompt statements in your program. Print
//			out the user - entered Name, ID, and GPA.
//Make sure your program includes all four steps, not just steps 1 and 4.

#include <array>
#include <iomanip>
#include <iostream>
#include <string>

using namespace::std;

// The maximum name size allowed
const size_t maxNameSize = 20;

struct StudentRecord
{
	char Name[maxNameSize];
	int ID;
	float GPA;
};

// Introduces the program.
void Introduction();

// Takes a reference to a StudentRecord and prints out the kwown information in the 
// format: {Name} with an Identification number of {ID} has a {GPA} GPA.
void printStudentRecord(StudentRecord &);

// Prompts the user to enter information about a student and returns a reference to
// the created record.
StudentRecord getStudentInfo();

// Program execution method
int main()
{
	Introduction();

	cout << "Example student...\n";
	StudentRecord TESCStudent = { "SuperProgrammer", 1234, 4.0 };
	printStudentRecord(TESCStudent);

	StudentRecord newStudent = getStudentInfo();
	printStudentRecord(newStudent);

	return 0;
}

// Introduces the program
void Introduction()
{
	cout << "Welcome to the Student information display. You will be shown a set of example\n."
		"information for a student and then prompted to enter your own which will be\n"
		"displayed as well. Let's begin...\n\n" << endl;
}

// Takes a reference to a StudentRecord and prints out the kwown information in the 
// format: {Name} with an Identification number of {ID} has a {GPA} GPA.
void printStudentRecord(StudentRecord &student)
{
	cout << student.Name << " with an Identification number of " << student.ID <<
		" has a " << fixed << setprecision(2) << student.GPA << " GPA." << endl;
}

// Prompts the user to enter information about a student and returns a reference to
// the created record.
StudentRecord getStudentInfo()
{
	StudentRecord newStudent;

	string newName = "";
	int newID = 0;
	float newGPA = 0;

	cout << "\n\nEnter new student information.\n";

	// Get name
	cout << "Name (20 characters or less): ";
	cin.getline(newStudent.Name, maxNameSize);
	cin.clear();
	cin.sync();

	// Get ID
	do
	{
		cout << "ID (positive integer): ";
		cin >> newStudent.ID;
		cin.clear();
		cin.sync();

		if (newStudent.ID <= 0)
		{
			cout << "Invalid ID. Try again.\n";
		}
	} while (newStudent.ID <= 0);

	// Get GPA
	do
	{
		cout << "GPA (0.00 to 4.00): ";
		cin >> newStudent.GPA;
		cin.clear();
		cin.sync();

		if (newStudent.GPA < 0 || newStudent.GPA > 4.00)
		{
			cout << "Invalid GPA. Try again.\n";
		}
	} while (newStudent.GPA < 0 || newStudent.GPA > 4.00);

	return newStudent;
}