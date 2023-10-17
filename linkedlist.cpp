/*
 Name: Andrew Smith
 Coding 05
 Purpose: This file represents the linked list
 File: linkedlist.cpp
 *
 */

#include "linkedlist.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList()
{
    this->clearList();
}


bool LinkedList::nodeCouple(bool success, int id, string* data, Node* current, Node* newNode)
{
    if (id > current->data.id && !current->next)
    {
        current->next = newNode;
        newNode->prev = current;
    }
    else if (id < current->data.id && !current->prev)
    {
        current->prev = newNode;
        newNode->next = current;
        head = newNode;
    }
    else
    {
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
    }
    return true;
}

bool LinkedList::addNode(int id, string* data)
{
    bool success = false;

    bool createNode = false;
    bool createHead = false;

	Node* current = head;
    Node* newNode;

    if (id > 0 && !head)
    {
        createNode = true;
        createHead = true;
    }
    else if (id > 0 && head)
    {
        while (current->next && id > current->data.id)
        {
            current = current->next;
        }

        if (id != current->data.id)
        {
            createNode = true;
        }
    }

    if (createNode)
    {
        newNode = new Node;
        newNode->data.id = id;
        newNode->data.data = *data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

		if (createHead)
		{
			head = newNode;
			success = true;
		}
		else
		{
			success = nodeCouple(success, id, data, current, newNode);
		}
    }
    return success;
}

bool LinkedList::deleteNode(int id)
{
    bool success = false;
    if (id > 0 && head)
    {
        Node* current = head;

        while (current && !(id == current->data.id))
        {
            current = current->next;
        }

        if (current && id == current->data.id)
        {
            success = deleting(current);
        }
    }
    return success;
}

bool LinkedList::deleting(Node* current)
{
    if (!current->next && !current->prev)
    {
        head = nullptr;
    }
    else if (!current->prev)
    {
        head = current->next;
        current->next->prev = nullptr;
    }
    else if (!current->next)
    {
        current->prev->next = nullptr;
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    delete current;
    return true;
}

bool LinkedList::getNode(int id, Data* data)
{
    bool success = false;
    if (id > 0 && head)
    {
        Node* current = head;

        while (current && !(id == current->data.id))
        {
            current = current->next;
        }

        if (current && id == current->data.id)
        {
            data->id = current->data.id;
            data->data = current->data.data;
            success = true;
        }
    }
    return success;
}

void LinkedList::printList(bool backward)
{
    if (head == nullptr)
    {
        std::cout << "Empty List" << std::endl;
    }
    else
    {
        if (!backward)
        {
            Node* temp = head;
            while (temp)
            {
                std::cout << temp->data.id << ": " << temp->data.data << std::endl;
                temp = temp->next;
            }
        }
        else
        {
            Node* temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            while (temp)
            {
                std::cout << temp->data.id << ": " << temp->data.data << std::endl;
                temp = temp->prev;
            }
        }
    }
}

int LinkedList::getCount()
{
    int count = 0;
    Node* current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

bool LinkedList::clearList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = nullptr;
    return true;
}

bool LinkedList::exists(int id)
{
    Node* current = head;
    while (current != nullptr)
    {
        if (current->data.id == id)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}