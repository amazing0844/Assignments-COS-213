// Name:					Scott Corbett
// College ID:				0561772
// Telephone:				848-391-6953
// Email:					secorbett13@gmail.com
// College and Semester:	TESC, July 2014
// Course Code:				COS-213-GS007
// Course Name:				C++ Programming
//
// Final Project Problem 3
//
// Write a program that reads from the external file input.txt, capitalizes all words that begin with the
// letter "a," and then writes them to an external file output.txt(Note: Do not forget to copy the
// blanks. You may wish to use infile.get and outfile.put in your program.)

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;


// Method signature for the processFile method
void processFile(ifstream* infile, ofstream* outfile);

// Takes a character and capitalizes it if it's a letter
char capitalizeChar(char c);

// Determines whether or not a character is a letter or not
bool isLetter(char* c);

// Determines whether or not the value underlying a character pointer is a lower case letter
bool isLowerCase(char* c);

// Determines whether a character is considered whitespace '\n', '\t', '\b', '\b', '\r', '\f'
bool isWhiteSpace(char* c);

// main execution method
int main()
{
	// Input file stream
	ifstream infile;

	// Output file stream
	ofstream outfile;

	cout << "Final Project Problem 3.\n\n"
		<< "Reading from a file, input.txt, and capitalizing all words that begin with\n"
		<< "an 'a' before outputting them to a file output.txt.\n\n"
		<< "Let's begin..." << endl;

	infile.open("input.txt");

	if (!infile)
	{
		cerr << "Could not open input.txt" << endl;
		exit(EXIT_FAILURE);
	}

	outfile.open("output.txt", ofstream::out);

	if (!infile)
	{
		cerr << "Could not open output.txt" << endl;
		exit(EXIT_FAILURE);
	}

	processFile(&infile, &outfile);

	return 0;
}

// Determines whether or not a character is a letter or not
bool isLetter(char* c)
{
	char checkChar = *c;

	if ((checkChar >= 'a' && checkChar <= 'z') ||
		(checkChar >= 'A' && checkChar <= 'Z'))
	{
		return true;
	}

	return false;
}

// Determines whether or not the value underlying a character pointer is a lower case letter
bool isLowerCase(char* c)
{
	char checkChar = *c;

	if (checkChar >= 'a' && checkChar <= 'z')
	{
		return true;
	}

	return false;
}

// Determines whether a character is considered whitespace ' ', '\n', '\t', '\b', '\b', '\r', '\f'
bool isWhiteSpace(char* c)
{
	char checkChar = *c;

	if (checkChar == ' ' || 
		checkChar == '\n' || 
		checkChar == '\t' ||
		checkChar == '\b' ||
		checkChar == '\r' ||
		checkChar == '\f')
	{
		return true;
	}

	return false;
}

// Takes a character and capitalizes it if it's a letter
char capitalizeChar(char c)
{
	if (isLowerCase(&c))
	{
		return c - 32;
	}
	
	return c;
}

// Processes an input file, capitalizing all of the words that begin an 'a' or 'A' and outputting
// the result to the output file.
void processFile(ifstream* infile, ofstream* outfile)
{
	// Whether or not to capitalize the letters
	bool doCapitalize = false;

	// Whether or not the process is in a word
	bool inWord = false;

	// Flag indicating whether the first letter in a "word" has been found. Handles cases where
	// a word begins with a non-letter, non-whitespace character
	bool foundFirstLetter = false;

	// The last character reviewed
	char lastChar = EOF;

	while (infile->good())
	{
		char c = infile->get();

		// at the end of the file time to exit
		if (c == EOF)
		{
			return;
		}

		if (isWhiteSpace(&c))
		{
			inWord = false;
			foundFirstLetter = false;
			doCapitalize = false;
		}

		// determine if we're in a word
		if (!inWord && !isWhiteSpace(&c))
		{
			inWord = true;
		}

		if (isLetter(&c) && inWord && !foundFirstLetter)
		{
			foundFirstLetter = true;

			if (c == 'a' || c == 'A')
			{
				doCapitalize = true;
			}
		}

		if (doCapitalize)
		{
			c = capitalizeChar(c);
		}

		*outfile << c;
	}
}