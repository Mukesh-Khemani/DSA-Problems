#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the given problem, we need to generate all possible full binary trees (FBTs)
with n nodes. An FBT is a binary tree in which every node has either 0 or 2
children. So we use dynamic programming to efficiently construct these trees
by breaking down the problem into smaller subproblems. We iterate through
different combinations of left and right subtrees to construct full binary
trees with 'n' nodes.
*/

class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (!(n % 2))
            return {};
        vector<vector<TreeNode *>> dp(n + 1);
        dp[1].push_back(new TreeNode(0));
        for (int count = 3; count <= n; count += 2)
        {
            for (int i = 1; i < count - 1; i += 2)
            {
                int j = count - i - 1;
                for (auto left : dp[i])
                {
                    for (auto right : dp[j])
                    {
                        TreeNode *root = new TreeNode(0, left, right);
                        dp[count].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    return 0;
}