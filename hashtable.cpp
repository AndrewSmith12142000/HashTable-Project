/*
 Name: Andrew Smith
 Coding 06
 Purpose: Create the hashtable for linkedlist
 File: hashtable.cpp
 *
 */
 
#include "hashtable.h"

HashTable::HashTable() : count(0) {
    
}

HashTable::~HashTable() {

}

bool HashTable::insertEntry(int id, std::string* data) {
    bool result = false;

    if (id > 0 && data && !data->empty()) {
        int index = hash(id);
        if (table[index].addNode(id, data)) {
            ++count; // Increment count when an entry is added
            result = true;
        }
    }

    return result;
}


string HashTable::getData(int id) {
    int index = hash(id);
    Data entry;
    string result = "";

    if (table[index].getNode(id, &entry)) {
        result = entry.data;
    }

    return result;
}


bool HashTable::removeEntry(int id) {
    int index = hash(id);
    bool success = false;

    if (table[index].deleteNode(id)) {
        success = true;
    }

    return success;
}

int HashTable::getCount() {
    int count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        count += table[i].getCount();
    }
    return count;
}

void HashTable::printTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        std::cout << "Entry " << i + 1 << ": ";
        if (table[i].getCount() == 0) {
            std::cout << "EMPTY";
        } else {
            table[i].printList();
        }
        std::cout << std::endl;
    }
}

int HashTable::hash(int id) {
    return id % HASHTABLESIZE;
}
