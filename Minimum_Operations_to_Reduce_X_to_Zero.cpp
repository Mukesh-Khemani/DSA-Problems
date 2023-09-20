#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We use a two-pointer sliding window approach to find a subarray with
a sum equal to `target`, where `target` is the difference between the
total sum of elements in `nums` and `x`. By finding the longest
subarray with this sum, we maximize the remaining part of the array,
which effectively minimizes the number of operations needed to reduce
the sum to zero.
*/

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int target = 0, n = nums.size();
        for (int num : nums)
            target += num;
        target -= x;
        if (target == 0)
            return n;
        int len = 0, sum = 0, left = 0;
        for (int right = 0; right < n; right++)
        {
            sum += nums[right];
            while (left <= right and sum > target)
            {
                sum -= nums[left];
                left++;
            }
            if (sum == target)
                len = max(len, right - left + 1);
        }
        return len ? (n - len) : -1;
    }
};

int main()
{
    return 0;
}