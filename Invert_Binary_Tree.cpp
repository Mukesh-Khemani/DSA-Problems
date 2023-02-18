#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        else{
            invertTree(root->left);
            invertTree(root->right);
            TreeNode* temp=root->left;
            root->left=root->right;
            root->right=temp;
            //return root;
        }
        return root;
    }
};
int main(){
    return 0;
}