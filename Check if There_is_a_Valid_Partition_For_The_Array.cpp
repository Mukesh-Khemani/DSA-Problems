#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In order to determine whether a valid partition exists within an integer array in this case,
we use dynamic programming. Using a sliding window method, we loop through the array while
keeping a DP vector in order to keep track of conditions pertaining to consecutive and equal
values. The dp vector's elements, which are updated depending on comparisons between the current
and prior elements, show the viability of partitions made in accordance with particular principles.
If a legitimate partition that complies with preset conditions is present in the array, it will
be indicated by the final value of dp[2].
*/

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return false;
        vector<bool> dp = {true, false, n > 1 and nums[0] == nums[1]};
        for (int i = 2; i < n; i++)
        {
            bool current = false;
            if (nums[i] == nums[i - 1] and dp[1])
                current = true;
            else if (nums[i] == nums[i - 1] and nums[i] == nums[i - 2] and dp[0])
                current = true;
            else if (nums[i] - nums[i - 1] == 1 and nums[i - 1] - nums[i - 2] == 1 and dp[0])
                current = true;
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = current;
        }
        return dp[2];
    }
};

int main()
{
    return 0;
}