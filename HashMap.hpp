#ifndef HW1_HASH_MAP_HPP
#define HW1_HASH_MAP_HPP

#include "LinkedList.hpp"
#include <string>
#include <utility>

class HashMap
{
  public:
    using Key = std::string;
    using Value = std::int32_t;
    using Pair = std::pair<const Key, Value>;
    using Size = std::size_t;
    class Iterator;

  private:
    /**
     * Number of elements in the map.
     */
    Size size_;
    /**
     * The pointer to the array of buckets.
     */
    LinkedList *buckets_;
    /**
     * The number of allocated buckets (one smaller than the actual buckets_
     * array size due to the extra bucket).
     */
    Size buckets_size_;

  public:
    HashMap();
    ~HashMap();

    /**
     * Get a reference to the value for the given key. Inserts the key with a
     * default value if it's not in there yet.
     */
    Value &operator[](const Key &key);

    Iterator begin();
    Iterator end();

    /**
     * Inserts a key-value-pair into the map, if it doesn't exist yet. The
     * return value will yield an iterator to the key-value-pair with the same
     * key as the parameter pair. If the boolean is true, a new pair was inserted,
     * if it is false, the iterator references the existing pair.
     */
    std::pair<Iterator, bool> insert(const Pair &pair);

    Iterator find(const Key &key);

  private:
    void initialize_storage(Size buckets_size);
    LinkedList &get_bucket(const Key &key);
};

class HashMap::Iterator
{
    LinkedList *bucket_;
    LinkedList::Iterator entry_;

  public:
    Iterator(LinkedList *bucket, LinkedList::Iterator entry);

    bool operator==(const Iterator &other);
    bool operator!=(const Iterator &other);

    Iterator &operator++();

    Pair &operator*();
    Pair *operator->();
};

#endif