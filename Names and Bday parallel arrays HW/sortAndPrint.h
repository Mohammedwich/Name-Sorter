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

#ifndef SORTANDPRINT_H_
#define SORTANDPRINT_H_

#include "stdafx.h"
#include <string>

using std::string;

// Sorts depending on parameter order. firstMention is listed first, secondMention second, and thirdMention third.
void sortAndPrint(int numberOfEntries, string * firstMention, string * secondMention, string * thirdMention);


#endif /* SORTANDPRINT_H_ */