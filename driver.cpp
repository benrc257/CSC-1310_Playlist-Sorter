/*
    Program: Spotify Playlist Sorter
    Authors: Benjamin Clark, Lucas Starkey
    Start Date: 10/2/24

    This file contains the main function.
*/

#include "main.h"
#include "Classes/sorter.h"

int main() {
    // Variables
    vector<string> filenames;
    string extension = ".csv", currentPath;
    fs::path inputPath{StorageInput};
    fs::directory_entry directory(inputPath);
    fs::directory_iterator directoryIterator(inputPath);
    int count = 0, fileIndex;
    Sorter *sorter = NULL;

    // Adding filenames to the vector for menu
    if (directory.exists()) { // if StorageInput directory exists
        while (directoryIterator != fs::end(directoryIterator)) { // while the iterator has not reached the end of file
            currentPath = directoryIterator->path().string();
            if ((currentPath).substr(currentPath.length()-4) == extension) { //if the path ends in .csv
                filenames.push_back(currentPath); // add current path to the vector
                cout << endl << filenames[count] << " found.\n";
                count++; // increments count
            }
            directoryIterator++; // increments iterator
        }
    } else { // if StorageInput directory does not exist, creates it and returns
        fs::create_directory(StorageInput);
        cout << "Folder \"" << StorageInput << "\" was missing. Folder has been created. Returning...";
        return 0;
    }
    
    fileIndex = fileMenu(filenames);
    
    if (fileIndex == 0) {
        cout << "Folder \"" << StorageInput << "\" is empty. Returning...";
        return 0;
    }

    sorter = new Sorter(sortMenu(), filenames.at(fileIndex-1));
    sorter->sort();
    sorter->fileOutput();
    

    
    delete sorter;
    
  
    return 0;
}