# Name-Sorter
Takes input file with number of entries followed by sets of entries(last name, first name, birth date). Uses parallel arrays to let user display entries sorted or search them.

The program prompts the user for an input file name. The file should contain the number of entries on the first line, followed by entries
in sets of 3 (last anme, first name, date of birth). This information is stored in parallel arrays, one for first names, one for last names,
and one for birth dates.

The program displays a menu for the user and lets them choose an option from: display the entries in their original order, sorted by first name,
sorted by last name, enter string to search for entries that start with that string, or quit.

Return code 1: input file failed to open.
Return code 2: bad menu input or some other issue with the menu's switch

Written on Eclipse photon with g++ compiler
