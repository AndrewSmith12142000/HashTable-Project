/*
 Name: Andrew Smith
 Coding 06
 Purpose: This file test for hashtables
 File: main.h
 *
 */

#include "main.h"
#include "hashtable.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
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

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    
    // show it is empty by calling getCount and printTable
    
    // try and put ALL the test data into the table and show what happens

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

       cout << "\n------------ Testing Empty Hash Table ------------\n";

    HashTable hashTable;
    cout << "\nHash Table Count: " << hashTable.getCount() << "\n";
    hashTable.printTable();

 
    cout << "\n---------------Inserting Test Data-------------------\n";
    for (int i = 0; i < testdatasize; i++) {
        cout << "Inserting " << ids[i] << " : " << strs[i];
        if (hashTable.insertEntry(ids[i], &strs[i])) {
            cout << " Insert success!";
        } else {
            cout << " Insert failed.";
        }
        cout << endl;
    }

    
    cout << "\n-------------Hash Table Output After Inserting----------------------\n";
    hashTable.printTable();

    
    cout << "\n-------------Testing to Remove Random Entries----------------------\n";
    int removeidOne = ids[testdatasize / 2]; 
    int removeidTwo = ids[testdatasize / 4];
    cout << "\nRemoving IDs: " << removeidOne << " and " << removeidTwo << endl;
    hashTable.removeEntry(removeidOne);
    hashTable.removeEntry(removeidTwo);

    
    cout << "\n----------Hash Table Output After Removal----------\n";
    hashTable.printTable();


    cout << "\n-----Retrieving Data from the Table----------\n";
    cout << "\nRetrieving data for ID " << ids[3] << ": ";
    cout << hashTable.getData(ids[3]) << endl;

    cout << "\nRetrieving data for ID " << ids[5] << ": ";
    cout << hashTable.getData(ids[5]) << endl;

    
    cout << "\n-------Test Boundary---------\n";
    int invalidId = -10;
    cout << "Inserting invalid ID " << invalidId << ": ";
    if (hashTable.insertEntry(invalidId, &strs[0])) {
        cout << "Insertion successful (unexpected)!";
    } else {
        cout << "Insertion failed (expected).";
    }
    cout << endl;

    cout << "Inserting duplicate ID " << ids[testdatasize-2] << ": ";
    if (hashTable.insertEntry(ids[testdatasize-2], &strs[testdatasize-2])) {
        cout << "Insertion successful (unexpected)!";
    } else {
        cout << "Insertion failed (expected).";
    }
    cout << endl;


    cout << "\n-------------Final Hash Table------------\n";
    hashTable.printTable();
   
    return 0;
}
