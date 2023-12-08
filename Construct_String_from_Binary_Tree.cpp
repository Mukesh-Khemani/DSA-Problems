#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition in this problem is to convert a binary tree into a string
representation using a preorder traversal. The helper function is
recursively called for each node, appending the node's value to the string.
If the node has only a right child, parentheses are used to represent the
absence of a left child. If the node has both left and right children, the
left subtree is enclosed in parentheses, while the right subtree is enclosed
only if it is present.
*/

class Solution
{
    void helper(TreeNode *root, string &str)
    {
        if (root == NULL)
            return;
        str += to_string(root->val);
        if (root->left or root->right)
        {
            str += '(';
            helper(root->left, str);
            str += ')';
        }
        if (root->right)
        {
            str += '(';
            helper(root->right, str);
            str += ')';
        }
    }

public:
    string tree2str(TreeNode *root)
    {
        string str = "";
        helper(root, str);
        return str;
    }
};

int main()
{
    return 0;
}