//Nathaniel Carrillo & Jacob Galaviz 

//This file contains function regarding the struct Profit 
//found in stream.h

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "stream.h"
using namespace std; 

//Prototypes for functions dealing with struct Profit
void calculatedProfit(Profit[]);
void searchSortSelection(Profit[]);
void sortProfit(Profit[]);
//void mergeProfit(Profit[], int, int, int);
string searchProfit(Profit[],Profit);

//Function to calculate the profit made by each streaming service 
void calculatedProfit(Profit a[]){
  cout << "Calculating the money each streaming service makes\n" << endl; 
  fstream file4;
  fstream file5;
  fstream file6;
  long double total;
  bool choice = true;
  
  //Opens the three files for use 
  file4.open("filmSub.txt",ios::in);
  file5.open("filmCharge.txt",ios::in);
  file6.open("filmName.txt",ios::in);

  while(choice){
    if(!file4.eof()){ //Nesting 
      if(!file5.eof()){ //All three files 
        if(!file6.eof()){ //in set of while loops 
          for(int i = 0;i < ::max - 1;i++){
            file4 >> a[i].subcount; //Stores subscriber account
            for(int j = 0;j < ::max - 1;j++){
              file5 >> a[j].charge; //Stores charge for each service
              for (int k = 0;k < ::max - 1;k++){
                cin.ignore();
                getline(file6,a[k].name); //Stores name of each streaming service 
                //Calculates money made monthly
                total = a[i].subcount * a[j].charge * pow(10.0,6); 
                cout << a[k].name  //Displays the money made  
                  << " makes $" << total << " monthly.";       
                
                char ch;
                bool tf = true;
                while(tf){
                  cout << "\nContinue(y/n)? ";
                  cin.get(ch);
                  switch(ch){
                    case 'y': case 'Y':
                      tf = false;
                      break;
                    case 'n': case 'N':
                      choice = false;
                      tf = false;
                      return;
                      break;
                    default: cout << "Please enter y/n" << endl;
                  }
                }                  
              } 
            } 
          }
        }
      }
    }
  }
  
  file4.close();
  file5.close();
  file6.close();
  cout << endl;
}

void searchSortSelection(Profit a[]){  
  cout << "\n\t1)Search the list of Services?\n\t2)Sort the profit earned.\n";
  cout << "What would you like to do next? ";
  Profit b;
  bool choice = true;
  int opt = 0;
  while(choice){
    cin >> opt;
    switch(opt){
      case 1:
        searchProfit(a,b);
        break;
      case 2:
        sortProfit(a);
        break;
      default: cout << "\n\tPlease enter a correct option!" << endl;
    }
  }
}

void sortProfit(Profit p[]){
  bool swapped;

  do{
    swapped = false;
    for(int count = 0; count < ::max -1;count++){
      if(p[count].charge > p[count + 1].charge){
        swap(p[count],p[count + 1]);
        swapped = true;
      }
    }
  }while(swapped);
}

//Searches name of streaming service
string searchProfit(Profit arr[],Profit in){
  for(int i = 0;i < ::max;i++){
    if(arr[i].name == in.key){
      in.key = i;
      break;
    }
  }
  return in.key;
}
