#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem calculates the minimum cost to connect a set of 2D points, forming a
minimum spanning tree (MST) using a Prim's algorithm-like approach. So we maintain
a priority queue to select edges with the smallest distances, iteratively connecting
unvisited vertices and updating the minimum cost. For each vertex, we calculate the
distances to all other unvisited vertices and store the minimum distance in a cache
to optimize subsequent calculations.
*/

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int min_cost = 0;
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        map<int, int> cache;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto edge = pq.top();
            pq.pop();
            int cost = edge.first;
            int u = edge.second;
            if (visited[u])
                continue;
            visited[u] = true;
            min_cost += cost;
            for (int v = 0; v < n; v++)
            {
                if (!visited[v])
                {
                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);
                    if (cache.find(v) == cache.end() || dist < cache[v])
                    {
                        cache[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }
        return min_cost;
    }
};

int main()
{
    return 0;
}