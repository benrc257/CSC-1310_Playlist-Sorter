/*
    This file will contain the function definitions for the driver.
*/

#include "main.h"
#include "Classes/sorter.h"

int printFileMenu(vector<string> files){ //prints the file menu

    int input;
    cout << line;
    for (int i = 0; i < file.length; i++) // loops though the files and prints them
    {
        cout  << "\n" << i << ": "  << file.at(i);
    }
    cout << "\nplease input the number next to the file youd like to choose: \n";
    cin << input;
    return input;
}

int printSortMenu(){
    int choice;
    int accending;

    cout << line <<  "how would you like to sort the Playlist?";
    cout << "\n" << "1: " << "  song name";
    cout << "\n" << "2: " << "artist name";
    cout << "\n" << "3: " << " album name"
    cin >> choice;

    cout << line << "accending or decending?" 
    cout << "\n" << "1: " << "accending";
    cout << "\n" << "2: " << "decending";
    cin >> accending;

    if (accending == 2)
    {
        return (choice += 3);
    } else
    {
        return choice;
    }
    
    
};