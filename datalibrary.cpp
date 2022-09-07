//Nathaniel Carrillo, Jacob L Galaviz 

//This program allows the user to view up to twenty 
//different streaming services along with 
//being given the option to add or delete entries that 
//get stored into a dynamically allocated array. 

//The user will be prompted to press any key on the keyboard to progress

//Then the user will be given the option to either 1. View the currently
//exsting data, 2. To change or edit the data that was stored into the 
//dynamic array and 3. To exit, which will leave the program entirely. 

//So far in our Library class we have a member function that will remove the 
//original file which will allow for a new file to be created that 
#include <iostream>
#include <fstream>
#include <string>
#include "dataLibrary.h"
using namespace std;

int main() {
    Library book; //Object that will give us access to our member functions. 
    int status = 0;{};
    int userInput;
    string readLine;

    //Allocating Memory for a Dynamic Array 
    const int maxSize = 20; //index limit 
    string* streamList = nullptr;
    streamList = new string[maxSize];

    //Opening the external file 
    ifstream libraryFile;
    ofstream newFile;

    //The following statements introduce the viewer to the program 
    cout << "Welcome to our Streaming Service Apps" << endl;

    cout << "\n(Press any key on you keyboard to continue)\n";
    cin.get();

    cout << "What would you like to do?\n";
    cout << "\n(Press any key on you keyboard to continue)\n";
    cin.get();

    libraryFile.open("library.txt");
    //Prompt the viwer with three options 
    cout << "(1) View Services\n(2) Edit Services\n(3) Exit\n";

    cin >> userInput;
    cout << endl;

    //The following switch statemnet allows the user to pick options 
    //from a menu
    switch (userInput) {
    case 1:
        cout << "You have selected to view the contents"
            << " of our services! " << endl;

        //Storing the external files' contents to the array
        while (!libraryFile.eof()) {
            for (int i = 0; i < maxSize; i++) {
                //Data from text file is stored in array 
                getline(libraryFile, readLine); 
                
                //readline is assigned to a dynamic array 
                *(streamList + i) = readLine; 
            }
        }

        //Reads the contents from the text file that
        //were stored in streamArray 
        for (int index = 0; index < maxSize; index++) { 
            cout << index + 1 << ": " << *(streamList + index) << endl;
        }
        break;

    case 2:
        cout << "\nYou have selected to edit the our content!" << endl;
        //An output file is opened so that new edited data can be written to it

        newFile.open("updatedLibrary.txt"); //New file created 

        //Branch that functions if the file has been opened correctly 
        if (newFile.is_open()) {
            cout << "\nNew File has been successfully created!\n" << endl;
            
            //Array allows for datat from text file to be read
            //into the dynamic array 
            int counter = 0;
            for (counter = 0; counter < maxSize; counter++) {
                getline(libraryFile, readLine);
                *(streamList + counter) = readLine;
            }

            //user is prompted to enter a new entry 
            cout << "Enter a new entry: ";
            string newEntry;
            cin.ignore();
            getline(cin, newEntry);

            //New entry is added to the dynamic array 
            *(streamList + counter) = newEntry; 
            counter++;

            //Displays what the user has entered into the array
            cout << "With your new entry, this is the new list: " << endl;
            for (counter = 0; counter < maxSize; counter++) {
                cout << counter + 1 << ": " << *(streamList + counter) << endl;
            }

            newFile.close(); //closes the new updated text file
        }
        else {
            cout << "File could not be opened!" << endl;
        }
        book.destroyFile(libraryFile, status); //Removes the old file
        cout << "\nYour edits have been saved!" << endl;
        break;

    case 3:
        //Allows the user to exit the program 
        cout << "\nYou are now exiting the program." << endl;
        break;
    }

    //Ending the program 
    cout << "\nThank You for choosing our service!\n" << endl;

    delete[] streamList; //deallocating memory
    streamList = NULL;
    libraryFile.close(); //closing the external file
    return 0;
}

//Erases the original text file
void Library::destroyFile(ifstream&, int effect) {
    //Removes the original external file
    effect = remove("library.txt");
    if (effect == 0) {
        cout << "\nOld Data is ready for override!" << endl;
    }
}