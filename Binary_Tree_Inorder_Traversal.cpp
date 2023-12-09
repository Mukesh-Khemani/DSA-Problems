#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
This problem aims to perform an inorder traversal of a binary
tree and returns a vector containing the values of the tree
nodes in ascending order. We achieve this by defining a helper
function named `Inorder` that recursively traverses the tree,
visiting left subtree, current node, and right subtree in that
order. The values of the nodes are then pushed into a vector
during the traversal.
*/

class Solution
{
public:
    void Inorder(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        Inorder(root->left, v);
        v.push_back(root->val);
        Inorder(root->right, v);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        Inorder(root, v);
        return v;
    }
};

int main()
{
    return 0;
}