#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition is to systematically explore and evaluate combinations of requests to
find the maximum number that can be fulfilled while maintaining balance in the flow of requests.

APPROACH:
The approach involves iterating through all possible subsets of requests using a bitmask. For each
subset, we evaluate if it satisfies the condition of balanced flow by updating the indegree and
outdegree of each node. We keep track of the maximum number of requests that fulfill the condition.
Finally, we return the maximum number of requests. This approach ensures that we consider all possible
combinations and select the optimal solution.
*/

class Solution
{
public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        int maxRequests = 0;
        int numRequests = requests.size();
        for (int mask = 0; mask < (1 << numRequests); mask++)
        {
            vector<int> indegree(n, 0);
            int selectedRequests = 0;
            for (int i = 0; i < numRequests; i++)
            {
                if ((mask >> i) & 1)
                {
                    indegree[requests[i][0]]--;
                    indegree[requests[i][1]]++;
                    selectedRequests++;
                }
            }
            bool balanced = true;
            for (int i = 0; i < n; i++)
            {
                if (indegree[i] != 0)
                {
                    balanced = false;
                    break;
                }
            }
            if (balanced)
            {
                maxRequests = max(maxRequests, selectedRequests);
            }
        }
        return maxRequests;
    }
};

int main()
{
    return 0;
}