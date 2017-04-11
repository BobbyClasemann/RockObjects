/*-----Rock.cpp------------------------------------------------------
An implementation file for an enumerated data type Rock that models 
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

#include "Rock.h"

/***************************************************
Construct a class object (default).

Precondition: None
Postcondition: Initializes the myName data member
	to some rock value, e.g., BASALT.
****************************************************/
Rock::Rock() : myName(BASALT){

}

/***************************************************
Construct a class object (explicit values).

Precondition: The value myName declared.
Postcondition: myName is initialized to the specified
	Rock name.
****************************************************/
Rock::Rock(RockName r){

	myName = r;
	//cout << "Rock Constructor\n";
}

/***************************************************
Overloaded output operator. Sets the ostream object
out.

Precondition: The ostream out is open.
Postcondition: The rock objects has been inserted
	into ostream out.
****************************************************/


void Rock::display(ostream &out) const {

switch(myName){

	case BASALT: out << "BASALT";
		break;
	case GRANITE: out << "GRANITE";
		break;
	case OBSIDIAN: out << "OBSIDIAN";
		break;
	case MARBLE: out << "MARBLE";
		break;
	case QUARTZITE: out << "QUARTZITE";
		break;
	case DOLOMITE: out << "DOLOMITE";
		break;
	case LIMESTONE: out << "LIMESTONE";
		break;
	case GYPSUM: out << "GYPSUM";
		break;
	case SANDSTONE: out << "SANDSTONE";
		break;
	case SHALE: out << "SHALE";
		break;
	case ROCK_OVERFLOW: out << "ROCK_OVERFLOW"; 

	}//end switch

} //end display

/***************************************************
Returns the ostream object out.

Precondition: The ostream out is open
Postcondition: The reference to out is returned.
****************************************************/
ostream &operator<<(ostream &out, const Rock &r){

	r.display(out);
	return out;

 }//end ostream

/***************************************************
Read a rock value from input stream in.

Precondition: The istream in is open.
Postcondition: Input values have been removed from 
	in and stored in the data members.
****************************************************/
void Rock::read(istream &in){

	string allowedRocks[] = {"BASALT", "DOLOMITE", "GRANITE", 
							"GYPSUM", "LIMESTONE", "MARBLE",
							"OBSIDIAN", "QUARTZITE", "SANDSTONE",
							"SHALE", "ROCK_OVERFLOW"};
	unsigned location = 0;
	bool found = false;
	string rockName;

	in >> rockName;

	//converts string entered into all uppercase
	for(unsigned i = 0; i < rockName.length(); i++){
		if(islower(rockName[i]))
			rockName[i] = toupper(rockName[i]);
	}//end for

	//finds if the string entered is valid
	for(; !found && location < 11; location++)
		found = rockName == allowedRocks[location];
	location--;

	

	if(found)
		myName = static_cast<RockName>(location);

	else{
		cout << "Invalid data entered ---- Terminating. " << endl;
		exit(1107);
	}//end else

}//end read

/***************************************************
Returns the istream object in.

Precondition: The istream in is open.
Postcondition: Value has been extracted
	from in via read() and stored in the Rock
	data member; The reference to in is returned.
****************************************************/
istream &operator>>(istream &in, Rock &r){

	r.read(in);
	return in;

}//end istream

/***************************************************
Determining and outputting the kind of rock the
Rock value is.

Precondition: myName is a valid Rock value.
Postcondition: The kind of rock myName is.
	(igneous, metamorphic, or sedimentary).
****************************************************/

string Rock::kind(){

	string rockType;

	switch(myName){

		case BASALT:
		case GRANITE:
		case OBSIDIAN: rockType = "igneous.";
			break;

		case MARBLE:
		case QUARTZITE: rockType = "metamorphic.";			
			break;

		case DOLOMITE:
		case LIMESTONE:
		case GYPSUM:
		case SANDSTONE:
		case SHALE:	 rockType = "sedimentary.";		
			
	}//end switch

	return rockType;

}//end kind

/***************************************************
Determines and outputs the texture of the Rock
value.

Precondition: myName is a valid Rock value.
Postcondition: Displays the texture of the rock:
	(coarse, intermediate, or fine).
****************************************************/

