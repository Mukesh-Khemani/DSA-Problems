#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this problem, we need to find if the target element exists in the rotated
sorted array in O(log n) time. All these hints suggest to use a binary search approach.
*/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;

            // if the left half is sorted
            if (nums[low] <= nums[mid])
            {
                // if the target element does not exists in right half
                if (nums[low] <= target and target <= nums[mid])
                    high = mid - 1;

                // if the target element does not exists in left half
                else
                    low = mid + 1;
            }
            // if the right half is sorted
            else
            {
                // if the target element does not exists in left half
                if (nums[mid] <= target and target <= nums[high])
                    low = mid + 1;

                // if the target element does not exists in right half
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}