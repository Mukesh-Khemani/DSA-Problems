#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return 1;
        if(p!=NULL && q!=NULL){
            return (p->val==q->val && isSameTree(p->left,q->left) && 
            isSameTree(p->right,q->right));
        }
        return 0;

    }
};
int main(){
    return 0;
}