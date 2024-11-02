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
    Song *temp1, *temp2, *point;

    int n = (this->songs)[0].size; // gets size of song arr
    for (int i = 1; i < n - 1; i++) { // bubble sort
        point = songs[0].next;
        // Compare the song album of consecutive songs
        if (ascending) // seperates into accending 
        {
            for (int j = 0; j < n - i; j++) {
                if (toupper(point->next->album.getData()[1]) > toupper(point->next->next->album.getData()[1])) { // A-Z
               
                    
                  // Swap if the current song name is lexicographically greater than the nex
                    //cout << "\n songs[j]" << point->next->album.getData()
                    //     << "\n songs[j+1]" << point->next->next->album.getData();

                    temp1 = point->next;
                    temp2 = point->next->next;
                    point = point->next;
                    point->next = temp1;
                    temp1 = temp2;


                //    songs[j-1].next = &songs[j+1];     
                //    songs[j].next = songs[j+1].next; 
                //    songs[j+1].next = &songs[j];
                   
                   //cout << "\n song[j] = " << point->next->album.getData();
                   
                   //cout << "\n song[j + 1] = " << point->next->next->album.getData();
                }
                point = point->next;
                cout << "\n[" << j << "] " << point->album.getData();
                //cout << "\n[" << j+1 << "] " << point->next->album.getData();
            }
        } else { 
            for (int j = n-1; j > i + 2; j--) {
                if (toupper(songs[j].album.getData()[1]) < toupper(songs[j + 1].album.getData()[1])) { // Z-A
                    // same as accending but the for loop works backwards
                    temp1 = songs[j+1].next; // pointer to songs[j+1]
                    songs[j+1].next = songs[j].next;
                    songs[j].next = temp1;
                }  
            }
        }
    }
}

// bubble sort by Artist
void Sorter::sortSongsByArtist() {
    Song temp;

    int n = (this->songs)[0].size; // gets size of song arr
    for (int i = 0; i < n - 1; i++) { // bubble sort
        for (int j = 0; j < n - i - 1; j++) {
            // Compare the song artist of consecutive songs
            if (ascending) // seperates into accending 
            {
                if (toupper(songs[j].artist.getData()[1]) > toupper(songs[j + 1].artist.getData()[1])) { // A-Z
                    // Swap if the current song artist is lexicographically greater than the next
                    temp = songs[j];
                    songs[j] = songs[j + 1];
                    songs[j + 1] = temp;
                }
            } else { 
            
                if (toupper(songs[j].artist.getData()[1]) < toupper(songs[j + 1].artist.getData()[1])) { // Z-A
                    // Swap if the current song artist is lexicographically lesser than the next
                    temp = songs[j];
                    songs[j] = songs[j + 1];
                    songs[j + 1] = temp;
                }
            }
        }
    }
}

// bubble sort by name
void Sorter::sortSongsByName() {
    Song temp;

    int n = (this->songs)[0].size; // gets size of song arr
    for (int i = 0; i < n - 1; i++) { // bubble sort
        for (int j = 0; j < n - i - 1; j++) {
            // Compare the song names of consecutive songs
            if (ascending) // seperates into accending 
            {
                if (toupper(songs[j].name.getData()[1]) > toupper(songs[j + 1].name.getData()[1])) { // A-Z
                    // Swap if the current song name is lexicographically greater than the next
                    temp = songs[j];
                    songs[j] = songs[j + 1];
                    songs[j + 1] = temp;
                }
            } else { 
            
                if (toupper(songs[j].name.getData()[1]) < toupper(songs[j + 1].name.getData()[1])) { // Z-A
                    // Swap if the current song name is lexicographically lesser than the next
                    temp = songs[j];
                    songs[j] = songs[j + 1];
                    songs[j + 1] = temp;
                }
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
   
    point = songs[0].next;
    for (int i = 1; i < songs[0].size; i++)
    {
        point = point->next;
        temp = point->artist.getData() + ',' + point->name.getData() +','+ point->album.getData() + "\n" ;
        file << temp;
    }
    
    cout << LINE << LINE << "OUTPUTTING TO FILE" << LINE << LINE;
    file.close();
}
