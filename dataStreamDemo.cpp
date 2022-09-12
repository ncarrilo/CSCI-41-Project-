//Nathaniel Carrillo, Jacob L Galaviz 

//This program allows the user to view up to twenty 
//different streaming services along with 
//being given the option to add or delete entries that 
//get stored into a dynamically allocated array. 

//Then the user will be given the option to either 1. View the currently
//exsting data, 2. To change or edit the data that was stored into the 
//dynamic array and 3. To exit, which will leave the program entirely. 

//So far in our Library class we have a member function that will remove the 
//original file which will allow for a new file to be created that 
#include <iostream>
#include <fstream>
#include <string> 
#include "dataStream.h"
using namespace std;

int main() {
	//Objects and variables 
	Film disk; //Using Film class that inherits from library
	int status = 0; {};
	int userInput;
	string readLine;
	ifstream libraryFile;
	ofstream newFile;

	//Allocating Memory for a Dynamic Array 
	const int maxSize = 20; //index limit 
	string* streamList = nullptr;
	streamList = new string[maxSize];

	libraryFile.open("library.txt");

	//The following statements introduce the viewer to the program 
	cout << "Welcome to our Streaming Service Apps" << endl;

	//Instrcutions for user input 
	cout << "Enter the number option you wish to proceed with!" << endl;

	//Prompt the viwer with three options 
	cout << "(1) View Services\n(2) Edit Services\n(3) Exit\n";

	//Calling the memeber function that calls the menu
	disk.optionMenu(libraryFile, newFile, streamList, readLine, maxSize);

	delete[] streamList; //deallocating memory
	streamList = nullptr; //change to nullptr later 
	libraryFile.close(); //closing the external file

	return 0;
}
