#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem is to determine whether a third string ''s3'' can be constructed
by interleaving the characters of two given strings 's1' and 's2' while
preserving the original order of characters from both strings. So we employ
a dynamic programming approach, utilizing a boolean vector dp to track if
specific substrings of 's1' and 's2' can contribute to forming corresponding
substrings of 's3'. By iteratively updating the dp vector based on character
matches and maintaining the order of characters, we efficiently determine if
's3' can indeed be constructed through interleaving.
*/

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.length(), l = s3.length();
        if (m + n != l)
            return false;
        if (m < n)
            return isInterleave(s2, s1, s3);
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int j = 1; j <= n; j++)
            dp[j] = dp[j - 1] and s2[j - 1] == s3[j - 1];
        for (int i = 1; i <= m; i++)
        {
            dp[0] = dp[0] and s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= n; j++)
            {
                dp[j] = (dp[j] and s1[i - 1] == s3[i + j - 1]) or
                        (dp[j - 1] and s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[n];
    }
};

int main()
{
    return 0;
}