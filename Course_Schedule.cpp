#include <bits/stdc++.h>
using namespace std;
/*
INTUITION and APPROACH:
The given problem checks if it is possible to finish all the courses given their prerequisites
using a graph algorithm. We use depth-first search (DFS) to detect cycles in the graph.
The canFinish function initializes an adjacency list and calls a recursive helper function.
The helper function performs a DFS traversal, keeping track of visited nodes and the current
recursion stack. If a node is already in the stack, it indicates a cycle, and true is returned.
If a node is already visited, it does not contribute to a cycle, and false is returned. If a
cycle is found for any course, false is returned, indicating it is not possible to finish all
the courses. If no cycle is found, true is returned, indicating all courses can be finished.
*/
class Solution
{
    bool helper(int node, vector<vector<int>> &adj,
                vector<bool> &visited, vector<bool> &inStack)
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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(numCourses);
        vector<bool> inStack(numCourses);
        for (int i = 0; i < numCourses; i++)
        {
            if (helper(i, adj, visited, inStack))
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}