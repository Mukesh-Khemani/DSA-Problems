#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the problem is to determine whether a given array
of integers is monotonic, meaning it is either entirely non-increasing
or non-decreasing. So we employ two boolean flags, 'ascending' and
'descending,' initialized as true, and iterate through the array,
comparing adjacent elements. If we encounter a decreasing sequence
(nums[i] > nums[i-1]), we set 'ascending' to false, and if we encounter
an increasing sequence (nums[i] < nums[i-1]), we set 'descending' to false.
If at any point both flags are false, the array is not monotonic, and we
return false. Otherwise, we return true, indicating that the array is monotonic.
*/

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool ascending = true;
        bool descending = true;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                descending = false;
            else if (nums[i] < nums[i - 1])
                ascending = false;
            if (!ascending and !descending)
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}