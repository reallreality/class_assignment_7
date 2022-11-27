/*********************
* Michael Johan Rupprecht
* COSC-2436-002
* Main.cpp file
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;


  
    //TESTING INSERTENTRY METHOD

    HashTable hash1;

    cout << "Trying insertEntry: " << hash1.insertEntry(ids[1], &strs[1]) << " - just finished trying method." << endl;

    cout << "Trying insertEntry: " << hash1.insertEntry(ids[2], &strs[2]) << " - just finished trying method." << endl;

    cout << "Trying insertEntry: " << hash1.insertEntry(ids[3], &strs[3]) << " - just finished trying method." << endl;

    cout << endl << endl;


    //TESTING PRINTLIST METHOD

    cout << "Trying printList: " << endl;

    hash1.printTable();

    cout << endl << endl << endl;

    //TESTING GETCOUNT METHOD

    cout << "Trying getCount: " << hash1.getCount() << " - just finished trying method." << endl << endl << endl;


    //TESTING GETDATA METHOD

    cout << "Trying getData: " << hash1.getData(ids[3]) << " - just finished trying method." << endl << endl << endl;


    //TESTING REMOVEENTRY METHOD

    cout << "Trying removeEntry: " << hash1.removeEntry(ids[1]) << " - just finished trying method." << endl;


    cout << "Trying removeEntry: " << hash1.removeEntry(ids[2]) << " - just finished trying method." << endl;


    cout << "Trying removeEntry: " << hash1.removeEntry(ids[3]) << " - just finished trying method." << endl << endl << endl;


    //CALLING GETCOUNT AGAIN
    
    cout << "Trying getCount again: " << hash1.getCount() << " - just finished trying method." << endl << endl << endl;


    
    std::cout << "Now going to use a switch statement block to randomly call various HashTable methods:" << std::endl << std::endl;


    //Switch statment to randomly execute various methods
    for (int switchExecute = 0; switchExecute < EXECUTIONS; switchExecute++) {

        //Random int generator to select a case from 0-4
        int switchSelection = std::rand() % SWITCHSTATEMENTAMOUNT;

        //Switch statement block head
        switch (switchSelection) {

            case 0:

                std::cout << std::endl << "\nSwitch case 1 entered. This case inserts entries, shows if it was successful or not, shows how many entries there are total, then calls printTable." << std::endl << std::endl;

                for (int i = 0; i < testdatasize; i++) {

                    std::cout << "Inserting: " << ids[i];

                    if (hash1.insertEntry(ids[i], &strs[i])) {

                        std::cout << " - Entry inserted successfully. There are " << hash1.getCount() << " entries currently." << std::endl;

                    }

                    else {

                        std::cout << " - Table is likely full. Entry not inserted. There are still " << hash1.getCount() << " entries." << std::endl;

                    }

                }

                std::cout << std::endl << "\nNow printing table: " << std::endl;
                
                hash1.printTable();


                break;

            case 1:

                std::cout << std::endl << "\nSwitch case 2 entered. This case removes entries, shows if it was successful or not, shows the number of entries left, then calls printTable." << std::endl << std::endl;

                for (int i = 0; i < testdatasize; i++) {

                    std::cout << "Removing " << ids[i] << ": ";

                    if (hash1.removeEntry(ids[i])) {

                        std::cout << " - Entry successfully removed. There are " << hash1.getCount() << " entries left." << std::endl;

                    }

                    else {

                        std::cout << " - Table is likely empty. No entry removed. There are still " << hash1.getCount() << " entries." << std::endl;

                    }

                }

                std::cout << std::endl << "\nNow printing table: " << std::endl;

                hash1.printTable();

                break;

            case 2:

                std::cout << std::endl << "\nSwitch case 3 entered. This retreives the string associated with an id entry." << std::endl << std::endl;


                for (int i = 0; i < testdatasize; i++) {

                    std::cout << "Retreiving string associated with: " << ids[i] << " - " << hash1.getData(ids[i]) << std::endl;

                }

                break;
                
        }
    }

    
    return 0;
}
