#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We have the list of bombs, and we have to return the maximum number of bombs that can be detonated if we are allowed to detonate only one bomb. So we have to find out the bomb detonating which will detonate the most number of bombs (as each detonated bomb will detonate the next active bomb in its surrounding area).

APPROACH:
1) For each bomb, create a graph where each bomb is a node, and there is an edge between two bombs if their blast radii overlap.
2) Perform a depth-first search (DFS) starting from each bomb to find the number of connected bombs that can be detonated.
3) Keep track of the maximum number of connected bombs seen so far.
*/

class Solution
{
    void dfs(vector<vector<int>> &graph, vector<bool> &visited,
             int &connectedBombs, int &i)
    {
        visited[i] = true;
        connectedBombs++;
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (!visited[graph[i][j]])
                dfs(graph, visited, connectedBombs,
                    graph[i][j]);
        }
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
        {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r = bombs[i][2];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    long long x = abs(x1 - bombs[j][0]), y = abs(y1 - bombs[j][1]);
                    if (x * x + y * y <= r * r)
                        graph[i].push_back(j);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int connectedBombs = 0;
            vector<bool> visited(n, false);
            dfs(graph, visited, connectedBombs, i);
            res = max(res, connectedBombs);
        }
        return res;
    }
};

int main()
{
    return 0;
}