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
    string extension = ".csv", outputExtension = ".output.csv", currentPath;
    fs::path inputPath{StorageInput};
    fs::directory_entry directory(inputPath);
    fs::directory_iterator directoryIterator(inputPath);
    int count = 0, fileIndex;
    Sorter *sorter = NULL;

    cout << LINE;
    cout << "This program takes an unsorted playlist downloaded";
    cout << "\nusing Exportify and sorts it according to user input.";
    cout << LINE;

    // Adding filenames to the vector for menu
    if (directory.exists()) { // if StorageInput directory exists
        while (directoryIterator != fs::end(directoryIterator)) { // while the iterator has not reached the end of file
            currentPath = directoryIterator->path().string();
            if ((currentPath).substr(currentPath.length()-4) == extension && (currentPath).find(outputExtension) == string::npos) { //if the path ends in .csv
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
    
    sorter = new Sorter(sortMenu(), filenames.at(fileIndex-1)); //creates sorter object with input from the sorting menu and the file path
    sorter->sort(); //sorts data
    sorter->fileOutput(); // outputs to file
    

    cout << LINE << "Sorting Complete.\n";
    delete sorter;
    return 0;
}