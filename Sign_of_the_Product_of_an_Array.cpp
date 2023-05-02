#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We are given an integer array nums. We need to return
-> 1 if x is positive.
-> -1 if x is negative.
-> 0 if x is equal to 0.

Solution:
- As we are only concerned by the sign of the product and not the
magnitude, we can keep a track of the negative elements of the array.
- If the negative elements are odd, we will return '-1' and
'1' for even negative numbers.
- Also the product will be zero if any element of the array is zero.
*/

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int lessThanZero = 0;
        for (int i : nums)
        {
            if (i < 0)
                lessThanZero++;
            else if (i == 0)
                return 0;
        }
        return lessThanZero % 2 ? -1 : 1;
    }
};

int main()
{
    return 0;
}