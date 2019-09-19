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
#include "stringSearchArrays.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


void stringSearchArrays(string searchPhrase, int numberOfEntriesPerArray, string * lastNames, string * firstNames, string * birthDates)
{
	// Counters so we can print "None" if no entries were found
	int entriesInLastNames = 0;
	int entriesInFirstNames = 0;
	int entriesInBirthDates = 0;

	// Search each entry of each array for the user's search string
	// This section for array of last names
	cout << "Entries starting with \"" << searchPhrase << "\" found in list of last names: ";
	for (int i = 0; i < numberOfEntriesPerArray; ++i)
	{
		string currentEntry = lastNames[i];
		string thePhrase = searchPhrase;

		// Making the search case insensitive
		for (auto & x : currentEntry)
		{
			x = tolower(x);
		}

		for (auto & x : thePhrase)
		{
			x = tolower(x);
		}

		// Find substring 
		auto found = currentEntry.find(thePhrase);
		
		// Only print if substring is found at the start of the entry.
		if (found != string::npos && found == 0)
		{
			cout << lastNames[i] << ", ";
			++entriesInLastNames;
		}
	}
	if (entriesInLastNames == 0)
	{
		cout << "None";
	}
	cout << endl;

	//Same as previous loop but for first names
	cout << "Entries starting with \"" << searchPhrase << "\" found in list of first names: ";
	for (int i = 0; i < numberOfEntriesPerArray; ++i)
	{
		string currentEntry = firstNames[i];
		string thePhrase = searchPhrase;

		for (auto & x : currentEntry)
		{
			x = tolower(x);
		}

		for (auto & x : thePhrase)
		{
			x = tolower(x);
		}

		auto found = currentEntry.find(thePhrase);

		if (found != string::npos && found == 0)
		{
			cout << firstNames[i] << ", ";
			++entriesInFirstNames;
		}
	}
	if (entriesInFirstNames == 0)
	{
		cout << "None";
	}
	cout << endl;

	// Same as previous two but for birthdates
	cout << "Entries starting with \"" << searchPhrase << "\" found in list of birth dates: ";
	for (int i = 0; i < numberOfEntriesPerArray; ++i)
	{
		string currentEntry = birthDates[i];
		string thePhrase = searchPhrase;

		for (auto & x : currentEntry)
		{
			x = tolower(x);
		}

		for (auto & x : thePhrase)
		{
			x = tolower(x);
		}

		auto found = currentEntry.find(thePhrase);

		if (found != string::npos && found == 0)
		{
			cout << birthDates[i] << ", ";
			++entriesInBirthDates;
		}
	}
	if (entriesInBirthDates == 0)
	{
		cout << "None";
	}
	cout << endl;
}