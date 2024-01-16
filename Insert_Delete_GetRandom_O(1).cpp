#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to provide a data structure that allows constant-time insertion,
removal, and retrieval of elements with the added feature of retrieving a random
element. We use a set to ensure uniqueness of elements. The "insert" function adds
a value to the set if it doesn't already exist, the "remove" function removes the
value if it exists, and the "getRandom" function retrieves a random element using
the `rand()` function.
*/

class RandomizedSet
{
    set<int> s;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (s.find(val) != s.end())
            return false;
        s.insert(val);
        return true;
    }

    bool remove(int val)
    {
        if (s.find(val) == s.end())
            return false;
        s.erase(val);
        return true;
    }

    int getRandom()
    {
        return *next(s.begin(), rand() % s.size());
    }
};

int main()
{
    return 0;
}