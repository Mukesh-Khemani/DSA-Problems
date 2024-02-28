#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the value of the bottom-left node in a binary tree.
We use a breadth-first search (BFS) approach, implemented using a queue data
structure. Beginning with the root node, we iteratively explore each level of
the tree, starting from the leftmost node at each level. As nodes are processed,
their left and right children, if existent, are added to the queue for further
exploration. By the end of the traversal, the last node visited represents the
bottom-left node in the tree. Thus, we return the value of this node.
*/

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *ans = NULL;
        while (!q.empty())
        {
            ans = q.front();
            q.pop();

            if (ans->right)
                q.push(ans->right);
            if (ans->left)
                q.push(ans->left);
        }
        return ans->val;
    }
};

int main()
{
    return 0;
}