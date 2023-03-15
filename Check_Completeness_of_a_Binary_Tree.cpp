#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
While doing the level order traversal of the tree, if any NULL node is obtained, that 
should be the end of the tree.

APPROACH:
-> We have to do the level order traversal of the binary tree.
-> We start with adding the root of the tree into the queue and a boolean flag='false'
-> We iterate until queue is empty or the boolean flag becomes 'true'.
-> At each step, we keep on adding the root's left as well as right node in the queue
and remove the root from the queue.
-> If a NULL node is obtained, flag becomes true and in the following iteration,
false is returned as the final output.
-> But if the queue becomes empty, this means that the NULL node obtained is the
last node of the tree. Therefore, the tree is Complete. Return true.

*/
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node==NULL) flag=true;
            else{
                if(flag) return false;
                else{
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}