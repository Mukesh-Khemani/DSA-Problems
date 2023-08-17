#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to update each non-zero cell in the matrix with the minimum distance to
the nearest zero cell. We achieve this by using a breadth-first search (BFS) approach,
starting from the zero cells and spreading out to update the distances in a systematic manner.
*/

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        if (mat.empty() or mat[0].empty())
            return {};
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        int Max = m * n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                    q.push({i, j});
                else
                    mat[i][j] = Max;
            }
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
            for (auto [r, c] : directions)
            {
                int newRow = r + row, newCol = c + col;
                if (newRow >= 0 and newRow < m and newCol >= 0 and newCol < n and
                    mat[newRow][newCol] > mat[row][col] + 1)
                {
                    q.push({newRow, newCol});
                    mat[newRow][newCol] = mat[row][col] + 1;
                }
            }
        }
        return mat;
    }
};

int main()
{
    return 0;
}