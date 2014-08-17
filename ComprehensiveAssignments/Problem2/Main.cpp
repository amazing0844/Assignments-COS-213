// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Comprehensive Assignment(Question 2)
//	Create a program that takes the scores as input and provides as output the management decision. In the 
//	program, include 2 void functions titled getScore and printDecision, each with an int argument.
//
//	- The function getScore should have a Reference parameter that gets the score in getScore and then
//	passes the value back to be printed in main(), and
//	- printDecision should have a Value parameter.
//
//	The function getScore will prompt the user for the integer score from 1 to 5, get the input from the user, and
//	display the input received on the screen.The function printDecision will determine the mortgage decision
//	and print the decision. (Be careful and note that this problem requires you to input the score into getScore
//	and not directly into the main function.)

#include <iostream>

using namespace std;

// Prompts the user for a score and assigns it to the provided reference
void getScore(int &);

// Prints the loan decision based on the provided score
void printDecision(int);

// Program execution 
int main()
{
	cout << "Welcome to the MinFinder.\n"
		"This program will take a loan application score provided by you "
		"and print a decision on whether to offer a loan and at what rate. "
		"The range of scores is 1 to 5. Enter -99 to exit.\n"
		"Let's begin...\n\n";

	int score = 0;

	while (score != -99)
	{
		getScore(score);

		if (score != -99)
		{
			printDecision(score);
		}
	}
		
	return 0;
}

// Prompts the user for a score and assigns it to the provided reference
void getScore(int &score)
{
	cout << "Score (1 to 5, -99 to exit): ";
	cin >> score;
	cin.clear();
	cin.sync();
}

// Prints the loan decision based on the provided score
void printDecision(int score)
{
	switch(score)
	{
	case 5:
		cout << "Provide mortgage at 5% interest rate." << endl;
		break;

	case 4:
		cout << "Provide mortgage at 6% interest rate." << endl;
		break;

	case 3:
		cout << "Provide mortgage at 7% interest rate." << endl;
		break;

	case 2:
	case 1:
		cout << "Do not provide mortgage." << endl;
		break;

	default:
		cout << "Invalid score. Try again." << endl;

	}
}
