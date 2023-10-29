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

    bool insertEntry(int, std::string*);
	string getData(int);
	bool removeEntry(int);
    int getCount();
    void printTable();

private:
    LinkedList table[HASHTABLESIZE]; 
    int hash(int);
    int count;
};

#endif /* HASHTABLE_H */
