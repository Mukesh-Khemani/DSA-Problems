#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition of the problem is to calculate and return the count of
subtrees in a binary tree where the values of all nodes in the subtree
form an arithmetic sequence. We use a helper function, helper, for a
recursive depth-first traversal of the tree. For each node, we calculate
the sum and count of values in its left and right subtrees. If the subtree
is an arithmetic sequence, the count is incremented, and the result is
updated accordingly.
*/

class Solution
{
    int res = 0;
    pair<int, int> helper(TreeNode *node)
    {
        if (!node)
            return {0, 0};
        auto left = helper(node->left);
        auto right = helper(node->right);
        int sum = left.first + right.first + node->val;
        int count = 1 + left.second + right.second;
        res += (node->val == sum / count);
        return {sum, count};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        helper(root);
        return res;
    }
};

int main()
{
    return 0;
}