#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind this problem is a binary search-based approach to find the range
of indices for a target element in a sorted array. We use a helper function `binarySearch`
to perform binary search either for the leftmost or rightmost occurrence of the target
element. The main function `searchRange` calls this helper function twice, once for the
leftmost occurrence and once for the rightmost occurrence, and returns a vector representing
the range [leftmost, rightmost].
*/

class Solution
{
    int binarySearch(vector<int> &nums, int target, bool isSearchingLeft)
    {
        int left = 0;
        int right = nums.size() - 1;
        int idx = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
            {
                idx = mid;
                if (isSearchingLeft)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return idx;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
    }
};

int main()
{
    return 0;
}