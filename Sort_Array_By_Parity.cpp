#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the problem is to sort an array of integers by parity,
where even numbers come before odd numbers. To achieve this, we utilize a
two-pointer approach, where one pointer ('prev') keeps track of the position
where the next even number should be placed, and another pointer ('i') iterates
through the array. When an even number is encountered, it is swapped with the
element at the 'prev' position, effectively moving all even numbers to the front
of the array while maintaining their relative order. As a result, the array
becomes sorted by parity.
*/

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int prev = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                swap(nums[prev], nums[i]);
                prev++;
            }
        }
        return nums;
    }
};

int main()
{
    return 0;
}