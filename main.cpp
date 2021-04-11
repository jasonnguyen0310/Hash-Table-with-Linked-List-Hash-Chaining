/*
main.cpp
Author: Jason Nguyen
Date: April 7 2021
*/

// Implement frequency counting

#include "HashMap.hpp"
#include <iostream>
using namespace std;

int main()
{
    // declare HashMap
    HashMap h;

    string word;

    while(cin >> word)
    {
        // inserts word into hashmap
        h[word];
        // increment by 1
        h[word] += 1;
    }

    for (auto it = h.begin(); it != h.end(); ++it)
    {
        cout << (*it).first << "  -  " << (*it).second << endl;
    }

    return 0;
}
