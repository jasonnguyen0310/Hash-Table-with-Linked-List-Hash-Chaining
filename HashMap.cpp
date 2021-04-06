/*
HashMap.cpp
Author: Jason Nguyen
Date: April 7 2021
*/

#include "HashMap.hpp"

// Constructor
HashMap::HashMap()
{
    size_ = 0;
    buckets_size_ = 7;
    initialize_storage(7);
};

// Destrutor
HashMap::~HashMap()
{
    delete[] buckets_;
};


// allocate array of lists dynamically
void HashMap::initialize_storage(Size buckets_size)
{
    buckets_ = new LinkedList;
    Pair dummy_entry = Pair("dummy", 0);
    buckets_->push_front(dummy_entry);
    for (Size i = 0; i < buckets_size + 1; i++)
    {
        Pair entry = Pair(NULL,NULL);
        buckets_->push_front(entry);
    }
    // default: 9 entries, 1 dummy, 1 extra, 7 real

};

// end iterator has pointer to the extra bucket that was allocated
LinkedList& HashMap::get_bucket(const Key &key)
{

};


// iterator constructor
HashMap::Iterator::Iterator(LinkedList *bucket, LinkedList::Iterator entry)
{
    while(bucket->begin() == bucket->end())
    {
        bucket++;
    }
};

// begin iterator has a pointer to the first bucket
HashMap::Iterator HashMap::begin()
{
    return Iterator(buckets_, buckets_->begin());
};

// end iterator has pointer to the extra bucket that was allocated
HashMap::Iterator HashMap::end()
{
    for (Size i = 0; i < buckets_size_ + 1; i++)
    {
        if (i == buckets_size_)
        {
            return Iterator(buckets_, buckets_->begin());
        }
        buckets_++;
    }
    return Iterator(buckets_, buckets_->begin());
};


