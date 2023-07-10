#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the solution is to check the depth of the left and right subtrees
of each node and return the minimum depth among them.

EXPLANATION:
In the minDepth function, the helper function is called to calculate the minimum depth.
The helper function recursively traverses the tree and returns the minimum depth by
considering the presence of left and right children.
*/

class Solution
{
    int helper(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (!root->left)
            return 1 + helper(root->right);
        else if (!root->right)
            return 1 + helper(root->left);
        return min(helper(root->left), helper(root->right)) + 1;
    }

public:
    int minDepth(TreeNode *root)
    {
        return helper(root);
    }
};

int main()
{
    return 0;
}