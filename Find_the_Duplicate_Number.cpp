#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind this problem is to identify a duplicate number efficiently
within an array by marking visited elements using negative values. We iterate
through the array, calculate the absolute value of each element to ensure a
valid index, and check if the element at that index is already marked as visited
(negative). If it is, we return the absolute value of the current element,
indicating the duplicate. If not, we mark the element as visited by negating
its value.
*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int num : nums)
        {
            int index = abs(num);
            if (nums[index] < 0)
                return index;
            nums[index] = -nums[index];
        }
        return -1;
    }
};

int main()
{
    return 0;
}