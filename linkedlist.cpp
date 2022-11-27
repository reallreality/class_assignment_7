/*********************
* Michael Johan Rupprecht
* COSC-2436-002
* An ADT that exemplifies the conceptual basics of linked lists  
* through implementation. 
**********************/

#include "linkedlist.h"     //Including header file needed

typedef Node* nodePtr;      //Creating a typedef that is used throughout the ADT

//Constructor
LinkedList::LinkedList() {

    head = nullptr;

}


//getNode method
bool LinkedList::getNode(int id, Data *receivingDataStruct) {

    nodePtr current = head;

    bool found = false;

    if (current) {

        while (current) {

            if (id == current->data.id) {

                found = true;

                receivingDataStruct->data = current->data.data;

                receivingDataStruct->id = current->data.id;

                current = current->next;

            }

            else {
                current = current->next;
            }

        }

        if (found != true) {

            receivingDataStruct->data = "";

            receivingDataStruct->id = -1;

        }

    }

    else {

        receivingDataStruct->data = "";

        receivingDataStruct->id = -1;

    }

    return found;

}


//getCount method
int LinkedList::getCount() {

    int count = 0;

    nodePtr current = head;

    if (head) {
    
        while (current) {

            count++;

            current = current->next;
        }

    }

    return count;

}


//printList method
void LinkedList::printList(bool direction) {

    nodePtr current = head;

    if (direction == false) {

        if (current == NULL) {

            std::cout << "Empty" << std::endl;
            
        }

        else {
    
            while (current) {

                std::cout << current->data.id;
                
                if (current->next != NULL) {

                    std::cout << " --> ";

                }

                else {

                    std::cout << std::endl;
                }

                current = current->next;
                
            }


        } 
    }

    
}


//exists method
bool LinkedList::exists(int searchInt) {

    nodePtr current = head;

    bool found = false;

    if (current) {
    
        while (current) {

            if (searchInt == current->data.id) {

                found = true;

            }

            current = current->next;

        }

    }

    return found;


}


//addNode method
bool LinkedList::addNode(int idIn, string *stringIn) {

    bool added = false;     //Variable to show if the addition to the list was successful

    nodePtr current = head;         //Head pointer

    nodePtr adding;     //Will hold node pointer to be added once allocated

    int flagID = idIn;  //Used to break out of while loops

    //Verifying input id is positive and string is not empty
    if (idIn <= 0 or *stringIn == "") {
        added = false;
    }

    else {

        if (!(head)) {      //If list is empty

            //Used to add node to list when list is empty
            LinkedList addingNode;
            adding = addingNode.allocateNode(idIn, stringIn); 
            //Adding node to list
            head = adding;
            adding->prev = NULL;
            adding->next = NULL;
            added = true;

        }

        else {      //If list is NOT empty
            
            while (flagID != current->data.id) {

                if (flagID > current->data.id) {

                    if (current->next == NULL) {

                        LinkedList addingNode;
                        adding = addingNode.allocateNode(idIn, stringIn);
                        //Adding
                        current->next = adding;
                        adding->next = NULL;
                        adding->prev = current;
                        added = true;
                        flagID = current->data.id;

                    }

                    else {

                        if (current->next != NULL) {

                            current = current->next;

                            if (idIn > current->prev->data.id && idIn < current->data.id) {

                                LinkedList addingNode;
                                adding = addingNode.allocateNode(idIn, stringIn);
                                //Adding
                                current->prev->next = adding;
                                adding->next = current;
                                adding->prev = current->prev;
                                current->prev = adding;
                                added = true;
                                flagID = current->data.id;
                            }

                        }

                        else if (current->next == NULL) {                        
                
                            LinkedList addingNode;
                            adding = addingNode.allocateNode(idIn, stringIn);
                            //Adding
                            current->next = adding;
                            adding->next = NULL;
                            adding->prev = current;
                            added = true;
                            flagID = current->data.id;
                            
                        }
                
                    }
                }

                else if (flagID < current->data.id) {

                    if (current->prev == NULL) {
                        LinkedList addingNode;
                        adding = addingNode.allocateNode(idIn, stringIn);
                        //Adding
                        current->prev = adding;
                        adding->next = current;
                        adding->prev = NULL;
                        head = adding;
                        added = true;
                        flagID = current->data.id;

                    }

                    else {

                        if (current->prev != NULL) {

                            current = current->prev;

                            if (idIn < current->data.id && idIn > current->prev->data.id) {

                                LinkedList addingNode;
                                adding = addingNode.allocateNode(idIn, stringIn);
                                //Adding
                                current->prev->next = adding;
                                adding->next = current;
                                adding->prev = current->prev;
                                current->prev = adding;
                                added = true;
                                flagID = current->data.id;
                            }

                        }

                        else if (current->prev == NULL) {                        
                
                            LinkedList addingNode;
                            adding = addingNode.allocateNode(idIn, stringIn);
                            //Adding
                            current->prev = adding;
                            adding->prev = NULL;
                            adding->next = current;
                            head = adding;
                            added = true;
                            flagID = current->data.id;
                            
                        }

                    }
                    
                }

            }
                
             
        }

    }

    

    return added;

}


//deleteNode method
bool LinkedList::deleteNode(int deleteID) {

    nodePtr current = head;

    bool deleted = false;

    if (current && deleteID != -1) {

        while (current) {

            if (deleteID == current->data.id) {

                if (current == head && current->next == NULL) {
                    
                    head = NULL;

                    delete current;

                    deleted = true;

                    current = NULL;

                }

                else if (current == head && current->next != NULL) {

                    head = current->next;

                    delete current;

                    head->prev = NULL;

                    deleted = true;

                    current = NULL;

                }
                
                
                else if (current->prev == head && current->next != NULL) {

                    current->prev->next = current->next;

                    current->next->prev = current->prev;

                    delete current;

                    deleted = true;

                    current = NULL;

                }

                else if (current->prev == head && current->next == NULL) {

                    nodePtr deleteTail = current;

                    current->prev->next = NULL;

                    delete deleteTail;
                }

                else if (current->prev != head && current->next != NULL) {

                    current->prev->next = current->next;

                    current->next->prev = current->prev;

                    delete current;

                    deleted = true;

                    current = NULL;

                }

                else if (current->prev != head && current->next == NULL) {

                    nodePtr deleteTail = current;

                    current = current->prev;

                    delete deleteTail;

                    current->next = NULL;

                    deleted = true;

                    current = NULL;

                }

            }

            else {

                current = current->next;
                    
            }

        }
    
    }
    return deleted;

}


//clearList method
void LinkedList::clearList() {      //Delete backwards

    nodePtr current = head;

    nodePtr tail;

    if (current) {
    
        while (current) {

            if (current->next != NULL) {

                current = current->next;
            }

            else {

                tail = current;

                current = NULL;
                
            }

        }

        current = tail;

        while (tail != NULL) {

            if (tail != head) {

                current = current->prev;

                delete tail;

                tail = current;


            }

            else {

                head = NULL;

                delete current;

                tail = NULL;

            }

        }

    }
    

}


//allocateNode method
Node* LinkedList::allocateNode(int ID, string *INPUT) {         //Private method to allocate and assign node

    nodePtr node = new Node;

    node->data.id = ID;

    node->data.data = *INPUT;

    return node;

}