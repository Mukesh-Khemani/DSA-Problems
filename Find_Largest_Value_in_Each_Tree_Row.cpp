#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the largest value in each level of a binary tree.
So we employ a depth-first search approach, implemented through a recursive
helper function. Then we traverse the tree, updating the maximum value for
each level in a vector called `ans`. If the current depth is equal to the
size of `ans`, a new level is reached, and the current node value is appended
to `ans`. Otherwise, we compare the current node value with the existing maximum
value for the level and update it if necessary. The `ans` vector, thus populated
during the traversal, represents the largest values at each level of the binary tree.
*/

class Solution
{
    vector<int> ans;

    void helper(TreeNode *node, int depth)
    {
        if (node == nullptr)
            return;
        if (depth == ans.size())
            ans.push_back(node->val);
        else
            ans[depth] = max(ans[depth], node->val);

        helper(node->left, depth + 1);
        helper(node->right, depth + 1);
    }

public:
    vector<int> largestValues(TreeNode *root)
    {
        helper(root, 0);
        return ans;
    }
};

int main()
{
    return 0;
}