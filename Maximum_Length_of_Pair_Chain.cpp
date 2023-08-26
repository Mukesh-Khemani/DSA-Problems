#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The task is to find the longest chain of pairs within a given vector,
where each pair's second value must be greater than the first value of
the next pair in the chain. We first sort the pairs based on their first
values. We then employ dynamic programming by iterating through the pairs
in reverse order, updating a dynamic programming vector to store the
lengths of longest chains ending at each pair. The algorithm maximizes
the chain length by considering valid pairs that can be included in the
chain, effectively building a sequence of pairs with the desired property.
*/

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (pairs[i][1] < pairs[j][0])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}