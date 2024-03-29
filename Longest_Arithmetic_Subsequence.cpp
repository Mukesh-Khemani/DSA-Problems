#include <bits/stdc++.h>
using namespace std;

/*
APPROACH:
So we start by iterating through each element of the input array nums.
For each element, we compare it with all previous elements to find
the common difference and update the corresponding dp value. If we find
a previous subsequence with the same common difference, we increment the
length by 1. Otherwise, we create a new subsequence of length 2.
*/

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int seqLength = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                seqLength = max(seqLength, dp[i][diff]);
            }
        }
        return seqLength;
    }
};

int main()
{
    return 0;
}