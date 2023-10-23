/* 
 * your comment header here
 */
 
#include "hashtable.h"

HashTable::HashTable() {
    
}

HashTable::~HashTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        table[i].clearList();
    }
}

bool HashTable::insertEntry(int id, std::string* data) {
    if (id <= 0 || data == nullptr || data->empty()) {
        return false; 
    }

    int index = hash(id);
    if (table[index].exists(id)) {
        return false; 
    }

    Data entry;
    entry.id = id;
    entry.data = *data;
    table[index].addNode(id, &entry.data);

    return true;
}