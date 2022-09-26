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
#include <string>
#include <fstream>
#include <cstring>
#include "stream.h"
using namespace std;

int main() {
  cout << "Welcome to our Streaming Service Program \n";
  Film screen; //base class object 
  Reel frame; //inherited class object
  string* streamList = new string[::max];
  string entryLine;
  char choice;
  bool option = true;
  
  fstream iFile; //declaring input variable  
  fstream oFile; //declaring output variable
  
  iFile.open("library.txt",ios::in); //opens input file
  oFile.open("libraryNew.txt",ios::app); //opens output file
  //wil also append any new information added by the user
  
  while(option){
    int num1;
    cout << "\n\t1)View Streaming Services\n\t"
      << "2)Add/Remove Services\n\t3)Exit\n";
    cout << "\nPlease choose an option above: ";
    cin >> num1; 
    switch(num1){
      case 1: //Displays the data from the text file 
        int num2;
        cout << "\n\t1)View Streaming Services\n\t"
          << "2)View Features and Directors\n";
        cout << "\nPlease select a choice above: ";
        cin >> num2;
        switch(num2){
          case 1:
            screen.viewFile(iFile,oFile,streamList); //base class call
            break;    
          case 2: 
            frame.viewFile(iFile,oFile,streamList); //derived class call 
            break;
          default: cout << "\n~!Please enter an option given!~\n" << endl;
        }
        break;
      case 2: //Allows users to add and reemove entries
        screen.addFile(iFile,oFile,entryLine);
        break;
      case 3: //Exit Option 
        cout << "\nNow exiting the program!" << endl;
        option = false;
        break; 
      default: cout << "\n\t~!Please enter a correct option!~\n\n" ;
    }
  }
  
  delete[] streamList; //deallocate the array 
  streamList = nullptr; 
  iFile.close(); //closing the input file
  oFile.close(); //closing the output file
  return 0; 
}
