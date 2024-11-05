/*
    This file will contain the function definitions for the sorter class.
*/

#include "sorter.h"

Sorter::Sorter(int choice, string path) //constructor
{
    playlist = new Playlist(path);
    this->outpath = path;
    if (choice > 3) // Z-A
    {
        this->ascending = 0;
        choice = choice - 3;
    } else { // A-Z
        this->ascending = 1;
    };
    this->sortby = choice;
    cout << "\n\n ---- initializing sorter ----\n";
};

void Sorter::sort() {
    
    switch (this->sortby)
    {
        case 1: // name
            cout << LINE << "sorting by Name" << LINE;
            //sortSongsByName();
            break;

        case 2: // artist
            cout << LINE << "sorting by Artist" << LINE;
            //sortSongsByArtist();
            break;
            
        case 3: // album
            cout << LINE << "sorting by Album" << LINE;
            sortSongsByAlbum();
            break;
    }
    
};

// merge sort by Album
/*void Sorter::sortSongsByAlbum() {
    int n = playlist->songsize; // gets size of song arr

    for (int i = 0; i < n - 1; i++) { // merge sort
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
}*/

void Sorter::sortSongsByAlbum() {
    Song<string> *start, *iter1, *iter2, *min;

    start = playlist->head;
    cout << "1\n";
    for (int i = 0; i < playlist->songsize - 3; i++) { //runs until it reaches the second to last node
        iter1 = start;
        cout << "2\n";
        for (int j = 0; j < playlist->songsize - 3 - i; j++) { //runs until it reaches the end of the list from start
            
            cout << "3\n";
            if (toupper(iter1->getNext()->getAlbum()[1]) > toupper(iter1->getNext()->getNext()->getAlbum()[1])) {
                min = iter2;
                cout << "4\n";
            }
            iter1 = iter1->getNext();
        }
        cout << "5\n";
        min->getPrevious()->setNext(min->getNext()); //sets node before min to point to the node after min
        min->getNext()->setPrevious(min->getPrevious()); //sets node after min to point to the node before min   
        min->setNext(start->getNext()); //sets the node after min to the node after start
        start->setNext(min); //sets the node after start to min
        min->setPrevious(start); //sets the node before min to the start node
        cout << "6\n";
        start = min; // progresses start
    }


}

// bubble sort by Artist
/*void Sorter::sortSongsByArtist() {
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
}*/

void Sorter::fileOutput() { //outputs to file with linked list
    cout << LINE << "PREPARING FILE FOR OUTPUT" << LINE;
    ofstream file;
    string temp;
    Song<string> *point;
    outpath = outpath.substr(0, outpath.size()-4) + ".output.csv";
    
    file.open(this->outpath);
   
    point = playlist->head;
    cout << "\nsongsize: " << playlist->songsize;
    for (int i = 1; i < playlist->songsize-2; i++)
    {
        
        point = point->getNext();
        cout << "\n7 " << i << " --- " << point;
        
        file << point;
    }
    
    cout << LINE << LINE << "OUTPUTTING TO FILE" << LINE << LINE;
    file.close();
}




