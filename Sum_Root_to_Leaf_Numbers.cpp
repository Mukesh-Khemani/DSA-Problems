#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
Given a binary tree, where every node value is a Digit from 1-9. 
Find the sum of all the numbers which are formed from root to leaf paths.

APPROACH:
The function SUM takes a pointer to the root of a binary tree as input and 
returns the sum of all the numbers that can be formed by traversing from the 
root to a leaf node.

The function SUM is a recursive function that takes two arguments: a pointer 
to the current node, the current sum 'n'. The current sum is calculated by 
multiplying the previous sum by 10 and adding the value of the current node's 
value. If the current node is a leaf node, the current sum(n) is added to the 
total sum(ans). If the current node is not a leaf node, the SUM function is 
called recursively on the left and right subtrees with the updated current(n).
*/
class Solution {
    int ans=0;
    void SUM(TreeNode *root,int n){
        if(root==NULL) return ;
        n=10*n+root->val;
        if(root->left==NULL && root->right==NULL) ans+=n;
        SUM(root->left,n);
        SUM(root->right,n);
    }
public:
    int sumNumbers(TreeNode* root) {
        SUM(root,0);
        return ans;
    }
};

int main()
{
    return 0;
}