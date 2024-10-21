/*
    This header file is for the linked list that stores playlist data during processing.
*/

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "metadata.h"
#include "../main.h"

// Names For .CSV Columns
const string track = "Track Name";
const string album = "Album Name";
const string artists = "Artist Name(s)";


// Class for holding the playlist data
class Playlist {
    private:
        struct Song { //holds song data
            Metadata<string> text;
            Metadata<time_t> time;
            Metadata<float> stats;
        };

        list<Song> songs;
        string *filecontent;
        string **cells;
        int rows, columns;

    public:
        int countColumns(string); //counts the number of commas in a string


    //constructor
    Playlist(string path) {
        string line;
        size_t start, end;
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
            }

        } else {
            throw runtime_error("The selected file was unable to be opened!");
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
                end = line.find(',');
                this->cells[i][j] = line.substr(start, end-1);
                start = end+1;
            }
        }

        file.close();
    }

    //destructor
    ~Playlist() {
        for (int i = 0; i < this->columns; i++) { //deletes columns
            delete [] cells[i];
        }
        delete [] cells; //deletes rows
    }

};

#endif