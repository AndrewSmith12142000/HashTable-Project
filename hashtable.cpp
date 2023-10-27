/*
 Name: Andrew Smith
 Coding 06
 Purpose: Create the hashtable for linkedlist
 File: hashtable.cpp
 *
 */
 
#include "hashtable.h"

HashTable::HashTable() {
    
}

HashTable::~HashTable() {

}

bool HashTable::insertEntry(int id, std::string* data) {
    bool result = false;

    if (id > 0 && data != nullptr && !data->empty()) {
        int index = hash(id);
        if (!table[index].exists(id)) {
            table[index].addNode(id, data);
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
    if (table[index].deleteNode(id)) {
        return true;
    }
    return false;
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
