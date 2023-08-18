#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the given problem, we need to compute the maximal network rank within a network
by analyzing the degrees of nodes and their connections. So we iterate through the
connections, increment the degrees of nodes, and record the connections in a set for
uniqueness. Subsequently, we calculate the sum of degrees for each pair of nodes and
adjust for shared connections. By comparing these sums, we identify the maximum possible
rank for the network. Our strategy is based on exploring node degrees and connections to
determine the highest potential network rank, providing a concise solution to the problem.
*/

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<int> degree(n, 0);
        set<pair<int, int>> set;
        for (auto it : roads)
        {
            degree[it[0]]++;
            degree[it[1]]++;
            set.insert({it[0], it[1]});
            set.insert({it[1], it[0]});
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int curr = degree[i] + degree[j];
                if (set.find({i, j}) != set.end())
                    curr--;
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}