#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We have to find the total number of provinces where a province is a group of
directly or indirectly connected cities and no other cities outside of the group.

APPROACH:
The solution uses a DFS approach to traverse the graph and identify the connected
components. Each unvisited node encountered during the iteration signifies a new
connected component, and the helper function recursively explores all connected
nodes of that component.
*/

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                provinces++;
                helper(isConnected, visited, i);
            }
        }
        return provinces;
    }
    void helper(vector<vector<int>> &isConnected, vector<bool> &visited,
                int node)
    {
        visited[node] = true;
        for (int connected = 0; connected < isConnected.size(); connected++)
        {
            if (isConnected[node][connected] == 1 and !visited[connected])
            {
                helper(isConnected, visited, connected);
            }
        }
    }
};

int main()
{
    return 0;
}