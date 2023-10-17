/*
 Name: Andrew Smith
 Coding 05
 Purpose: This file is for the includes and class LinkedList
 File: functions.h
 *
 */
#ifndef LINKED_LIST_h
#define LINKED_LIST_h

# include "data.h"
# include <iomanip>
# include <string>
# include <stdlib.h>
# include <iostream>
# include <new>

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
  
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);
    

private:
	Node *head;
    bool nodeCouple(bool, int, string*, Node*, Node*);
    bool deleting(Node*);
};

# endif