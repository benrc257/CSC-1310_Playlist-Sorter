/*
    This file will contain the function definitions for the playlist class.
*/

#include "playlist.h"

// Function for counting commas in a string, returns the count+1 (number of columns) or -1 if the string is empty
int Playlist::countColumns(string line) {
    int count = 1;
    size_t start = 0, end = 0;

    if (line.size() == 0) {
        return -1;
    }

    while (start < line.size() && line.find(',', start) != string::npos) { //runs while start is smaller than line and commas are still being found
        end = line.find(',', start);
        start = end+1;
        count++;
    }

    return count;
}