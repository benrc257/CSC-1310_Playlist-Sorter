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
    
    file.clear();
    file.seekg(0); //resets the read position back to the start
    

    getline(file, line); //pulls first line from file
    this->columns = countColumns(line);

    this->cells = new string*[this->rows]; //allocates rows
    for (int i = 0; i < this->rows; i++) {
        this->cells[i] = new string[this->columns]; //allocates columns
    }      

    for (int i = 0; i < this->rows; i++) {
        getline(file, line); //reads in a line from the file
        start = 0;
        end = 0;

        for (int j = 0; j < this->columns; j++) { //pushes the cells of the row into cells array
            end = line.find(',', start);

            quotes = (line.substr(start, end-start)).find('\"'); //finds the first quotation mark in the line substring
            if (quotes != string::npos) { //checks for quotation marks
                if ((line.substr(quotes+1, end)).find('\"') == string::npos) { //checks if the quotes is a pair, or if one is missing
                    end = line.find('\"', end)+1; //finds the missing end quote and adds one
                }
            }

            this->cells[i][j] = line.substr(start, end-start);
            start = end+1;
        }
    }

    file.close();
}

void Playlist::loadList() {
    cout << "\n ---- Loading Playlist ----\n";
        this->songs = new Song[this->rows+1];
  


    for (int i = 0; i < this->rows; i++) { 
        (this->songs)[i].size = this->rows;
        
        if (i == 0) { //handles first index, sets the previous and next for head to NULL
            (this->songs)[i].next = NULL;
        } else { //handles all other indexes, sets next to NULL, sets previous to previous song's memory address, and previous song's next to current songs address 
            (this->songs)[i].next = NULL;
            (this->songs)[i-1].next = &(this->songs)[i];
        }


        //transfers data from the cells vector into the linked list
        (this->songs)[i].artist.setData((this->cells)[i][3]);
        (this->songs)[i].album.setData((this->cells)[i][2]);
        (this->songs)[i].name.setData((this->cells)[i][1]);
        
        
    }
} 

Song* Playlist::getList() {
    return this->songs;
}