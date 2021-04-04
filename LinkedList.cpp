/*
LinkedList.cpp
Author: Jason Nguyen
Date: April 7 2021
*/

#include "LinkedList.hpp"
#include <iostream>

// Entry struct
struct LinkedList::Entry
{
    Value value;
    Entry* next_entry;
};

// Constructor
LinkedList::LinkedList()
{
    head_ = nullptr;
};

// Destructor
LinkedList::~LinkedList()
{
   Entry* curr = head_;
   while(curr != nullptr)
   {
     Entry* next = curr->next_entry;
     delete curr;
     curr = next;
   }
};
