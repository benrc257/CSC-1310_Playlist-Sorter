/*
    This file will contain the function definitions for the sorter class.
*/

#include "sorter.h"

Sorter::Sorter(int choice, string path)
{
    this->outpath = path;
    this->playlist = new Playlist(path);
    if (choice > 3) // decending
    {
        this->ascending = 0;
        choice = choice - 3;
    } else { // ascending
        this->ascending = 1;
    };
    this->sortby = choice;
    this->songs = (*this->playlist).getList();
    cout << "\n\n ---- initializing sorter ----\n";
};

void Sorter::sort() {
    
    switch (this->sortby)
    {
        case 1: // name
            cout << LINE << "sorting by Name" << LINE;
            sortSongsByName();
            break;

        case 2: // artist
            cout << LINE << "sorting by Artist" << LINE;
            sortSongsByArtist();
            break;
            
        case 3: // album
            cout << LINE << "sorting by Album" << LINE;
            sortSongsByAlbum();
            break;
    }
    
};

// bubble sort by Album
void Sorter::sortSongsByAlbum() {
    Song *temp1, *temp2, *point, *previous;

    int n = (this->songs)[0].size-1; // gets size of song arr
    for (int i = 0; i < n - 1; i++) { // bubble sort
        previous = &songs[0]; //sets previous to be used as iterator

        // Compare the song album of consecutive songs
        if (ascending) // seperates into accending 
        {

            for (int j = 0; j < n - i - 1; j++) {
                point = previous->next; //sets point to the correct pointer for swapping
                if (toupper(previous->next->album.getData()[1]) > toupper(point->next->album.getData()[1])) { // A-Z
                    // Swap if the current song name is lexicographically greater than the nex

                    //holding values
                    temp1 = point->next->next;
                    temp2 = point->next;

                    //swapping values
                    point->next->next = previous->next;
                    point->next = temp1;
                    previous->next = temp2;

                }
                previous = previous->next; //iterates to the next node
            }
        } else { 
            for (int j = 0; j < n - i - 1; j++) {
                point = previous->next; //sets point to the correct pointer for swapping
                if (toupper(previous->next->album.getData()[1]) < toupper(point->next->album.getData()[1])) { // Z-A
                    // Swap if the current song name is lexicographically greater than the nex

                    //holding values
                    temp1 = point->next->next;
                    temp2 = point->next;

                    //swapping values
                    point->next->next = previous->next;
                    point->next = temp1;
                    previous->next = temp2;

                }
                previous = previous->next; //iterates to the next node
            }
        }
    }
}

// bubble sort by Artist
void Sorter::sortSongsByArtist() {
    Song *temp1, *temp2, *point, *previous;

    int n = (this->songs)[0].size-1; // gets size of song arr
    for (int i = 0; i < n - 1; i++) { // bubble sort
        previous = &songs[0]; //sets previous to be used as iterator

        // Compare the song artist of consecutive songs
        if (ascending) // seperates into accending 
        {

            for (int j = 0; j < n - i - 1; j++) {
                point = previous->next; //sets point to the correct pointer for swapping
                if (toupper(previous->next->artist.getData()[1]) > toupper(point->next->artist.getData()[1])) { // A-Z
                    // Swap if the current song name is lexicographically greater than the nex

                    //holding values
                    temp1 = point->next->next;
                    temp2 = point->next;

                    //swapping values
                    point->next->next = previous->next;
                    point->next = temp1;
                    previous->next = temp2;

                }
                previous = previous->next; //iterates to the next node
            }
        } else { 
            for (int j = 0; j < n - i - 1; j++) {
                point = previous->next; //sets point to the correct pointer for swapping
                if (toupper(previous->next->artist.getData()[1]) < toupper(point->next->artist.getData()[1])) { // Z-A
                    // Swap if the current song name is lexicographically greater than the nex

                    //holding values
                    temp1 = point->next->next;
                    temp2 = point->next;

                    //swapping values
                    point->next->next = previous->next;
                    point->next = temp1;
                    previous->next = temp2;

                }
                previous = previous->next; //iterates to the next node
            }
        }
    }
}

// bubble sort by name
void Sorter::sortSongsByName() {
    Song *temp1, *temp2, *point, *previous;

    int n = (this->songs)[0].size-1; // gets size of song arr
    for (int i = 0; i < n - 1; i++) { // bubble sort
        previous = &songs[0]; //sets previous to be used as iterator

        // Compare the song name of consecutive songs
        if (ascending) // seperates into accending 
        {

            for (int j = 0; j < n - i - 1; j++) {
                point = previous->next; //sets point to the correct pointer for swapping
                if (toupper(previous->next->name.getData()[1]) > toupper(point->next->name.getData()[1])) { // A-Z
                    // Swap if the current song name is lexicographically greater than the nex

                    //holding values
                    temp1 = point->next->next;
                    temp2 = point->next;

                    //swapping values
                    point->next->next = previous->next;
                    point->next = temp1;
                    previous->next = temp2;

                }
                previous = previous->next; //iterates to the next node
            }
        } else { 
            for (int j = 0; j < n - i - 1; j++) {
                point = previous->next; //sets point to the correct pointer for swapping
                if (toupper(previous->next->name.getData()[1]) < toupper(point->next->name.getData()[1])) { // Z-A
                    // Swap if the current song name is lexicographically greater than the nex

                    //holding values
                    temp1 = point->next->next;
                    temp2 = point->next;

                    //swapping values
                    point->next->next = previous->next;
                    point->next = temp1;
                    previous->next = temp2;

                }
                previous = previous->next; //iterates to the next node
            }
        }
    }
}
void Sorter::fileOutput() { //outputs to file with linked list
    cout << LINE << "PREPARING FILE FOR OUTPUT" << LINE;
    ofstream file;
    string temp;
    Song *point;
    outpath = outpath.substr(0, outpath.size()-4) + ".output.csv";
    
    file.open(this->outpath);
   
    point = &songs[0];
    for (int i = 1; i < songs[0].size; i++)
    {
        point = point->next;
        temp = point->artist.getData() + ',' + point->name.getData() +','+ point->album.getData() + "\n" ;
        file << temp;
    }
    
    cout << LINE << LINE << "OUTPUTTING TO FILE" << LINE << LINE;
    file.close();
}
