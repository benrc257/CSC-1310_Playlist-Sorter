/*
    This file will contain the function definitions for the metadata class.
*/

#include "metadata.h"

template <typename T>
vector<T> Metadata<T>::getData(vector<string>& names) { //returns the data vector and modifies the given vector with the value name data
    
    names.resize(0); //clears name vector

    for (int i = 0; i < this->data.size(); i++) { //sets names equal to valueName
        names[i] = this->valueName[i];
    }

    return data; //returns the data vector

}


template <typename T>
vector<T> Metadata<T>::getData() { //returns the data vector without the value names
    return this->data;
}


template <typename T>
void Metadata<T>::setData(vector<T> inputData, vector<string> inputNames) { //sets the data vector, name vector

    this->data.resize(0); //clears data vector
    this->valueName.resize(0); //clears name vector

    for (int i = 0; i < inputData.size() && i < inputNames.size(); i++) { //sets data and valueName equal to inputNames and inputData
        this->data[i] = inputData[i];
        this->valueName[i] = inputNames[i];
    }

}


template <typename T>
void Metadata<T>::push(T input, string name) { //pushes data value, value name
    this->data.push(input);
    this->valueName.push(name);
}


template <typename T>
T Metadata<T>::pop(string name) { //used for popping by value name

    for (int i = 0; i < this->valueName.size() && i < this->data.size(); i++) { //runs for the length of valueName and data
        if (name == this->valueName[i]) { //if name is found in valueName, returns the corresponding data point
            return this->data[i];
        }
    }

    return NULL; //returns NULL if the name does not exist
}


template <typename T>
T Metadata<T>::pop(int index) { //used for popping by index number

    if (index < this->data.size()) { //if the index exists, returns the corresponding data point
        return data[i];
    }

    return NULL; //returns NULL if the index does not exist

}