//Nathaniel Carrillo, Jacob L Galaviz 
#ifndef DATASTREAM_H
#define DATASTREAM_H
#include <iostream>
#include <fstream>
using namespace std;


class Library {
protected:
	const int size = 20;
	string* streamArray;

public:
	Library(); //Default Constructor 
	~Library(); //Destructor 

	//Member Functions interact with the text file to allow users to 
	// make changes and view all available information. 
	void destroyFile(ifstream&, int); //destroys the original text file
	int optionMenu(ifstream&, ofstream&, string*, string, const int);
	virtual void optionOne(ifstream&,string* ,string, const int) const;
	void optionTwo(ofstream&, string, const int);
	void optionThree();
};

//Inherits the Library class 
class Film :public Library {
public:
	//This member function overrides option one 
	void optionOne(ifstream&, string*, string, const int)const override;
};

#endif
