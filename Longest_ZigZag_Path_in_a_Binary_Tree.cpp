#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We need to find the length of the maximum zigzag subtree. For that
we traverse the entire tree untill we reach the leaf nodes. Some imp
points to keep in my while Depth-First Search:
-> If we are have a parent node which is a left child, we cannot combine
the edges going into parent and left subchild, because they do not form a
zigzag path. We can only begin a new zigzag path of length 1 by including
the edge between the parent node and the left subchild.
-> We can only form a zigzag path between a parent node (which is a left child)
and its right subchild. Similarly, between a parent node (which is a right child)
and its left subchild.
*/

class Solution
{
    int pathLength = 0;
    void dfs(TreeNode *node, bool goLeft, int steps)
    {
        if (node == NULL)
            return;
        pathLength = max(pathLength, steps);
        if (goLeft)
        {
            dfs(node->left, false, steps + 1);
            dfs(node->right, true, 1);
        }
        else
        {
            dfs(node->left, false, 1);
            dfs(node->right, true, steps + 1);
        }
    }

public:
    int longestZigZag(TreeNode *root)
    {
        dfs(root->left, false, 1);
        dfs(root->right, true, 1);
        return pathLength;
    }
};

int main()
{
    return 0;
}