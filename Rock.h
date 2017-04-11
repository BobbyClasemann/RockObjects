/*-----Rock.h------------------------------------------------------
A header file for an enumerated data type Rock that models 
rocks of various types (basalt, dolomite, granite, gypsum,
limestone, marble, obsidian, quartzite, sandstone, and shale)

Operations are:
Rock():											A default constructor
Rock(Rockname r):								An explicit-value constructor
display(Rockname r):							A console output method
&operator<<(ostream &out, const Rock &r):		An overload function
read(istream &in):								A console input method
&operator>>(istream &in, Rock &r):				An overload function
kind():											A console output method
texture():										A console output method
name():											A console output method
&operator<<(ostream &out, const RockName &r):	An overload function
operator<(const Rock &r1, const Rock &r2):		An overload function
operator==(const Rock &r1, const Rock &r2):		An overload function
checkFile(ifstream &inputFile):					A validation function	
sampleCount(ifstream &inputFile,
			int count[], Rock r):				An increment function
operator++():									A successor function
displayHistogram(int count[]):					A display function


Written by: Bobby Clasemann			Anoka Ramsey Community College
Written for: CS 1107				Feb. 14, 2017
------------------------------------------------------------------*/

#ifndef ROCK_H
#define ROCK_H
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum RockName {BASALT, DOLOMITE, GRANITE, GYPSUM, LIMESTONE, MARBLE,
			  OBSIDIAN, QUARTZITE, SANDSTONE, SHALE, ROCK_OVERFLOW};

class Rock {
	public:
		/****** Class constructors *******/

		Rock();
		/***************************************************
		Construct a class object (default).

		Precondition: None
		Postcondition: Initializes the myName data member
			to some rock value, e.g., BASALT.
		****************************************************/

		Rock(RockName r);
		/***************************************************
		Construct a class object (explicit values).

		Precondition: The value myName declared.
		Postcondition: myName is initialized to the specified
			Rock name.
		****************************************************/

		/****** Methods ********/

		void display(ostream &out) const;
		/***************************************************
		Display the rock name to the user.

		Precondition: The ostream out is open.
		Postcondition: The rock objects has been inserted
			into ostream out and reference to out is returned.
		****************************************************/

		void read(istream &in);
		/***************************************************
		Read a rock value from input stream in.

		Precondition: The istream in is open.
		Postcondition: Input values have been removed from 
			in and stored in the data members.
		****************************************************/

		string kind();
		/***************************************************
		Determines and outputs the kind of rock the
		Rock value is.

		Precondition: myName is a valid Rock value.
		Postcondition: The kind of rock myName is.
			(igneous, metamorphic, or sedimentary).
		****************************************************/

		string texture();
		/***************************************************
		Determines and outputs the texture of the Rock
		value.

		Precondition: myName is a valid Rock value.
		Postcondition: Displays the texture of the rock:
			(coarse, intermediate, or fine).
		****************************************************/

		RockName name() const;
		/***************************************************
		Outputs the numeric value of the Rock value.

		Precondition: myName is a valid Rock value.
		Postcondition: Displays the numeric value of the 
			Rock value from the enum.
		****************************************************/

		Rock operator++();
		/****************************************************
		Overloads the prefix operator.

		Precondition: None.
		Postcondition: Rock variable can use the prefix 
			operator.
		****************************************************/

	private:
		RockName myName;
		


};//end of class declaration

/*********** Overloading operators ***************/

ostream &operator<<(ostream &out, const Rock &r);
/***************************************************
Returns the ostream object out.

Precondition: The ostream out is open
Postcondition: The reference to out is returned.
****************************************************/

istream &operator>>(istream &in, Rock &r);
/***************************************************
Returns the istream object in.

Precondition: The istream in is open.
Postcondition: Value has been extracted
	from in via read() and stored in the Rock
	data member; The reference to in is returned.
****************************************************/

ostream &operator<<(ostream &out, const RockName &r);
/***************************************************
Overloaded output operator. Sets the ostream object
out for RockName values.

Precondition: The ostream out is open.
Postcondition: The RockName objects has been inserted
	into ostream out.
****************************************************/


/********** Relational operators *******/
bool operator<(const Rock &r1, const Rock &r2);
/***************************************************
Overloaded operator compares two Rock values to 
test which is greater.

Precondition: None.
Postcondition: Returns a boolean value after
the compare is finished.
****************************************************/

bool operator==(const Rock &r1, const Rock &r2);
/***************************************************
Overloaded operator compares two Rock values to 
test if they're equal.

Precondition: None
Postcondition: Returns a boolean value after
the compare is finished.
****************************************************/

/********** Functions ***********/
void sampleCount(ifstream &inputFile, int count[]);
/****************************************************
Keeps count for each time a rock type is displayed
in the file.

Precondition: A text file
Postcondition: Array contains the number of times each
	rock type is displayed in the file.
****************************************************/

void checkFile(ifstream &inputFile);
/*****************************************************
Checks if the file opened correctly.

Precondition: Rockfile.txt
Postcondition: Displays an error message to the console
	if file couldn't be opened.
*****************************************************/

void displayHistogram(int count[]);
/****************************************************
Displays an 'X' for each time a rock type is read.

Precondition: None
Postcondition: A histogram is displayed to the user.
****************************************************/

#endif