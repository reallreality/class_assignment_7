/*********************
* Michael Johan Rupprecht
* COSC-2436-002
* An exemplification of hashtables through a basic integer input and output
**********************/

#ifndef HASHTABLE_CPP_FILE
#define HASHTABLE_CPP_FILE

#include "hashtable.h"


//Hash Constructor
HashTable::HashTable() {

    count = 0;

    for (int i = 0; i < HASHTABLESIZE; i++) {

        hashArray[i] = new LinkedList();           //Created linkedlist objects in each of the array elements
        
    }

}


// //Insert Entry method seems to be working correctly
bool HashTable::insertEntry(int idInput, string *stringInput) {

    bool added = false; //Flag used to denote if an entry was successfully added or not

    int position = hash(idInput);   //Hashing the id in order to find where to place in array

    if (idInput > 0 && *stringInput != "") {

        LinkedList exist;

        if (!(hashArray[position]->exists(idInput))) {

            count++;

        }
        
        // count++;

        hashArray[position]->addNode(idInput, stringInput);

        added = true;
   
    }

    return added;
}



// //getData method
string HashTable::getData(int searchId) {

    string exists = "";

    int position = hash(searchId);

    if (searchId > 0) {
    
        if (hashArray[position]->exists(searchId)) {

            Data receiver;

            hashArray[position]->getNode(searchId, &receiver);

            exists = receiver.data;

        }
    }

    return exists;
    
}


//getCount method
int HashTable::getCount() {

    return count;

}


//removeEntry method
bool HashTable::removeEntry(int removeId) {

    bool removed = false;

    int position = hash(removeId);


    if (removeId > 0) {
    
        if (hashArray[position]->exists(removeId)) {

            hashArray[position]->deleteNode(removeId);

            removed = true;

            count--;
        }

    }

    return removed;

}


//printTable method
void HashTable::printTable() {

    bool direction = false;

    for (int i = 0; i < HASHTABLESIZE; i++) {

        cout << "Entry " << (i + 1) << ": "; 
        hashArray[i]->printList(direction);
    }


}


//Hash method
int HashTable::hash(int POSITION) {

    return (POSITION % HASHTABLESIZE);

}




#endif //HASHTABLE_CPP_FILE