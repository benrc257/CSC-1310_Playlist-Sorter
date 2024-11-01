/*
    This file will contain the function definitions for the sorter class.
*/

#include "sorter.h"

Sorter::Sorter(int choice, string path)
{
    this->outpath = path;
    this->playlist = new Playlist(path);
    if (choice >= 3) // decending
    {
        this->ascending = 0;
    } else { // ascending
        this->ascending = 1;
    };
    this->sortby = choice;
    this->songs = (*this->playlist).getList();
};

void Sorter::sort() {
    
    switch (this->sortby)
    {
        case 1: // name
            sortSongsByName();
            break;

        case 2: // artist
            sortSongsByArtist();
            break;

        case 3: // album
            sortSongsByAlbum();
            break;
    }
    
};

//bubble sort by Album
void Sorter::sortSongsByAlbum() {
    int n = songs[0].size; // gets size of song arr

    for (int i = 0; i < n - 1; i++) { // bubble sort
        for (int j = 0; j < n - i - 1; j++) {
            // Compare the album names of consecutive songs
            if (ascending) // seperates into accending 
            {
                if (songs[j].album.getData()[1] > songs[j + 1].album.getData()[1]) { // A-Z
                    // Swap if the current album name is lexicographically greater than the next
                    Song temp = songs[j];
                    songs[j] = songs[j + 1];
                    songs[j + 1] = temp;
                }

            } else { 
            
                if (songs[j].album.getData()[1] < songs[j + 1].album.getData()[1]) { // Z-A
                    // Swap if the current album name is lexicographically lesser than the next
                    Song temp = songs[j];
                    songs[j] = songs[j + 1];
                    songs[j + 1] = temp;
                }
            }
        }
        
    }
}
// bubble sort by artist
void Sorter::sortSongsByArtist() {
    int n = songs[0].size; // gets size of song arr

    for (int i = 0; i < n - 1; i++) { // bubble sort
        for (int j = 0; j < n - i - 1; j++) {
            // Compare the artist names of consecutive songs
            if (ascending) // seperates into accending 
            {
                if (songs[j].artist.getData() > songs[j + 1].artist.getData()) { // A-Z
                    // Swap if the current artist name is lexicographically greater than the next
                    Song temp = songs[j];
                    songs[j] = songs[j + 1];
                    songs[j + 1] = temp;
                }

            } else { 
            
                if (songs[j].artist.getData() < songs[j + 1].artist.getData()) { // Z-A
                    // Swap if the current artist name is lexicographically lesser than the next
                    Song temp = songs[j];
                    songs[j] = songs[j + 1];
                    songs[j + 1] = temp;
                }
            }
        }
    }
}
// bubble sort by name
void Sorter::sortSongsByName() {
    int n = (this->songs)[0].size; // gets size of song arr
    for (int i = 0; i < n - 1; i++) { // bubble sort
        for (int j = 0; j < n - i - 1; j++) {
            // Compare the song names of consecutive songs
            if (ascending) // seperates into accending 
            {
                if (songs[j].name.getData() > songs[j + 1].name.getData()) { // A-Z
                    // Swap if the current song name is lexicographically greater than the next
                    Song temp = songs[j];
                    songs[j] = songs[j + 1];
                    songs[j + 1] = temp;
                }
            } else { 
            
                if (songs[j].name.getData() < songs[j + 1].name.getData()) { // Z-A
                    // Swap if the current song name is lexicographically lesser than the next
                    Song temp = songs[j];
                    songs[j] = songs[j + 1];
                    songs[j + 1] = temp;
                }
            }
        }
    }
}

void Sorter::fileOutput() {
    ofstream file;
    string temp;
    outpath = outpath.substr(0, outpath.size()-4) + ".output.csv";
    
    file.open(this->outpath);
   
    for (int i = 0; i < songs->size ; i++)
    {
        temp = songs[i].album.getData() + ',' + songs[i].name.getData() +','+ songs[i].artist.getData() + "\n" ;  
        file << temp;
    }
    

    file.close();
}