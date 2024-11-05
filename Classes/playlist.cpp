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
    this->rows--;
    
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
    this->songsize = this->rows+2; //sets size of linked list to rows+2 with space for head and tail
    this->songs = new Song<string>[songsize]; //creates Song array
  
    this->head = &songs[0]; //sets head node
    this->tail = &songs[songsize-1]; //sets tail node

    songs[0].setNext(NULL); //sets head next to null
    songs[0].setPrevious(NULL); //sets head previous to null
    songs[songsize-1].setNext(NULL); //sets tail next to null
    songs[songsize-1].setPrevious(NULL); //sets tail previous to null

    for (int i = 1; i < songsize; i++) { //runs after head node and until tail node
        
        //sets previous song's next to current songs address, and current song's previous to previous song's address
        songs[i-1].setNext(&songs[i]);
        songs[i].setPrevious(&songs[i-1]);
        songs[i].setNext(NULL);

        
        //transfers data from the cells vector into the linked list
        if (i != songsize-1) {
            songs[i].setArtist((this->cells)[i-1][3]);
            (this->songs)[i].setAlbum((this->cells)[i-1][2]);
            (this->songs)[i].setName((this->cells)[i-1][1]);
        }
        
    }

}

void Playlist::insertAfter(Song<string>* node, Song<string>* before) { //first argument is the node to be placed, second argument is the node to place after
    //variables
    Song<string> *after;

    after = before->getNext();

    //places node between before and after
    before->setNext(node);
    after->setPrevious(node);

    //sets node's pointers
    node->setNext(after);
    node->setPrevious(before);

}

Song<string>* Playlist::pop(Song<string>* node) {
    //variables
    Song<string> *before, *after;

    //saves the pointers before and after node
    before = node->getPrevious();
    after = node->getNext();

    //bypasses node
    before->setNext(after);
    after->setPrevious(before);

    return node;
}

int Playlist::getSongsize() {
    return this->songsize;
}

Song<string>* Playlist::getHead() {
    return this->head;
}