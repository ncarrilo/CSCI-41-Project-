//Nathaniel Carrillo & Jacob Galaviz
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "stream.h"
using namespace std; 

void Film::viewFile(fstream& file1,fstream& file2,string*array){
  cout << "\n~List of Streaming Services~\n" << endl; 
  while (!file1.eof()){
    for (int i = 0;i < ::max;i++){
      getline(file1,line);
  
      *(array + i) = line;
      
      file2 << line << endl;
      
      cout << "\t" << line << "\n";
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
