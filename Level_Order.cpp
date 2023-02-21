#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> z;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                z.push_back(node->val);
            }
            v.push_back(z);
        }
        return v;
    }
};
int main(){
    return 0;
}