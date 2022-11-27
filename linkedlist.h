/*********************
* Michael Johan Rupprecht
* COSC-2436-002
* Header file for ADT file linkedlist.cpp 
**********************/

//Necessary ifndef and define
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Indcluding needed files
#include "data.h"

#include <iostream>

//LinkedList class prototype
class LinkedList {

    public:

        LinkedList();

        bool addNode(int, string*);

        bool deleteNode(int);

        bool getNode(int, Data*);

        void printList(bool = false);

        int getCount();

        void clearList();

        bool exists(int);


    private:

        Node *head;

        Node* allocateNode(int, string*);       //Private method created


};


#endif  //End of header file definition