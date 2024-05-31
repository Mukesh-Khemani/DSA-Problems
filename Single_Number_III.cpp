#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem of finding two unique numbers in an array where every other number appears
exactly twice can be efficiently solved using bit manipulation. By XORing all the numbers,
we can isolate the combined XOR of the two unique numbers, which helps in identifying a
bit position where these two numbers differ. Using this differing bit, we can partition
the numbers into two groups: one group where numbers have a 0 in this bit position and the
other where numbers have a 1. XORing the numbers within each group will cancel out the
duplicate numbers, leaving us with the two unique numbers.
*/

class Solution
{
public:
    static vector<int> singleNumber(vector<int> &nums)
    {
        int xorResult = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
        int bitPosition = 31;

        while (((xorResult >> bitPosition) & 1) == 0)
            bitPosition--;

        int num1 = 0, num2 = 0;

        for (int num : nums)
        {
            if (((num >> bitPosition) & 1) == 0)
                num1 ^= num;
            else
                num2 ^= num;
        }

        return {num1, num2};
    }
};

int main()
{
    return 0;
}