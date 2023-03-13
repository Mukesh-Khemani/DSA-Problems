#include<bits/stdc++.h>
using namespace std;

/*

INTUITION:
The idea is to write a recursive function issymmetric() that takes two trees as 
an argument and returns true if trees are the mirror and false if trees are not 
mirrored. The issymmetric() function recursively checks two roots and subtrees 
under the root.

WORKING:
For two trees to be symmetric, the following conditions must be true:
-> Their root node's key must be same
-> left subtree of left tree and right subtree of right tree have to be symmetric
-> right subtree of left tree and left subtree of right tree have to be symmetric

*/

class Solution {
    bool issymmetric(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL) return p==q;
        if(p->val!=q->val) return false;
        return issymmetric(p->left,q->right) && 
        issymmetric(p->right,q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return issymmetric(root->left,root->right);
    }
};

int main(){
    return 0;
}