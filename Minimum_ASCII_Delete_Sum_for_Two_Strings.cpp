#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the minimum sum of ASCII values required to make two given
strings s1 and s2 equal. The approach employs dynamic programming by using a 2D table
dp to store the minimum sum for different subproblems. Base cases initialize dp[i][0]
and dp[0][j] as sums of ASCII values of prefixes in s1 and s2, respectively. The dynamic
programming table is filled using nested loops, comparing characters of s1 and s2. If
characters are equal, no deletion is needed (dp[i][j] = dp[i-1][j-1]); otherwise, the
minimum is chosen between deleting s1[i-1] or s2[j-1]. The final result is
dp[s1.size()][s2.size()], representing the minimum sum of ASCII values needed for equality.
*/

class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = 1; i <= s1.size(); i++)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int j = 1; j <= s2.size(); j++)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        for (int i = 1; i <= s1.size(); i++)
        {
            for (int j = 1; j <= s2.size(); j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main()
{
    return 0;
}