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
    Song *previous, *next;
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
        cout << "\nTEST playlist.h line 42 ----- constructor ---- start";
        fillCells(path); //opens file and fills cells
        cout << "\nTEST playlist.h line 45 ----- constructor ----";
        loadList(); //loads cells into list
        cout << "\nTEST playlist.h line 47 ----- constructor ----";
    }

    //destructor
    ~Playlist() {
        for (int i = 0; i < this->columns; i++) { //deletes columns
            delete [] cells[i];
        }
        delete [] cells; //deletes rows
        delete [] songs; //deletes songs array
    }

};

#endif