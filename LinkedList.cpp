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
    Entry(Value value): val(value), next_entry(nullptr){}
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
  // new node with associated value
  Entry* elem= new Entry(value); 
  // set value and old head
  elem->next_entry = head_;
  // make new node entry the new head
  head_ = elem;
};

// begin()
// return an iterator at the head of the list

LinkedList::Iterator LinkedList::begin()
{
  return Iterator(head_);
};

// end()
// return an iterator at the end of the list

LinkedList::Iterator LinkedList::end()
{
  return Iterator(nullptr);
};

// Iterator constructor for class Linked List
LinkedList::Iterator::Iterator(Entry *value)
{
  entry_ = value;
};

// Iteartor comparison (equal) operator
bool LinkedList::Iterator::operator==(const Iterator &other)
{
  return entry_ == other.entry_;
};

// Iterator comparison (not equal) operator

bool LinkedList::Iterator::operator!=(const Iterator &other)
{
  return entry_ != other.entry_;
};

// Iterator prefix next (++) operator
LinkedList::Iterator& LinkedList::Iterator::operator++()
{
  if (entry_)
  {
    entry_ = entry_->next_entry;
  }
  return *this;
};

// Iterator dereference (*) operator
LinkedList::Value& LinkedList::Iterator::operator*()
{
  return entry_->val;
};

// Iterator arrow (->) operator
LinkedList::Value* LinkedList::Iterator::operator->()
{
  return &entry_->val;
};