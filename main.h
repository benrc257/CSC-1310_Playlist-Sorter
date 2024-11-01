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
#include <list>

// Global Constants
const string LINE = "---------------------------------------------";
const string StorageInput = "Storage";
const string StorageOutput = "Storage";
namespace fs = filesystem;

// Driver Function Prototypes
int fileMenu(vector<string>);
int sortMenu();


#endif