/*
    This file will contain the function definitions for the playlist class.
*/

#include "playlist.h"

// Function for counting commas in a string, returns the count+1 (number of columns) or -1 if the string is empty
int Playlist::countColumns(string line) {
    int count = 1;
    size_t start = 0, end = 0;

    if (line.size() == 0) {
        return -1;
    }

    while (start < line.size() && line.find(',', start) != string::npos) { //runs while start is smaller than line and commas are still being found
        end = line.find(',', start);
        start = end+1;
        count++;
    }

    return count;
}

// Function for collecting info from csv file and placing it into cells
void Playlist::fillCells(string path) {
    string line;
    size_t start, end, quotes;
    ifstream file; //creates file variable and opens it to the file specified from main
    file.open(path);

    while (!file.eof()) { //counts the number of lines
        getline(file, line);
        this->rows++;
    }


    file.seekg(0); //resets the read position back to the start
    file.clear();

    if (file.is_open()) { //checks if file is open, otherwise throws error
        getline(file, line);
        this->columns = countColumns(line);
        if (this->columns < 1) { //if columns is counted to be less than one, throws error
            throw runtime_error("The selected file is empty!");
            return;
        }

    } else {
        throw runtime_error("The selected file was unable to be opened!");
        return;
    }

    *this->cells = new string[this->rows]; //allocates rows

    for (int i = 0; i < this->rows; i++) {
        this->cells[i] = new string[this->columns]; //allocates columns
    }        

    for (int i = 0; i < this->rows; i++) {
        getline(file, line); //reads in a line from the file
        start = 0;
        end = 0;

        for (int j = 0; i < this->columns; j++) { //pushes the cells of the row into cells array
            end = line.find(',', start);

            quotes = (line.substr(start, end)).find('\"'); //finds the first quotation mark in the line substring
            if (quotes != string::npos) { //checks for quotation marks
                if ((line.substr(quotes+1, end)).find('\"') == string::npos) { //checks if the quotes is a pair, or if one is missing
                    end = line.find('\"', end)+1; //finds the missing end quote and adds one
                }
            }

            this->cells[i][j] = line.substr(start, end-1);
            start = end+1;
        }
    }

    file.close();
}