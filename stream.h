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
  char script;
  bool val;
public:
  Film(){ //default constructor initializes val
    val = true; 
  }
  //Allows the user to view the contents of film.txt
  virtual void viewFile(fstream&,fstream&,string*); 
  void addFile(fstream&,fstream&,string); //Allows users to add a new entry
};

class Reel : public Film{ //inherited class 
public:
  void viewFile(fstream& file1,fstream& file2,string*array) override{
    fstream file3;
    //Features of each streaming service with directors
    file3.open("filmExtra.txt",ios::in); //Allows filmExtra.txt to be read 
    cout << "\n\t~List of Film releases by year with Directors~\n" << endl; 
    string* array2nd = new string[::max2nd]; //Declaring a new dynamic array
    
    while(!file3.eof()){ //Will display contents of filmExtra.txt
      for (int i = 0;i < ::max2nd;i++){
        getline(file3,line);
        *(array2nd + i) = line;    
        cout << line << endl;
      }
    }
    file3.close(); //closes the file 
    delete[] array2nd; //deallocates memory of the new dynamic array 
  }
  //additional info for original 20 entries 
};

class LinkNode{
private: 
  struct Node{
    double chrg; //value stored in node
    Node* next; //Points to the next node
  };
  Node *head; //head pointer

public:
  LinkNode(){
    head = nullptr;
  }

  void insert(double);
  void display() const; 
  
};

//Data structure will store data vital to calculating the amount of money
//each streaming service recieves per month. 

struct Profit{ 
  string name; //Stores the streaming service's name 
  int subcount; //stores the amount of subcribers
  float charge; //stores the amount that each service charges subscribers, monthly
  long double total; //Stores the total profit each service makes
  string key;
  int array;
};
#endif
