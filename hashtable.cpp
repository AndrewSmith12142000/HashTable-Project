/* 
 * your comment header here
 */
 
#include "hashtable.h"

HashTable::HashTable() {
    // Initialize the hash table with linked lists
}

HashTable::~HashTable() {
    // Destructor to clean up resources
    for (int i = 0; i < HASHTABLESIZE; i++) {
        table[i].clearList();
    }
}

bool HashTable::insertEntry(int id, std::string* data) {
    if (id <= 0 || data == nullptr || data->empty()) {
        return false; // Reject bad IDs or strings
    }

    int index = hash(id);
    if (table[index].exists(id)) {
        return false; // ID must be unique
    }

    Data entry;
    entry.id = id;
    entry.data = *data;
    table[index].addNode(id, &entry.data);

    return true;
}

string HashTable::getData(int id) {
    int index = hash(id);
    Data entry;

    if (table[index].getNode(id, &entry)) {
        return entry.data;
    } else {
        return ""; // Return an empty string if the id does not exist
    }
}

bool HashTable::removeEntry(int id) {
    int index = hash(id);
    if (table[index].deleteNode(id)) {
        return true;
    }
    return false; // Entry not found
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

