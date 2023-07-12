#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The main intuition behind the solution is as follows:
1) The eventual safe nodes are those nodes in the graph that do not have any outgoing
edges or do not participate in any cycles.
2) We can identify cycles in the graph using DFS. If we encounter a node that is already
in the current DFS path, it means there is a cycle, and we mark it as unsafe.
3) By performing DFS on all nodes in the graph, we can identify which nodes are safe and
which are not.
*/

class Solution
{
    bool helper(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inStack)
    {
        if (inStack[node])
            return true;
        if (visited[node])
            return false;
        visited[node] = true;
        inStack[node] = true;
        for (auto it : adj[node])
        {
            if (helper(it, adj, visited, inStack))
                return true;
        }
        inStack[node] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
            {
                adj[i].push_back(it);
            }
        }
        vector<bool> visited(n), inStack(n);
        for (int i = 0; i < n; i++)
        {
            helper(i, adj, visited, inStack);
        }
        vector<int> safeNodes;
        for (int i = 0; i < n; i++)
        {
            if (!inStack[i])
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};

int main()
{
    return 0;
}