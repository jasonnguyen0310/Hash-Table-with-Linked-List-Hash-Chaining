#ifndef HW1_LINKED_LIST_HPP
#define HW1_LINKED_LIST_HPP

#include <string>
#include <utility>

class LinkedList
{
    /**
     * An entry is a struct containing a value and a next pointer. Defined
     * in LinkedList.cpp.
     */
    struct Entry;

  public:
    using Value = std::pair<const std::string, int32_t>;
    class Iterator;

  private:
    Entry *head_;

  public:
    LinkedList();
    ~LinkedList();

    Iterator begin();
    Iterator end();

    /**
     * Adds a value to the front of the list.
     */
    void push_front(const Value &value);
};

class LinkedList::Iterator
{
    Entry *entry_;

  public:
    explicit Iterator(Entry *value);

    bool operator==(const Iterator &other);
    bool operator!=(const Iterator &other);

    Iterator &operator++();

    Value &operator*();
    Value *operator->();
};

#endif /* LINKEDLIST_H_ */