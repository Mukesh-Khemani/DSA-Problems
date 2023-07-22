#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The code uses dynamic programming with memoization to find the probability of a knight
remaining on an n x n chessboard after making k moves, starting from a given position
(row, column). It iteratively calculates the probabilities for different positions and
moves, using a recursive function with memoization. Finally, it returns the total probability.
*/

class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
    {
        vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        vector dp(k + 1, vector(n, vector<double>(n, -1)));
        function<double(int, int, int)> calculateDP = [&](int moves, int i, int j) -> double
        {
            if (moves == 0)
            {
                if (i == row and j == column)
                    return 1;
                else
                    return 0;
            }
            if (dp[moves][i][j] != -1)
                return dp[moves][i][j];
            dp[moves][i][j] = 0;
            for (const auto &it : directions)
            {
                int prevI = i - it.first;
                int prevJ = j - it.second;
                if (prevI >= 0 and prevI < n and prevJ >= 0 and prevJ < n)
                {
                    dp[moves][i][j] += calculateDP(moves - 1, prevI, prevJ) / 8.0;
                }
            }
            return dp[moves][i][j];
        };
        double totalProbability = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                totalProbability += calculateDP(k, i, j);
            }
        }
        return totalProbability;
    }
};

int main()
{
    return 0;
}