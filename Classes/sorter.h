/*
    This header file is for the data processing class.
*/

#ifndef SORTER_H
#define SORTER_H

#include "playlist.h"
#include "../main.h"

class Sorter
{
    private:
        string outpath;
        int sortby; // what to sort by
        bool ascending; // true = ascending, false = descending
        Playlist* playlist = NULL; // the playlist to sort

    public:
        void sort(); // contains switch for determining what to sort by
        void sortSongsByAlbum();
        //void sortSongsByName();
        //void sortSongsByArtist();

        void fileOutput();// outputs to file

        Sorter(int choice, string path); // constructor

        ~Sorter(){

            delete playlist;

        }

    
};







#endif