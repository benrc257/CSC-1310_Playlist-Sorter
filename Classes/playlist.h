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
        void fillCells(string);
        void loadList();


    //constructor
    Playlist(string path) {
        try { //checks for errors from fillCells
            fillCells(path);
        } catch(runtime_error err) { //passes possible errors into main
           throw runtime_error(err.what());
        }

        loadList();


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