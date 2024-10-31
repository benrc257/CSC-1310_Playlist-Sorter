/*
    This file will contain the function definitions for the metadata class.
*/

#include "metadata.h"


template <typename T>
T Metadata<T>::getData() { //returns the data vector without the value names
    return this->data;
}


template <typename T>
void Metadata<T>::setData(T data) { //sets the data vector, name vector
    this->data = data;
}
