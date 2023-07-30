#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We use dynamic programming to efficiently calculate the minimum steps for
printing all substrings of s. We searche for a "pivot" index j in each
substring, and if found, we reduce the number of steps needed. The minimum
steps for each substring are stored in the dp table. Finally, the minimum
steps needed to print the entire string s are returned by accessing
dp[0][n-1] + 1, where n is the size of s.
*/

class Solution
{
public:
    int strangePrinter(string s)
    {
        int n = s.size();
        vector dp(n, vector<int>(n, n));
        for (int length = 1; length <= n; length++)
        {
            for (int left = 0; left <= n - length; left++)
            {
                int right = left + length - 1;
                int j = -1;
                for (int i = left; i < right; i++)
                {
                    if (s[i] != s[right] and j == -1)
                        j = i;
                    if (j != -1)
                        dp[left][right] = min(dp[left][right],
                                              1 + dp[j][i] + dp[i + 1][right]);
                }
                if (j == -1)
                    dp[left][right] = 0;
            }
        }
        return dp[0][n - 1] + 1;
    }
};

int main()
{
    return 0;
}