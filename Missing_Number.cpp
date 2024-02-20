#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problemn aims to find the missing number in an array of integers.
We leverage the arithmetic sum formula to calculate the expected sum
of all numbers from 0 to nums.size(). By subtracting each element of
the input array nums from this expected sum, we identify the missing
number. The final result represents the difference between the
expected sum and the actual sum of elements in the array.
*/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int x = nums.size() * (nums.size() + 1) / 2;
        for (int i : nums)
            x -= i;
        return x;
    }
};

int main()
{
    return 0;
}