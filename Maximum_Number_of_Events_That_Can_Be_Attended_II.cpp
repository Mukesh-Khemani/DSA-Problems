#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the maximum value that can be obtained by attending events,
considering a limit on the number of events that can be attended. So we use dynamic
programming and memoization to efficiently explore different event combinations. By
recursively considering attending or skipping events, and storing computed results
in a memoization array, we determine the maximum value that can be achieved.
*/

class Solution
{
    int helper(vector<vector<int>> &events, int k, int i,
               vector<vector<int>> &dp)
    {
        if (i >= events.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int ans = helper(events, k, i + 1, dp);
        if (k)
        {
            vector<int> temp = {events[i][1], INT_MAX, INT_MAX};
            int next = upper_bound(events.begin(), events.end(), temp) - events.begin();
            ans = max(ans, events[i][2] + helper(events, k - 1, next, dp));
        }
        return dp[i][k] = ans;
    }

public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return helper(events, k, 0, dp);
    }
};

int main()
{
    return 0;
}