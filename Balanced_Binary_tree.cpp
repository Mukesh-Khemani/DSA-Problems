#include <bits/stdc++.h>
using namespace std;

class Solution {
    int Height(TreeNode* root){
        if(root==NULL) return 0;
        int leftHeight=Height(root->left);
        int rightHeight=Height(root->right);
        if(leftHeight==-1 || rightHeight==-1 || 
        abs(leftHeight-rightHeight)>1) return -1;
        return max(leftHeight,rightHeight)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return 1;
        return !(Height(root)==-1);
    }
};

int main()
{
    return 0;
}