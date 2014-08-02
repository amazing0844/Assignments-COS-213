// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 2B
//	Design and run a program that takes a numerical score and outputs a
//	letter grade.Specific numerical scoresand letter grades are listed below :
//	90–100 = Grade A
//	80–89 = Grade B
//	70–79 = Grade C
//	60–69 = Grade D
//	0–59 = Grade F

#include <array>
#include <iomanip>
#include <iostream>
#include <string>

using namespace::std;

// The number of possible different grade entries
const size_t arraySize = 101;

// An array containing the char values for all grades from 0 to 100
char grades[arraySize];

// Introduces the program.
void Introduction();

// Builds the grade array
void BuildGradeArray();

// Prompts a user for a grade and assigns it to the passed in integer reference.
// It will then display the entered number before returning.
void getScore(int &);

// Takes in an integer score and prints the corresponding letter grade. If the grade
// is not within the correct bounds an error is displayed.
void printGrade(int);

// Program execution method
int main()
{
	// Introduce program
	Introduction();

	// Build the grade array. We're preloading an array of grades to speed up the subsequent lookups.
	BuildGradeArray();

	// While the returned value <> -999, Prompt/Display a grade number
	int enteredGrade = -1;

	while (enteredGrade != -999)
	{
		getScore(enteredGrade);

		if (enteredGrade != -999)
		{
			// Display the grade as a string (e.g. Grade A)
			printGrade(enteredGrade);
		}
	}

	return 0;
}

// Introduces the program
void Introduction()
{
	cout << "Welcome to the Evaluator. You will be prompted to "
		"enter a grade in numeric form. The program will analyze that "
		"grade and return a letter value. The valid range of grades is "
		"0 to 100. Sorry, no extra credit allowed. When you're done, "
		"enter -999 for the grade. \n\nLet's begin..." << endl;
}

// Prompts a user for a grade and assigns it to the passed in integer reference
// It will then display the entered number before returning.
void getScore(int &score)
{
	cout << "\nPlease enter a grade from 0 to 100. (-999 to exit): ";
	cin >> score;

	if (score == -999) return;

	cout << "You entered: " << score << endl;
}

// Takes in an integer score and prints the corresponding letter grade. If the grade
// is not within the correct bounds an error is displayed.
void printGrade(int score)
{
	if (score >= 0 && score < arraySize)
	{
		cout << score << " gets a grade of " << grades[score] << endl;
		return;
	}

	cout << "An invalid score was entered. Try again." << endl;
}

// Builds the grade array. 
void BuildGradeArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		if (i < 60) {
			grades[i] = 'F';
		}
		else if (i < 70) {
			grades[i] = 'D';
		}
		else if (i < 80) {
			grades[i] = 'C';
		}
		else if (i < 90) {
			grades[i] = 'B';
		}
		else {
			grades[i] = 'A';
		}
	}
}

