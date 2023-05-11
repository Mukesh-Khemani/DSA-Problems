#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The idea is to find the maximum number of uncrossed lines that can be drawn
up to each element in the two arrays and then combine them to find the maximum
number of uncrossed lines that can be drawn up to the last element of the two arrays.

APPROACH:
The three cases handled in the nested if-else statements are as follows:
1) If either nums1 or nums2 is empty (i.e., i==0 or j==0), there are no common elements,
so the value of dp[i][j] is set to 0.
2) If the elements at indices i-1 and j-1 in nums1 and nums2 respectively are equal,
it means we can extend the common subsequence by one. So, we increment the value of dp[i][j]
by 1, considering the length of the current subsequence.
3) If the elements at indices i-1 and j-1 in nums1 and nums2 respectively are not equal, we
need to decide whether to include the current elements in the subsequence or not. We choose
the maximum value between dp[i-1][j] (the length of the subsequence without the current element
of nums1) and dp[i][j-1] (the length of the subsequence without the current element of nums2).
After iterating through all elements of both arrays, the final result is stored in dp[n1][n2],
which represents the length of the longest common subsequence (the maximum number of uncrossed lines).
*/

class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 0; i <= n1; ++i)
        {
            for (int j = 0; j <= n2; ++j)
            {
                if (i == 0 or j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};

int main()
{
    return 0;
}