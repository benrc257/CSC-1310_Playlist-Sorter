/*
    This file will contain the function definitions for the sorter class.
*/

#include "sorter.h"
#include "playlist.h"

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
    cout << "\n\n ---- Initializing Sorter ----\n";
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

// Selection sort by album
void Sorter::sortSongsByAlbum() {
    Song<string> *start, *iter1, *min;

    start = playlist->getHead();
    
    if (ascending) { //A-Z
        for (int i = 0; i < playlist->getSongsize() - 3; i++) { //runs until it reaches the second to last node
            iter1 = start->getNext();
            min = start->getNext();

            for (int j = 0; j < playlist->getSongsize() - 2 - i; j++) { //runs until it reaches the end of the list from start
                

                if (toupper(iter1->getAlbum()[1]) < toupper(min->getAlbum()[1])) { //compares current min to iterator
                    min = iter1; //if iter is smaller, min = iter

                }
                iter1 = iter1->getNext(); //progresses iter
            }

            playlist->insertAfter(playlist->pop(min), start); //inserts min after the start node and removes min from the list
            

            start = min; // progresses start
        }
    } else { //Z-A
        for (int i = 0; i < playlist->getSongsize() - 3; i++) { //runs until it reaches the second to last node
            iter1 = start->getNext();
            min = start->getNext();

            for (int j = 0; j < playlist->getSongsize() - 2 - i; j++) { //runs until it reaches the end of the list from start
                

                if (toupper(iter1->getAlbum()[1]) > toupper(min->getAlbum()[1])) { //compares current min to iterator
                    min = iter1; //if iter is bigger, min = iter

                }
                iter1 = iter1->getNext(); //progresses iter
            }

            playlist->insertAfter(playlist->pop(min), start); //inserts min after the start node and removes min from the list
            

            start = min; // progresses start
        }
    }

}

// Selection sort by artist
void Sorter::sortSongsByArtist() {
    Song<string> *start, *iter1, *min;

    start = playlist->getHead();
    
    if (ascending) { //A-Z
        for (int i = 0; i < playlist->getSongsize() - 3; i++) { //runs until it reaches the second to last node
            iter1 = start->getNext();
            min = start->getNext();

            for (int j = 0; j < playlist->getSongsize() - 2 - i; j++) { //runs until it reaches the end of the list from start
                

                if (toupper(iter1->getArtist()[1]) < toupper(min->getArtist()[1])) { //compares current min to iterator
                    min = iter1; //if iter is smaller, min = iter

                }
                iter1 = iter1->getNext(); //progresses iter
            }

            playlist->insertAfter(playlist->pop(min), start); //inserts min after the start node and removes min from the list
            

            start = min; // progresses start
        }
    } else { //Z-A
        for (int i = 0; i < playlist->getSongsize() - 3; i++) { //runs until it reaches the second to last node
            iter1 = start->getNext();
            min = start->getNext();

            for (int j = 0; j < playlist->getSongsize() - 2 - i; j++) { //runs until it reaches the end of the list from start
                

                if (toupper(iter1->getArtist()[1]) > toupper(min->getArtist()[1])) { //compares current min to iterator
                    min = iter1; //if iter is bigger, min = iter

                }
                iter1 = iter1->getNext(); //progresses iter
            }

            playlist->insertAfter(playlist->pop(min), start); //inserts min after the start node and removes min from the list
            

            start = min; // progresses start
        }
    }

}

// Selection sort by name
void Sorter::sortSongsByName() {
    Song<string> *start, *iter1, *min;

    start = playlist->getHead();
    
    if (ascending) { //A-Z
        for (int i = 0; i < playlist->getSongsize() - 3; i++) { //runs until it reaches the second to last node
            iter1 = start->getNext();
            min = start->getNext();

            for (int j = 0; j < playlist->getSongsize() - 2 - i; j++) { //runs until it reaches the end of the list from start
                

                if (toupper(iter1->getName()[1]) < toupper(min->getName()[1])) { //compares current min to iterator
                    min = iter1; //if iter is smaller, min = iter

                }
                iter1 = iter1->getNext(); //progresses iter
            }

            playlist->insertAfter(playlist->pop(min), start); //inserts min after the start node and removes min from the list
            

            start = min; // progresses start
        }
    } else { //Z-A
        for (int i = 0; i < playlist->getSongsize() - 3; i++) { //runs until it reaches the second to last node
            iter1 = start->getNext();
            min = start->getNext();

            for (int j = 0; j < playlist->getSongsize() - 2 - i; j++) { //runs until it reaches the end of the list from start
                

                if (toupper(iter1->getName()[1]) > toupper(min->getName()[1])) { //compares current min to iterator
                    min = iter1; //if iter is bigger, min = iter

                }
                iter1 = iter1->getNext(); //progresses iter
            }

            playlist->insertAfter(playlist->pop(min), start); //inserts min after the start node and removes min from the list
            

            start = min; // progresses start
        }
    }

}

void Sorter::fileOutput() { //outputs to file with linked list
    cout << LINE << "PREPARING FILE FOR OUTPUT" << LINE;
    ofstream file;
    string temp;
    Song<string> *point;
    outpath = outpath.substr(0, outpath.size()-4) + ".output.csv";
    
    file.open(this->outpath);
   
    point = playlist->getHead();
    cout << "\nLIST SIZE: " << playlist->getSongsize()-2 << "\n";
    for (int i = 1; i < playlist->getSongsize()-1; i++)
    {
        
        point = point->getNext();
        cout << "\n" << i << " --- " << point;
        
        file << point;
    }
    
    cout << LINE << LINE << "OUTPUTTING TO FILE" << LINE << LINE;
    file.close();
}




