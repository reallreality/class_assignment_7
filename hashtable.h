/*********************
* Michael Johan Rupprecht
* COSC-2436-002
* Header file for hashtable.cpp
**********************/

#ifndef HASHTABLE_H_FILE
#define HASHTABLE_H_FILE

#define HASHTABLESIZE 15

#include "main.h"
#include "linkedlist.h"

//HashTable class prototype
class HashTable {

    public:

        HashTable();

        // ~HashTable();
    
        bool insertEntry(int, string*);

        string getData(int);

        bool removeEntry(int);

        int getCount();

        void printTable();

    private:
    
        int hash(int);

        LinkedList *hashArray[HASHTABLESIZE];

        int count;

};

#endif //HASHTABLE_H_FILE