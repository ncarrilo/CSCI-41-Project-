//Nathaniel Carrillo & Jacob Galaviz
#ifndef STREAM_H
#define STREAM_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

const int max = 20;
const int max2nd = 40;

class Film{ //base class 
protected:
  string line;
  char userChoice;
  bool val = true;
public:
  virtual void viewFile(fstream&,fstream&,string*);
  void addFile(fstream&,fstream&,string);
};

class Reel : public Film{ //inherited class 
public:
  void viewFile(fstream& file1,fstream& file2,string*array) override{
    fstream file3;
    //Features of each streaming service with directors
    file3.open("libraryExtra.txt",ios::in);
    cout << "\n\t~List of Film releases by year with Directors~\n" << endl; 
    string* array2nd = new string[::max2nd];
    
    while(!file3.eof()){
      for (int i = 0;i < ::max2nd;i++){
        getline(file3,line);
        *(array2nd + i) = line;    
        cout << line << endl;
      }
    }
    file3.close();
    delete[] array2nd;
  }
  //additional info for original 20 entries 
};
