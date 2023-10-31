#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The function modifies pref in-place by applying a bitwise XOR operation
between each element and its predecessor in reverse order. This effectively
transforms pref into the original array that generated the given prefix
array through cumulative XOR operations.
*/

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {
        int n = pref.size();
        for (int i = n - 1; i > 0; i--)
            pref[i] ^= pref[i - 1];
        return pref;
    }
};

int main()
{
    return 0;
}