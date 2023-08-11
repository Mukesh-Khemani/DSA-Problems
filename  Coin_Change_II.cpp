#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem wants us to count distinct combinations to make a given amount using
various coin denominations. So we use dynamic programming by iteratively accumulating
ways to reach different amounts. The base case initializes dp[0] to 1, representing
one way to make zero amount. By iterating over coins and amounts, we build upon smaller
solutions to calculate larger ones, ultimately yielding the total ways to achieve the
target amount.
*/

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i : coins)
        {
            for (int j = i; j <= amount; j++)
            {
                dp[j] += dp[j - i];
            }
        }
        return dp[amount];
    }
};

int main()
{
    return 0;
}