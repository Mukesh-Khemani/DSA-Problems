#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
Initially, we create a dynamic programming array `dp` where each
index represents a sum value from 0 to the target. We set `dp[0]`
to 1, as there's one way to reach a sum of 0 (by selecting no numbers).
Subsequently, we iterate through values from 0 to the `target`, and for
each value `i`, we iterate through the provided `nums`. If subtracting
a number `num` from `i` yields a non-negative result, we add the count
of combinations represented by `dp[i - num]` to `dp[i]`.
*/

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++)
        {
            for (int num : nums)
            {
                if (i - num >= 0)
                    dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};

int main()
{
    return 0;
}