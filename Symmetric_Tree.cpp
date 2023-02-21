#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool issymmetric(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL) return 1;
        if(p && q && p->val==q->val){
            return (issymmetric(p->right,q->left) && 
            issymmetric(p->left,q->right));
        }
        return 0;
    }
    bool isSymmetric(TreeNode* root) {
        return issymmetric(root->right,root->left);
    }
};
int main(){
    return 0;
}