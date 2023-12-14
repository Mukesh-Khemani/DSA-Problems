#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to compute the difference between twice the count of ones
in each row and column and the total number of rows and columns in a given
binary matrix `grid`. We first calculate the cumulative count of ones in
each row (`onesRow`) and each column (`onesCol`). Then, we construct a new
matrix `diff` where each element at position `(i, j)` represents the
specified difference for the corresponding row and column.
*/

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> onesRow(m, 0);
        vector<int> onesCol(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }
        vector<vector<int>> diff(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                diff[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - n - m;
        }
        return diff;
    }
};

int main()
{
    return 0;
}