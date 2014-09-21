// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Assignment 6B
//
// Write a program that reads a given text file, outputs the text file as is, and
// also prints the number of lines and the number of times each letter
// appears in the text file. (To simplify things, treat uppercase letters and
// lowercase letters as being the same.)

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// Maximum size of the charcter count array
const size_t charCountArraySize = 26;

// The size of the character buffer array
const size_t bufferSize = 80;

// Array containing the counts of charactes within the file.
int charCount[charCountArraySize];

// the count of lines found in the file
int lineCount = 0;

// The input file stream
ifstream infile;

// The output file stream
ofstream outfile;

// Initializes the variables used during the operation of the program
void initialize()
{
	charCount[charCountArraySize] = { 0 };

	lineCount = 0;

	infile.open("textinput.txt");

	if (!infile)
	{
		cerr << "Could not open textinput.txt" << endl;
		exit(EXIT_FAILURE);
	}

	outfile.open("textoutput.txt");

	if (!outfile)
	{
		cerr << "Could not open textoutput.txt" << endl;
		exit(EXIT_FAILURE);
	}
}

// Writes a pointer to a character array to the output file
void writeToOutput(char &c)
{
	outfile << c;
}

// Analyzes a character and determines whether to increment the line count and/or character count
void countChar(char &c)
{
	if (c == '\n')
	{
		lineCount++;
	}
	else
	{
		if (c >= 'a' && c <= 'z')
		{
			c -= 32;
		}

		if (c >= 'A' && c <= 'Z')
		{
			charCount[c - 65]++;
		}
	}
}

// Reads each line from the file and saves the line to the output file and then
// counts the lines and the instances of each letter.
void processFile()
{
	// for each line in the file
	while (infile.good())
	{
		char c = infile.get();

		// end of file. Time to exit
		if (c == EOF)
		{
			lineCount++;
			return;
		}

		// write to the output file
		writeToOutput(c);
		countChar(c);
	}
}

// Writes the results of the operation to the file.
void writeResults()
{
	cout << "Lines counted: " << lineCount << endl;
	cout << "Characters found: \n";

	for (int i = 0; i < charCountArraySize; i++)
	{
		cout << "\t" << (char)(i + 65) << ": " << charCount[i] << "\n";
	}
}

// main execution path
int main()
{
	cout << "Welcome to the line and letter counter.\n"
		<< "This program will open up the file textinput and count the total\n"
		<< "number of lines and the number of times that each letter appears.\n"
		<< "The output will be piped to a file named textoutput.\n"
		<< "Let's begin...\n\n";

	cout << "Initializing the program variables...\n";

	initialize();

	cout << "Processing the file...\n";

	processFile();

	cout << "Writing the output...\n";

	writeResults();

	return 0;
}