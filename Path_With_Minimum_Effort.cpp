#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the minimum effort path from the top-left cell to the bottom-right
cell in a grid by considering the maximum height difference between adjacent cells. So we
use a priority queue to explore cells efficiently, choosing cells with lower effort first.
The algorithm gradually updates the minimum effort to reach each cell and returns the minimum
effort required to traverse the grid. This approach ensures that the path minimizes the maximum
height difference along the way.
*/

class Solution
{
public:
    vector<int> directions = {0, 1, 0, -1, 0};
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, 0, 0});
        dist[0][0] = 0;
        while (!minHeap.empty())
        {
            vector<int> top = minHeap.top();
            minHeap.pop();
            int d = top[0];
            int r = top[1];
            int c = top[2];
            if (d > dist[r][c])
                continue;
            if (r == m - 1 && c == n - 1)
                return d;
            for (int i = 0; i < 4; i++)
            {
                int nr = r + directions[i];
                int nc = c + directions[i + 1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    int newDist = max(d, abs(heights[nr][nc] - heights[r][c]));
                    if (dist[nr][nc] > newDist)
                    {
                        dist[nr][nc] = newDist;
                        minHeap.push({dist[nr][nc], nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}