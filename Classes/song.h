/*
    This header file will contain the templated nodes for the linked list.
*/

#ifndef SONG_H
#define SONG_H

#include "../main.h"

template<typename T>
class Song { //this class will hold metadata for each song
    private:
        Song *next, *previous;
        T artist, album, name;
    public:
        T getArtist(); //returns the artist value
        T getAlbum(); //returns the album value
        T getName(); //returns the name value
        Song* getNext(); //gets the next pointer
        Song* getPrevious(); //gets the next pointer

        void setArtist(const T&); //sets the artist value
        void setAlbum(const T&); //sets the album value
        void setName(const T&); //sets the name value
        void setNext(Song*); //sets the next pointer
        void setPrevious(Song*); //gets the next pointer

        //friends
        friend std::ostream& operator<<(std::ostream& os, Song<string>* song) {
            os << song->getArtist() + ',' + song->getName() +','+ song->getAlbum() + "\n" ;
            return os;
        }
};

template <typename T>
T Song<T>::getArtist() { //returns the artist value
    return this->artist;
}

template <typename T>
T Song<T>::getAlbum() { //returns the album value
    return this->album;
}

template <typename T>
T Song<T>::getName() { //returns the name value
    return this->name;
}

template <typename T>
void Song<T>::setArtist(const T& artist) { //sets the artist value
    this->artist = artist;
}

template <typename T>
void Song<T>::setAlbum(const T& album) { //sets the album value
    this->album = album;
}

template <typename T>
void Song<T>::setName(const T& name) { //sets the name value
    this->name = name;
}

template <typename T>
void Song<T>::setNext(Song* next) { //sets the next pointer
    this->next = next;
}

template <typename T>
Song<T>* Song<T>::getNext() { //gets the next pointer
    return this->next;
}

template <typename T>
void Song<T>::setPrevious(Song* previous) { //sets the previous pointer
    this->previous = previous;
}

template <typename T>
Song<T>* Song<T>::getPrevious() { //gets the previous pointer
    return this->previous;
}

#endif