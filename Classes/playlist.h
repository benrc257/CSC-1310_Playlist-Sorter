/*
    This header file is for the linked list that stores playlist data during processing.
*/

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "metadata.h"
#include "../main.h"

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

    public:


    //constructor
    Playlist(string path) {
        
    }

};

#endif