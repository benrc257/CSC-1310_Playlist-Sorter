/*
    This header file will contain the template class for storing metadata within the playlists.
*/

#ifndef METADATA_H
#define METADATA_H

#include "../main.h"
#include <vector>

template<typename T>
class Metadata { //this class will bundle metadata from the song into categories
    private:
        vector<T> data; //multiple of the same type of data can be held in one vector
        vector<string> valueName; //the name of each data point can be held in this parallel vector
    public:
        vector<T> getData(vector<string>&); //returns the data vector and modifies the given vector with the value name data
        vector<T> getData(); //returns the data vector without the value names
        void setData(vector<T>, vector<string>); //data vector, name vector
        void push(T, string); //data value, value name
        T pop(string); //used for popping by value name
        T pop(int); //used for popping by index number
};

#endif