#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The given problem aims to find the minimum difference between any two nodes in a
binary search tree (BST). The intuition behind the approach is that in a BST,
the nodes are arranged in sorted order. Therefore, by traversing the tree in an
in-order manner, we can compare adjacent nodes and find the minimum difference.

NOTE: We need not store the entire inOrder traversal of the BST. We just need to
compare the difference between any 2 nodes and the main intuition is that the minimum
difference will be between a parent-child pair. So we need not compare the difference
of each pair of nodes.
*/

class Solution
{
    int minDifference = INT_MAX;
    TreeNode *prevNode = NULL;
    void inOrder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inOrder(root->left);
        if (prevNode)
        {
            minDifference = min(minDifference, root->val - prevNode->val);
        }
        prevNode = root;
        inOrder(root->right);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        inOrder(root);
        return minDifference;
    }
};

int main()
{
    return 0;
}