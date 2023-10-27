/*
 Name: Andrew Smith
 Coding 06
 Purpose: This file support the file to hashtable.cpp
 File: hashtable.h
 *
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
    LinkedList table[HASHTABLESIZE]; 
    int hash(int id);
};

#endif /* HASHTABLE_H */
