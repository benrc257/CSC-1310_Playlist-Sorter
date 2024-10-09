/*
    Program: Spotify Playlist Sorter
    Authors: ---
    Start Date: 10/2/24

    This file contains the main function.
*/

#include "main.h"
#include "Classes/sorter.h"

int main() {
    // Variables
    vector<string> filenames;
    string extension = ".csv";
    fs::directory_entry directory(StorageInput);

    // Adding filenames to the vector for menu
    if (directory.exists()) { //if StorageInput directory exists

    } else { //if StorageInput directory does not exist, creates it and returns
        fs::create_directory(StorageInput);
    }

    return 0;
}