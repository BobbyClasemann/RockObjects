/******Rock File.cpp *****************************
Program that reads from a text file and displays
the contents of the file in histogram format.

Programmer: Bobby Clasemann
Lab Experience 6
Date: Feb. 16, 2017
**************************************************/

#include "Rock.h"

const int SIZE = 10;

int main(){
	
	//declare variables
	int count[SIZE] = {0};
	ifstream inputFile;
	Rock rockVal;

	inputFile.open("Rockfile.txt");

	//function calls
	checkFile(inputFile);
	sampleCount(inputFile, count);
	displayHistogram(count);


	inputFile.close();

	return 0;

}//end main