# Hash Table with Linked List Hash Chaining in C++

This version of the Hash Table with Linked List Hash Chaining is written using [C++](https://www.cplusplus.com/).

## What is a hash-table?

A hash table is used to fetch, add and remove an element in constant time.

Every hash-table store data in the form of a (key, value) combination. Interestingly every key is unique in a Hash Table but values can repeat which means values can be the same for different keys present in it. Now as we observe in an array to fetch a value we provide the position/index corresponding to the value in that array. In a Hash Table, instead of an index, we use a key to fetch the value corresponding to that key.

Every time a key is generated. The key is passed to a hash function. Every hash function has two parts a Hash code and a Compressor. 

Hash code is an Integer number (random or non-random). We will use the hash code generated by our hash function and compress the hash code we modulo(%) the hash code by the size of the hash table. So modulo operator is a compressor in our implementation.

The entire process ensures that for any key, we get an integer position within the size of the Hash Table to insert the corresponding value.

So the process is simple, the user gives a (key, value) pair set as input, and based on the value generated by the hash function an index is generated to where the value corresponding to the particular key is stored. So whenever we need to fetch a value corresponding to a key, that is just O(1).

## Hash Collisions

This picture stops being so rosy and perfect when the concept of a hash collision is introduced. Imagine for different key values same block of the hash table is allocated now where do they previously store values corresponding to some other previous key go. We certainly can’t replace it. That will be disastrous! To resolve this issue we will use the Separate Chaining Technique, Please note there are other open addressing techniques like double hashing and linear probing whose efficiency is almost the same as that of separate chaining.

Now what we do is make a linked list corresponding to the particular bucket of the Hash Table, to accommodate all the values corresponding to different keys that map to the same bucket. 


## Load Factor

If n be the total number of buckets we decided to fill initially say 10 and let’s say 7 of them got filled now, so the load factor is 7/10=0.7. 

In our implementation whenever we add a key-value pair to the Hash Table we check the load factor if it is greater than 0.7 we double the size of our hash table.


## Citation

All explanations above are provided by GeeksForGeeks. 
Link: https://www.geeksforgeeks.org/implementing-our-own-hash-table-with-separate-chaining-in-java/
