#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
An alternative way to look at this problem is to maximise the difference between
Alice and Bob. The 'help' function returns the difference between their respective
scores and we can calculate the sum of their scores with the help of the given array.
Hence, we can take their average to get Alice's maximum score.
*/

class Solution
{
public:
    int dp[101][201];
    int help(int i, int M, vector<int> &piles)
    {
        if (i >= piles.size())
            return 0;
        if (dp[i][M] != -1)
            return dp[i][M];
        int total = 0;
        int res = INT_MIN;
        for (int j = 0; j < 2 * M; j++)
        {
            if (i + j < piles.size())
            {
                total += piles[i + j];
                res = max(res, total - help(i + j + 1, max(M, j + 1), piles));
            }
        }
        return dp[i][M] = res;
    }
    int stoneGameII(vector<int> &piles)
    {
        memset(dp, -1, sizeof dp);
        int sum = 0;
        for (auto i : piles)
            sum += i;
        int diff = help(0, 1, piles);
        return (sum + diff) / 2;
    }
};

int main()
{
    return 0;
}