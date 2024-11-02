/*
    This file will contain the function definitions for the driver.
*/

#include "main.h"

// handles the file selection menu and returns the index of the selected file
int fileMenu(vector<string> files){ 

    int input;
    cout << LINE;
    cout << "\nPlease input the number of the playlist you'd like to sort: \n";
    for (int i = 0; i < files.size(); i++) // loops though the file options and prints them 
    {
        cout  << "\n" << i+1 << ": "  << files.at(i);
    }
    cout << "\n>> ";

    while (!(cin >> input) || input > files.size() || input < 1) { //input validation
        cout << "\nInvalid entry. Please try again. >> ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    return input;
}

// handles the sort menu and takes in input
int sortMenu() {
    int choice;
    int ascending;

     // what to sort by
    cout << LINE <<  "How would you like to sort the playlist?";
    cout << "\n" << "1: " << "Alphabetically, by song name";
    cout << "\n" << "2: " << "Alphabetically, by artist name";
    cout << "\n" << "3: " << "Alphabetically, by album name";
    cout << "\n>> ";
    while (!(cin >> choice) || choice > 3 || choice < 1) { //input validation
        cout << "\nInvalid entry. Please try again. >> ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << LINE << "A-Z or Z-A?";
    cout << "\n" << "1: " << "A-Z";
    cout << "\n" << "2: " << "Z-A";
    cout << "\n>> ";
    while (!(cin >> ascending) || ascending > 2 || ascending < 1) { //input validation
        cout << "\nInvalid entry. Please try again. >> ";
        cin.clear();
        cin.ignore(10000, '\n');
    } // ascending status

    if (ascending == 2) // encodes ascending status into the choices
    {
        return (choice = choice + 3);
    } else
    {
        return choice;
    }
    
    
};