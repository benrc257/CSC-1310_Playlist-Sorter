/*
    This is the primary header file for the program.
*/

#ifndef MAIN_H
#define MAIN_H

using namespace std;


// Includes
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <ctime>

// Global Constants
const string StorageInput = "Storage/Playlists";
const string StorageOutput = "Storage/SortedPlaylists";
namespace fs = filesystem;

// Driver Function Prototypes
int printMenu(vector<string>);

#endif