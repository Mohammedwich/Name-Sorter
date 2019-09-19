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
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


void sortAndPrint(int numberOfEntries, string * firstMention, string * secondMention, string * thirdMention)
{
	// An array to hold all related values in a single entry so they all get sorted together based on the desired first entry.
	// Also lets us preserve the original arrays
	string * fullEntryArray = new string[numberOfEntries];

	// Filling fullEntryArray
	for (int i = 0; i < numberOfEntries; ++i)
	{
		fullEntryArray[i] = firstMention[i] + " " + secondMention[i] + "    Born: " + thirdMention[i];
	}

	// Selection sort to sort the array
	for (int currentIndex = 0; currentIndex < numberOfEntries; ++currentIndex)
	{
		string minValue = fullEntryArray[currentIndex];
		int minValueIndex = currentIndex;

		for (int currentCompare = (currentIndex+1); currentCompare < numberOfEntries; ++currentCompare)
		{
			if (fullEntryArray[currentCompare] < minValue )
			{
				minValue = fullEntryArray[currentCompare];
				minValueIndex = currentCompare;
			}
		}

		string temp;
		temp = fullEntryArray[currentIndex];
		fullEntryArray[currentIndex] = fullEntryArray[minValueIndex];
		fullEntryArray[minValueIndex] = temp;
	}

	// Display entries in sorted order
	for (int i = 0; i < numberOfEntries; ++i)
	{
		cout << fullEntryArray[i] << endl;
	}

	// Memory cleanup
	delete [] fullEntryArray;
	fullEntryArray = 0;

}
