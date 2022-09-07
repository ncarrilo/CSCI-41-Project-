//Nathaniel Carrillo, Jacob L Galaviz 
#ifndef MAINHEAD_H
#define MAINHEAD_H
#include <iostream>
#include <fstream>
using namespace std;

class Library {
private:
	const int size = 20;
	string* streamArray;

public:
	//Member Functions interact with the text file to allow users to 
	// make changes and view all available information. 
	void destroyFile(ifstream&, int); //destroys the original text file
};

#endif