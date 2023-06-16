#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the problem is to recursively divide the given array into left
and right subtrees based on the root node. The number of ways to arrange the left
subtree is calculated using the recursive function, and similarly for the right
subtree. The total number of ways to arrange the entire tree is then calculated by
multiplying the number of ways for the left subtree, right subtree, and the number
of combinations for choosing the root node.
*/

class Solution
{
    int mod = 1000000007;

public:
    int numOfWays(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> combinations(n + 1, vector<int>(n + 1));
        combinations[0][0] = 1;
        for (int i = 0; i <= n; i++)
        {
            combinations[i][0] = 1;
            for (int j = 1; j <= i; j++)
            {
                combinations[i][j] = (combinations[i - 1][j - 1] +
                                      combinations[i - 1][j]) %
                                     mod;
            }
        }
        function<int(vector<int> &)> helper = [&](vector<int> &nums)
        {
            int n = nums.size();
            if (n <= 2)
                return 1;
            vector<int> leftSubTree, rightSubTree;
            for (int i = 1; i < n; i++)
            {
                if ((nums[i] < nums[0]))
                    leftSubTree.push_back(nums[i]);
                else
                    rightSubTree.push_back(nums[i]);
            }
            long long ans = combinations[n - 1][leftSubTree.size()];
            ans = ans * helper(leftSubTree) % mod;
            ans = ans * helper(rightSubTree) % mod;
            return (int)ans;
        };
        return helper(nums) - 1;
    }
};

int main()
{
    return 0;
}