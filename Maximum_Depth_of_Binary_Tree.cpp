#include <bits/stdc++.h>
using namespace std;

int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;
    int ldepth=maxDepth(root->left);
    int rdepth=maxDepth(root->right);
    if(ldepth>=rdepth) return ldepth+1;
    return rdepth+1;
}

int main()
{
    return 0;
}