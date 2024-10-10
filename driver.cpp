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
    fs::path inputPath{StorageInput};
    fs::directory_entry directory(inputPath);
    fs::directory_iterator directoryIterator(inputPath);
    int count = 0;

    // Adding filenames to the vector for menu
    if (directory.exists()) { // if StorageInput directory exists
        while (directoryIterator != fs::end(directoryIterator)) { // while the iterator has not reached the end of file
            filenames.push_back(directoryIterator->path()); // add current path to the vector
            cout << endl << filenames[count] << " found.\n";
            directoryIterator++; // increment iterator and count
            count++;
        }
    } else { // if StorageInput directory does not exist, creates it and returns
        fs::create_directory(StorageInput);
        cout << "Folder \"" << StorageInput << "\" was missing. Folder has been created. Returning...";
        return 0;
    }

    return 0;
}