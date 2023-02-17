#include <bits/stdc++.h>
using namespace std;


// SOLUTION 1:
class Solution {
public:
    void Inorder(TreeNode* root,vector<int> &v){
        if(root==NULL) return;
        Inorder(root->left,v);
        v.push_back(root->val);
        Inorder(root->right,v);
    }
    int minDiffInBST(TreeNode* root){
        vector<int> v;
        Inorder(root,v);
        int x=INT_MAX;
        for(int i=1;i<v.size();i++){
            x= x>(v[i]-v[i-1]) ? v[i]-v[i-1]:x;  
        }
        return x;
    }
};


// SOLUTION 2 - OPTIMISED FORM OF SOLUTION 1:
class Solution
{
    int prevVal = INT_MAX;
    void inorder(TreeNode *root, int &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);

        if (prevVal != INT_MAX)
            ans = min(ans, root->val - prevVal);
            
        prevVal = root->val;
        inorder(root->right, ans);
    }

public:
    int minDiffInBST(TreeNode *root)
    {
        prevVal = INT_MAX;
        int ans = INT_MAX;
        inorder(root, ans);
        return ans;
    }
};
int main()
{
    return 0;
}