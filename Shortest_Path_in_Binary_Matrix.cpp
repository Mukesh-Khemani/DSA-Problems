#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We need to find the shortest path starting from the top-left cell to the bottom-right
cell and we can travel in 8 directions. We are using the shortest path approach called
the Dijkstra's Algorithm. It is a popular algorithm for finding the shortest paths in a
weighted graph. It works by starting from a source node and iteratively expanding to
neighboring nodes with the smallest known distances, until the shortest path to the
target node is found or all reachable nodes have been visited.
*/

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] or grid[n - 1][n - 1])
            return -1;
        queue<vector<int>> queue;
        queue.push({0, 0, 1});
        grid[0][0] = 1;
        vector<vector<int>> neighbours = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        while (!queue.empty())
        {
            auto curr = queue.front();
            queue.pop();
            int r = curr[0];
            int c = curr[1];
            int result = curr[2];
            if (r == n - 1 and c == n - 1)
            {
                return result;
            }

            for (int i = 0; i < 8; i++)
            {
                int row = r + neighbours[i][0];
                int col = c + neighbours[i][1];
                if (row >= 0 and row < n and col >= 0 and col < n and grid[row][col] == 0)
                {
                    grid[row][col] = 1;
                    queue.push({row, col, result + 1});
                }
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}