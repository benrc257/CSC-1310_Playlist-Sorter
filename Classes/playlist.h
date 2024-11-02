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

// Structure for holding song data
struct Song {
    int size;
    Song *next;
    Metadata<string> name;
    Metadata<string> artist;
    Metadata<string> album;

};

// Class for holding the playlist data
class Playlist {
    private:
        Song* songs;
        string *filecontent;
        string **cells;
        int rows = 0, columns = 0;

    public:
        int countColumns(string); //counts the number of commas in a string
        void fillCells(string);
        void loadList();
        Song* getList();


    //constructor
    Playlist(string path) {
        fillCells(path); //opens file and fills cells
        loadList(); //loads cells into list
    }

    //destructor
    ~Playlist() {
        for (int i = 0; i < this->rows+1; i++) { //deletes columns
            delete [] cells[i];
        }
        delete [] cells; //deletes rows
        delete [] songs; //deletes songs array
    }

};

#endif