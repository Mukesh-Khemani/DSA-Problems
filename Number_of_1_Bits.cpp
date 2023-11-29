#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We use a bitwise AND operation with n and (n-1) inside a loop to continuously
clear the least significant set bit in n until n becomes 0. With each iteration,
the variable bitCount is incremented, keeping track of the number of set bits
encountered. The approach is based on the principle that performing n & (n-1)
effectively removes the rightmost set bit, allowing us to count set
bits in a time complexity proportional to the number of set bits rather than the
overall bit length of n.
*/

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int bitCount = 0;
        while (n != 0)
        {
            n &= (n - 1);
            bitCount++;
        }
        return bitCount;
    }
};

int main()
{
    return 0;
}