string Rock::texture(){

	string rockTexture;

	switch(myName){

		case DOLOMITE:
		case GRANITE:
		case GYPSUM:
		case LIMESTONE:
		case SANDSTONE:	rockTexture = "coarse.";
			break;

		case BASALT:
		case QUARTZITE: rockTexture = "intermediate.";
			break;

		case OBSIDIAN:
		case MARBLE:
		case SHALE: rockTexture = "fine.";
		
	}//end switch

	return rockTexture;

}//end texture

/***************************************************
Outputs the rock name of the RockName value.

Precondition: myName is a valid RockName value.
Postcondition: Displays the name of the 
	RockName value.
****************************************************/

RockName Rock::name() const{

	return myName;

}

/***************************************************
Overloaded output operator. Sets the ostream object
out for RockName values.

Precondition: The ostream out is open.
Postcondition: The RockName objects has been inserted
	into ostream out.
****************************************************/

ostream &operator<<(ostream &out, const RockName &r){

	switch(r){

	case BASALT: out << "BASALT";
		break;
	case GRANITE: out << "GRANITE";
		break;
	case OBSIDIAN: out << "OBSIDIAN";
		break;
	case MARBLE: out << "MARBLE";
		break;
	case QUARTZITE: out << "QUARTZITE";
		break;
	case DOLOMITE: out << "DOLOMITE";
		break;
	case LIMESTONE: out << "LIMESTONE";
		break;
	case GYPSUM: out << "GYPSUM";
		break;
	case SANDSTONE: out << "SANDSTONE";
		break;
	case SHALE: out << "SHALE";
		break;
	case ROCK_OVERFLOW: out << "ROCK_OVERFLOW"; 

	}//end switch

	return out;

}//end ostream 

/***************************************************
Overloaded operator compares two Rock values to 
test which is greater.

Precondition: None
Postcondition: Returns a boolean value after
the compare is finished.
****************************************************/

bool operator<(const Rock &r1, const Rock &r2){

	return r1.name() < r2.name();

}//end operator<

/***************************************************
Overloaded operator compares two Rock values to 
test if they're equal.

Precondition: None
Postcondition: Returns a boolean value after
the compare is finished.
****************************************************/

bool operator==(const Rock &r1, const Rock &r2){

	return r1.name() == r2.name();

}//end operator==

/*****************************************************
Checks if the file opened correctly.

Precondition: Rockfile.txt
Postcondition: Displays an error message to the console
	if the file couldn't be opened.
*****************************************************/

void checkFile(ifstream &inputFile){

	if(!inputFile){
		cout << "Error opening file ----- Terminating.\n";
		exit(1107);
	}//end if

}//end checkFile

/****************************************************
Keeps count for each time a rock type is displayed
in the file.

Precondition: Rockfile.txt
Postcondition: Array contains the number of times each
	rock type is displayed in the file.
****************************************************/

void sampleCount(ifstream &inputFile, int count[]){
	
	Rock r = BASALT;

	while(!inputFile.eof()){
		inputFile >> r;
		count[r.name()]++;
	}
}//end sampleCount

/****************************************************
Overloads the prefix operator.

Precondition: None.
Postcondition: Rock variable can use the prefix 
	operator.
****************************************************/

Rock Rock::operator++(){
	
	switch(myName){
		case BASALT: myName = DOLOMITE;
			break;

		case DOLOMITE: myName = GRANITE;
			break;

		case GRANITE: myName = GYPSUM;
			break;

		case GYPSUM: myName = LIMESTONE;
			break;

		case LIMESTONE: myName = MARBLE;
			break;

		case MARBLE: myName = OBSIDIAN;
			break;

		case OBSIDIAN: myName = QUARTZITE;
			break;

		case QUARTZITE: myName = SANDSTONE;
			break;

		case SANDSTONE: myName = SHALE;
			break;

		default: myName = ROCK_OVERFLOW;	

	}//end switch

	return *this;

}//end operator++


/****************************************************
Displays an 'X' for each time a rock type is read.

Precondition: None
Postcondition: A histogram is displayed to the user.
****************************************************/

void displayHistogram(int count[]){

	Rock rock;

		for(rock = BASALT; rock < ROCK_OVERFLOW; ++rock){ 
			cout << left << setw(10) << rock << " :";		//display Rock names

			for(int j = 0; j < count[rock.name()]; j++)		//display an x for each 
				cout << 'X';								//rock type occurrence 

		cout << " " << "(" << count[rock.name()] << ")" << endl;
	}//end for

}//end displayHistogram