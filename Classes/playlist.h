/*
    This header file is for the linked list that stores playlist data during processing.
*/

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"
#include "../main.h"

// Names For .CSV Columns
const string track = "Track Name";
const string album = "Album Name";
const string artists = "Artist Name(s)";

// Class for holding the playlist data
class Playlist {
    private:
        // Variables
        Song<string> *songs, *head, *tail;
        string **cells;
        int rows = 0, columns = 0;
        int songsize = 0;

    public:
        //file functions
        int countColumns(string); //counts the number of commas in a string
        void fillCells(string); // fills cells in cells array
        void loadList(); // fills linked list

        //linked list functions
        void insertAfter(Song<string>*, Song<string>*); //inserts node after given node
        Song<string>* pop(Song<string>*); //pops node


        //friends
        friend class Sorter;
        //friend void Sorter::sortSongsByArtist();
        //friend void Sorter::sortSongsByAlbum();
        //friend void Sorter::sortSongsByName();
        

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