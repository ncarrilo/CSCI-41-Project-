//Nathaniel Carrillo & Jacob Galaviz

//This file contains functions related to our main menu

//void branch(); displys the main menu that the user sees as well as 
//The options that they select to view. 

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "stream.h"
using namespace std; 

//Function prototype(s)
void branch(bool,Film&,Reel&,fstream&,fstream&,string*,string);
void calculatedProfit(Profit[]);
void searchSortSelection(Profit[]);
void rosterRecipt();

void Film::viewFile(fstream& file1,fstream& file2,string*array){
  cout << "\n~List of Streaming Services~\n" << endl; 
  while (!file1.eof()){ //reads to the end of entire film.txt file 
    for (int i = 0;i < ::max;i++){//for loop will cycle through, store data in array 
      getline(file1,line);
  
      *(array + i) = line;
      
      file2 << line << endl; //Stores the current line to filmNew.txt
      
      cout << "\t" << line << "\n"; //Writes the contents of line to the console 
    }
  }
}

void Film::addFile(fstream& file1,fstream& file2,string line){
  char answer;
  cout << "\nWould you like to enter a new entry(y/n)? " << endl;
  cin >> answer; 
  
  if (answer == 'y'||answer == 'Y'){
    string entry; 
    cout << "\nPlease enter a new Streaming Service!" << endl;
    cin.ignore();
    getline(cin,entry);

    cout << "\nNew Entry: " << entry << endl;   

    file2 << entry << endl;
  }else if(answer == 'n'||answer == 'N'){ //Will boot user back to main menu
    
  }else{
    cout << "\n\t~!Please enter y/n!~\n\n";
  }
}

void branch(bool tf,Film& s,Reel& f,fstream& i, fstream& o,string* array,string line){
  Profit p[20]; //Declaring array of structures to hold 20 elements
  while(tf){
    int num1;
    cout << "\n\t1)View Streaming Services\n\t"
      << "2)Add/Remove Services\n\t3)Exit\n";
    cout << "\nPlease choose an option above: ";
    cin >> num1; 
    switch(num1){
      case 1: //Displays the data from the text file 
        int num2;
        cout << "\n\t1)View Streaming Services\n\t"
          << "2)View Features and Directors\n\t"
          <<"3)View Profit each service recieves each month.\n\t"
          <<"4)Search/Sort\n\t"
          <<"5)View/Edit Charge\n";
        cout << "\nPlease select a choice above: ";
        cin >> num2;
        switch(num2){
          case 1:
            s.viewFile(i,o,array); //base class call
            break;    
          case 2: 
            f.viewFile(i,o,array); //derived class call 
            break;
          case 3:
            //calls function to access and calculate each services monthly Profit 
            calculatedProfit(p);
            break;
          case 4:
            searchSortSelection(p);
          case 5:
            rosterRecipt();
            break;
          default: cout << "\n~!Please enter an option given!~\n" << endl;
        }
        break;
      case 2: //Allows users to add and reemove entries
        s.addFile(i,o,line);
        break;
      case 3: //Exit Option 
        cout << "\nNow exiting the program!" << endl;
        tf = false;
        break; 
      default: cout << "\n\t~!Please enter a correct option!~\n\n" ;
    }
  }
}
