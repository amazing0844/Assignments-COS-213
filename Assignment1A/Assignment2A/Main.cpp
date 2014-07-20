// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 2A (Question 2)
//	Create a program that reads five numbers, finds their sum, and then 
//	prints the numbers in reverse order.Use arrays as a tool in your program.

#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

// The number of numbers to process in the main process
const size_t arraySize = 5;

// Method signature for function to get a set of numbers from console and insert
// them into an array whose first element is identified by the initial pointer.
void GetNumbers(int *, size_t);

// Processes a provided array and returns the sum of the contained integers
int SumArray(int *, size_t);

// Takes an array and outputs the numbers in the reverse of the order they were entered.
void DisplayInReverse(int *, size_t);

// Program execution
int main()
{
	int numbersToProcess[arraySize];
	char endChar;

	cout << "Welcome to a program that will take " << arraySize << " numbers "
		"and display their sum and then the numbers in the reverse order "
		"of how they entered. Let's begin..." << endl;

	GetNumbers(numbersToProcess, arraySize);

	cout << "The sum of the numbers you entered: " << SumArray(numbersToProcess, arraySize) << endl;

	cout << "The numbers in reverse order..." << endl;

	DisplayInReverse(numbersToProcess, arraySize);

	cout << "\nPress any key and enter to exit";

	cin >> endChar;
}

// Gets a set of numbers from console and inserts them into an array whose first
// element is identified by the initial pointer.
void GetNumbers(int *numbers, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Number " << i + 1 << ": ";
		cin >> numbers[i];
	}
}

// Cycles through a provided array and outputs the sum of the integers in the array
int SumArray(int *numbers, size_t size)
{
	int result = 0;

	for (int i = 0; i < size; i++)
	{
		result += numbers[i];
	}

	return result;
}

// Cycles through an array from last to first
void DisplayInReverse(int *numbers, size_t size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		cout << "Number " << i + 1 << ": " << numbers[i] << endl;
	}
}
