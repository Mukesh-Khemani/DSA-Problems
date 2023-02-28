#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Map to store tree/sub-tree in form of 
    // string along with their root nodes
    unordered_map<string,vector<TreeNode*>> mp;

    string preOrder(TreeNode* root){
        
        // In case of null node, return 'null' string
        if(!root) return "NULL";

        // To store the tree of current node 
        string tree = to_string(root->val) + ',';
        // Recur for left and right sub-trees and add them
        // to current node
        tree += preOrder(root->left) + ',';
        tree += preOrder(root->right);

        // Adding tree to map and push its root
        mp[tree].push_back(root);

        // Return current node tree
        return tree;
    } 
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preOrder(root);

        vector<TreeNode*> v;

        for(auto it:mp){
            if(it.second.size() > 1){
                // If size > 1 , then a duplicate has been found
                // Hence, add it to the answer
                v.push_back(it.second[0]);
            }
        }

        return v;
    }
};
int main()
{
    return 0;
}