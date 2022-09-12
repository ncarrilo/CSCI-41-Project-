//Nathaniel Carrillo, Jacob L Galaviz 
#include <iostream>
#include <fstream>
#include <string>
#include "dataStream.h"
using namespace std;

//Erases the original text file
void Library::destroyFile(ifstream&, int effect) {
    //Removes the original external file
    effect = remove("library.txt");
    if (effect == 0) {
        cout << "\nOld Data is ready for override!" << endl;
    }
}

void Library::optionOne(ifstream& iFile,string* arrayList,string line, const int elm) const {
    cout << "You have selected to view the contents of our services! " << endl;
    //Storing the external files' contents to the array
    while (!iFile.eof()) {
        for (int i = 0; i < elm; i++) {
            //Data from text file is stored in array 
            getline(iFile, line);

            //readline is assigned to a dynamic array 
            *(arrayList + i) = line;
        }
    }
}

void Library::optionTwo(ofstream& oFile, string, const int) {
    cout << "\nYou have selected to edit the our content!" << endl;
    //An output file is opened so that new edited data can be written to it
    oFile.open("updatedLibrary.txt"); //New file created 
}

//Function that displays statments when the user has chose to exit the program
void Library::optionThree() {
    cout << "You are exiting the application.";
    cout << "We appreciate you using our service";
    cout << "\n\tThank You," << endl;
}

void Film::optionOne(ifstream& file, string* filmList, string dataLine, const int indexSize)const{
    file.open(""); //Opens a seconod external file with new data including film titles & directors/producers 


}

int Library::optionMenu(ifstream& iFile, ofstream& ofile, string* array, string line, const int elm) {
    int choice = 0;
    char decision;

    do {
        cin >> choice;
        if (choice == 1) {
            //Reads in the data from library.txt   
            optionOne(iFile,array, line, elm);
        }
        else if (choice == 2) {
            optionTwo(ofile, line, elm);
        }
        else if (choice == 3) {
            optionThree();
            return 0;
        }
        else {
            cout << "\nYou have no entered a valid option";
            cout << "Please try again.\n";

        }
    }while (choice == 1 || choice == 2 || choice == 3);
}
