#include <bits/stdc++.h>
using namespace std;

/*
APPROACH:To solve this problem, we use dynamic programming to count the number of paths from the
top-left corner to the bottom-right corner in a given grid. We initialize a dp matrix to store
precomputed values. We then recursively calculate the number of paths for each position based
on the value of the previous position, storing the results in the dp matrix. Finally, we sum up
all the values in the dp matrix to obtain the total number of paths. This approach optimizes
the computation by avoiding redundant calculations.
*/

class Solution
{
    int mod = 1000000007;
    int helper(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp,
               int previous)
    {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or
            previous >= grid[i][j])
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int l = helper(grid, i - 1, j, dp, grid[i][j]);
        int r = helper(grid, i + 1, j, dp, grid[i][j]);
        int t = helper(grid, i, j - 1, dp, grid[i][j]);
        int b = helper(grid, i, j + 1, dp, grid[i][j]);
        dp[i][j] = (1 + l + r + t + b) % mod;
        return dp[i][j];
    }

public:
    int countPaths(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 and n == 1)
        {
            return 1;
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] == -1)
                    res += (helper(grid, i, j, dp, -1) % mod);
                else
                    res = (res + dp[i][j]) % mod;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}