/*
    This header file will contain the template class for storing metadata within the playlists.
*/

#ifndef METADATA_H
#define METADATA_H

#include "../main.h"

template<typename T>
class Metadata { //this class will hold metadata for each song
    private:
        T data;
    public:
        T getData(); //returns the data value
        void setData(T&); //intakes data value
};

template <typename T>
T Metadata<T>::getData() { //returns the data vector without the value names
    return this->data;
}


template <typename T>
void Metadata<T>::setData(T& data) { //sets the data vector, name vector
    this->data = data;
}
#endif