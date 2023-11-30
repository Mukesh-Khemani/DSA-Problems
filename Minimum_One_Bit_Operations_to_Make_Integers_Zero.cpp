#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We employ bitwise XOR operations to iteratively reduce the number
of set bits in n by dividing the bits into groups and XORing them.
The XOR operations essentially simulate the process of flipping
bits and contribute to the cumulative count of operations.
*/

class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int res = n;
        res ^= res >> 16;
        res ^= res >> 8;
        res ^= res >> 4;
        res ^= res >> 2;
        res ^= res >> 1;
        return res;
    }
};

int main()
{
    return 0;
}