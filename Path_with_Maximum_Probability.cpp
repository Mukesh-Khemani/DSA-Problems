#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem involves finding the maximum probability of reaching the end node from the start node
in a graph.

WORKING:
We create a graph representation from the given edges and probabilities. We initialize a path array
with the maximum probability set to 1 for the start node and 0 for other nodes. Using a queue, we
perform a BFS traversal, updating the maximum probabilities for each node based on the current node's
probability and the edge probabilities. Finally, we return the maximum probability stored in the path
array for the end node.
*/
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            graph[x].push_back({y, succProb[i]});
            graph[y].push_back({x, succProb[i]});
        }
        vector<double> path(n, 0.0);
        path[start] = 1.0;
        queue<int> q;
        q.push(start);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto it : graph[curr])
            {
                double currNode = it.first;
                double currProb = it.second;
                double newProb = path[curr] * currProb;
                if (newProb > path[currNode])
                {
                    path[currNode] = newProb;
                    q.push(currNode);
                }
            }
        }
        return path[end];
    }
};

int main()
{
    return 0;
}