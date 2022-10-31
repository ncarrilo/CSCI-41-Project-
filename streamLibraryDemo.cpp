//Nathaniel Carrillo & Jacob Galaviz

//This program allows the user to view up to twenty 
//different streaming services along with 
//being given the option to add or delete entries 

//Then the user will be given the option to either 1. View the currently
//exsting data, 2. To change or edit the streaming serive entries 
//and 3. To exit, which will close the program entirely. 

#include <iostream>
#include <string>
#include <fstream>
#include "stream.h"
using namespace std;

void branch(bool,Film&,Reel&,fstream&,fstream&,string*,string);

int main() {
  cout << "Welcome to our Streaming Service Program \n";
  Film screen; //base class object 
  Reel frame; //inherited class object
  string* streamList = new string[::max]; //dynamically allocated array
  string entryLine; //string stores entries to be displayed to console 
  bool option = true; //bool variable while break while loop when false 
  
  fstream iFile; //declaring input variable  
  fstream oFile; //declaring output variable
  
  iFile.open("film.txt",ios::in); //opens input file
  oFile.open("filmNew.txt",ios::app); //opens output file
  //wil also append any new information added by the user
  
  branch(option,screen,frame,iFile,oFile,streamList,entryLine); //main menu 
  
  delete[] streamList; //deallocate the array 
  streamList = nullptr; //sets dynamic array to nullptr
  iFile.close(); //closing the input file
  oFile.close(); //closing the output file
  return 0; 
}
