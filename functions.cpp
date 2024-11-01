/*
    This file will contain the function definitions for the driver.
*/

#include "main.h"

// handles the file selection menu and returns the index of the selected file
int fileMenu(vector<string> files){ 

    int input;
    cout << LINE;
    for (int i = 0; i < files.size(); i++) // loops though the file options and prints them 
    {
        cout  << "\n" << i+1 << ": "  << files.at(i);
    }
    cout << "\nplease input the number next to the file youd like to choose: \n";
    cin >> input;
    return input;
}

// handles the sort menu and takes in input
int sortMenu() {
    int choice;
    int accending;

    cout << LINE <<  "how would you like to sort the Playlist?";
    cout << "\n" << "1: " << "  song name";
    cout << "\n" << "2: " << "  artist name";
    cout << "\n" << "3: " << "  album name";
    cin >> choice; // what to sort by

    cout << LINE << "accending or decending?";
    cout << "\n" << "1: " << "accending";
    cout << "\n" << "2: " << "decending";
    cin >> accending; // accending status

    if (accending == 2) // encodes aceending status into the choices
    {
        return (choice += 3);
    } else
    {
        return choice;
    }
    
    
};