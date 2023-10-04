#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind this problem is to implement a basic hash map using
an array of fixed size (1000001) for simplicity. The 'MyHashMap' class
initializes the array, and each index represents a key in the hash map.
The values in the array are initialized to -1, indicating that the
corresponding keys are not present. The 'put' method assigns a value to a
specific key by updating the array at the corresponding index. The 'get'
method retrieves the value associated with a given key, and the 'remove'
method sets the value for the key to -1, effectively removing it from the
hash map.
*/

class MyHashMap
{
    int hashmap[1000001];

public:
    MyHashMap()
    {
        for (int i = 0; i < 1000001; i++)
            hashmap[i] = -1;
    }

    void put(int key, int value)
    {
        hashmap[key] = value;
    }

    int get(int key)
    {
        return hashmap[key];
    }

    void remove(int key)
    {
        hashmap[key] = -1;
    }
};

int main()
{
    return 0;
}