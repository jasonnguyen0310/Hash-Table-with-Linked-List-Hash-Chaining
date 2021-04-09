/*
HashMap.cpp
Author: Jason Nguyen
Date: April 7 2021
*/

#include "HashMap.hpp"
#include <iostream>
using namespace std;

// Constructor
HashMap::HashMap()
{
    // initial size 0
    size_ = 0;
    // allocated size
    buckets_size_ = 0;
    // initialize the HashMap
    initialize_storage(7);
};

// allocate array of lists dynamically
void HashMap::initialize_storage(Size buckets_size)
{
    buckets_size_ = buckets_size;
    buckets_ = new LinkedList[buckets_size + 1]; // dynamically allocates memory for HashMap array
    // 8 entries: 7 real entries, 1 dummy entry

    // adds a dummy entry to this extra list: default values "dummy", 0
    buckets_[buckets_size + 1].push_front(Pair("dummy", 0));
};


// Destrutor
HashMap::~HashMap()
{
    delete [] buckets_;
};


// begin iterator has a pointer to the first bucket
HashMap::Iterator HashMap::begin()
{
    LinkedList *head_of_hashmap = &buckets_[0];
    return Iterator(head_of_hashmap, head_of_hashmap->begin());
};

// end iterator has pointer to the extra bucket that was allocated
HashMap::Iterator HashMap::end()
{
    LinkedList *end_of_hashmap = &buckets_[buckets_size_ + 1];
    return Iterator(end_of_hashmap, end_of_hashmap->begin());
};

// get_bucket
LinkedList& HashMap::get_bucket(const Key &key)
{
    Size hash = 14695981039346656037ull;
    for(std::string::const_iterator it = key.begin(), end = key.end(); it != end; ++it)
    {
        hash ^= *it;
        hash *= 1099511628211;
    }

    return buckets_[hash % buckets_size_];
};

// find
HashMap::Iterator HashMap::find(const Key &key)
{
    // obtain bucket the key is in
    LinkedList& bucket = get_bucket(key);
    // pointer to the bucket that key is in
    LinkedList *pointer_to_bucket = &bucket;

    // iterates through bucket to find key
    for (LinkedList::Iterator it= bucket.begin(); it != bucket.end(); ++it)
    {
        // test_key: deferenced LinkedList pointer which contains a Value
        LinkedList::Value& test_key = *it; 
        // tests the first value which is test_key.first against the real parameter key
        if (test_key.first == key)
        {
            return Iterator(pointer_to_bucket, it);
        }
    }
    return end();
};

// insert
std::pair<HashMap::Iterator, bool> HashMap::insert(const Pair &pair)
{
    // check before insertion whether there are more than twice as many elements in the map than there are buckets
    Size load_factor = size_ / buckets_size_;

    // deals with reallocation of buckets_
    if (load_factor > 2)
    {
        Size old_size_ = buckets_size_;
        LinkedList* old_buckets_ = buckets_;
        initialize_storage(size_);
        for (int i = 0; i < old_size_; i++)
        {
            buckets_[i] = old_buckets_[i];
        }
        size_ = old_size_;
        delete[] old_buckets_;
    }

    auto it = find(pair.first);
    if (it == end())
    {
        get_bucket(pair.first).push_front(pair);
        size_ += 1;
        return std::make_pair(it, true); 
    }
    else
    {
        return std::make_pair(it, false);
    }
};

// operator [] (indexing)
// work on this
HashMap::Value& HashMap::operator[](const Key &key)
{
    return (*insert(std::make_pair(key, 0)).first).second;
};

// Iterator constructor
HashMap::Iterator::Iterator(LinkedList *bucket, LinkedList::Iterator entry) : entry_(entry)
{
    while (bucket->begin() == bucket->end())
    {
        bucket++;
        entry_ = bucket->begin();
    }
    bucket_ = bucket;
};

// Iteartor equality (==) operator
bool HashMap::Iterator::operator==(const Iterator &other)
{
    return entry_ == other.entry_;
}

// Iteartor equality (!=) operator
bool HashMap::Iterator::operator!=(const Iterator &other)
{
    return entry_ != other.entry_;
}

// Iterator prefix next (++) operator
HashMap::Iterator& HashMap::Iterator::operator++()
{
    bucket_++;
    return *this;
};

// Iterator dereference (*) operator
HashMap::Pair& HashMap::Iterator::operator*()
{
    return *entry_;
}

// Iterator arrow (->) operator
HashMap::Pair* HashMap::Iterator::operator->()
{
    return &*entry_;
};
