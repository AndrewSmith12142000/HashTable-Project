/* 
 * your comment header here
 */
 
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include <string>

#define HASHTABLESIZE 15

class HashTable {
public:
    HashTable();
    ~HashTable();

    bool insertEntry(int id, std::string* data);
    std::string getData(int id);
    bool removeEntry(int id);
    int getCount();
    void printTable();

private:

};

#endif /* HASHTABLE_H */
