#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We use a depth-first search (DFS) approach to traverse the binary tree and
maintain a path variable XORed with the current node's value. The helper
function recursively explores the tree, updating the path and checking if
the path's binary representation has at most one set bit, making it a
pseudo-palindromic path. When a leaf node is reached, we increment the result
variable if the path meets the pseudo-palindromic condition. The main
function initializes the result variable and calls the helper function to
start the DFS traversal.
*/

class Solution
{
    int ans = 0;
    void helper(TreeNode *node, int path)
    {
        if (node)
        {
            path = path ^ (1 << node->val);
            if (!node->left and !node->right)
            {
                if ((path & (path - 1)) == 0)
                    ans++;
            }
            helper(node->left, path);
            helper(node->right, path);
        }
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        helper(root, 0);
        return ans;
    }
};

int main()
{
    return 0;
}