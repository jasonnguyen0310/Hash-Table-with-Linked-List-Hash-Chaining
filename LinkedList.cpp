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
    Value val;
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
   head_ = nullptr;
};

// push_front (const Value &value)
// adds new element to the start of the list and updates the head pointer

void LinkedList::push_front(const Value &value)
{
  // new node
  Entry* elem= new Entry; 
  // set value and old head
  elem->val = value;
  elem->next_entry = head_;
  // make new node entry the new head
  head_ = elem;
};

