#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the solution, we implement a binary search algorithm tailored for rotated sorted arrays that might
contain duplicates. We maintain two pointers, low and high, representing the current search range.
In each iteration, we calculate the middle index mid and check if the target value is at mid, low, or high.
If found, we return true. We handle cases where elements at low and high are equal (indicating duplicates)
by incrementing low. The algorithm then determines if the left or right half of the current range is sorted,
based on comparisons with nums[low] and nums[mid]. Depending on this, we update the pointers to search in
the sorted half where the target might reside.
*/

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target or nums[low] == target or
                nums[high] == target)
                return true;
            if (nums[low] == nums[high])
            {
                low++;
                continue;
            }
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target and target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if (nums[mid] <= target and target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}