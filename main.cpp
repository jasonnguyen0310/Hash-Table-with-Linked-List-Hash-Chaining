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
    HashMap h;
    string word;
    while(cin >> word)
    {
        h[word];
    }

    for (auto it = h.begin(); it != h.end(); ++it)
    {
        cout << it->first << "  -  " << it->second;
    }
    return 0;
}
