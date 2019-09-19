//============================================================================
// Name			: File name??????????
// Author		: Mohammed Ahmed
// Course		: UTDallas CS 1337.502 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
//		The program prompts the user for an input file name. The file should contain the number of entries on the first line, followed by entries
//		in sets of 3 (last anme, first name, date of birth). This information is stored in parallel arrays, one for first names, one for last names,
//		and one for birth dates.
//
//		The program displays a menu for the user and lets them choose an option from: display the entries in their original order, sorted by first name,
//		sorted by last name, enter string to search for entries that start with that string, or quit.
//
//		Return code 1: input file failed to open.
//		Return code 2: bad menu input or some other issue with the menu's switch
//============================================================================


#include "stdafx.h"
#include "sortAndPrint.h"
#include "stringSearchArrays.h"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;


int main()
{
	string inputFileName;

	std::ifstream fileReader;

	cout << "Enter input file name: ";
	getline(cin, inputFileName);
	cout << endl;

	fileReader.open(inputFileName);

	// Make sure file opened without issue. If not return error code 1 and end program.
	if (!(fileReader.is_open()))
	{
		cout << "The file " << inputFileName << " failed to open. Exiting program..." << endl;
		return 1;
	}

	int numberOfEntries;
	fileReader >> numberOfEntries;

	string * firstNamesArray = new string[numberOfEntries];
	string * lastNamesArray = new string[numberOfEntries];
	string * birthDatesArray = new string[numberOfEntries];

	// Putting file values in their respective arrays in parallel
	for (int i = 0; i < numberOfEntries; ++i)
	{
		fileReader >> lastNamesArray[i];
		fileReader >> firstNamesArray[i];
		fileReader >> birthDatesArray[i];
	}

	int userSelect;
	string searchString;

	do
	{
		// Clear the console screen. Differenet statement based on operating system
		#if defined(_WIN32)
		system("cls");
		#elif defined(__linux__)
		system("clear");
		#elif defined(__APPLE__)
		system("clear");
		#endif

		// Display menu
		cout << "1: Print list of entries in original order." << endl;
		cout << "2: Print list of entries sorted by first name." << endl;
		cout << "3: Print list of entries sorted by last name." << endl;
		cout << "4: Search for entry." << endl;
		cout << "0: Quit." << endl << endl;


		cout << "Enter the number of the option you want: ";

		// All the clear() and ignore() calls are to prevent issues with excess deposited values in the input buffer affecting the next input prompt
		cin >> userSelect;
		while (userSelect != 0 && userSelect != 1 && userSelect != 2 && userSelect != 3 && userSelect != 4)
		{
			cin.clear();
			cin.ignore();

			cout << "Enter a proper value(1, 2, 3, 4, or 0) : ";
			cin >> userSelect;
		}
		
		switch (userSelect)
		{
		case 1: 
			// Display entries in default order
			for (int i = 0; i < numberOfEntries; ++i)
			{
				cout << (i + 1) << ". " << lastNamesArray[i] << ", " << firstNamesArray[i] << "\t Born: " << birthDatesArray[i] << endl;
			}
			cout << endl << "Enter any character to return to menu" << endl;
			cin.clear();
			cin.ignore();
			cin.get();
			break;

		case 2:
			// Display entries sorted by first name
			sortAndPrint(numberOfEntries, firstNamesArray, lastNamesArray, birthDatesArray);
			cout << endl << "Enter any character to return to menu" << endl;
			cin.clear();
			cin.ignore();
			cin.get();
			break;

		case 3:
			// Display entries sorted by last name
			sortAndPrint(numberOfEntries, lastNamesArray, firstNamesArray, birthDatesArray);
			cout << endl << "Enter any character to return to menu" << endl;
			cin.clear();
			cin.ignore();
			cin.get();
			break;

		case 4:
			// Takes string from user and searches for any entries that begin with that string. Case insensitive.
			cout << "Enter string to search for entries beginning with it: ";
			cin.clear();
			cin.ignore();
			getline(cin, searchString);
			stringSearchArrays(searchString, numberOfEntries, lastNamesArray, firstNamesArray, birthDatesArray);
			cout << endl << "Enter any character to return to menu" << endl;
			cin.clear();
			cin.ignore();
			cin.get();
			break;

		case 0:
			cout << "Quitting..." << endl;
			userSelect = 0;
			break;

		default:
			cout << "Something went wrong in the menu's switch or the input it checks" << endl;
			return 2;
		}

	} while (userSelect != 0);


	// Freeing allocated memory and nulling pointers
	fileReader.close();
	delete[] firstNamesArray;
	delete[] lastNamesArray;
	delete[] birthDatesArray;
	firstNamesArray = 0;
	lastNamesArray = 0;
	birthDatesArray = 0;

	// A pause so user can see any output before program closes
	cout << endl << "Enter any character to exit" << endl;
	cin.clear();
	cin.ignore();
	cin.get();


    return 0;
}

