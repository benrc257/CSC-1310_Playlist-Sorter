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
        int sortby;
        int accending;
        Playlist* playlist;
        Song* songs;
    public:
        Song* sort();

        Sorter(int choice, string path);
    
};

Sorter::Sorter(int choice, string path)
{
    this->playlist = new Playlist(path);

    if (choice >= 3) // decending
    {
        this->accending = 0;
    } else { // accending
        this->accending = 1;
    };
    this->sortby = choice;
    
    this->songs = (*this->playlist).getList();
}





#endif