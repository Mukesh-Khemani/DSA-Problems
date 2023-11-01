#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The given problem aims to find the mode (most frequent elements) in a
binary search tree (BST). So we employ an unordered_map to count the
occurrences of each unique value in the BST through an in-order traversal.
The function isValid traverses the BST in-order, updating the frequency
count in the map for each encountered value. Subsequently, we identify
the maximum frequency (maxi) among the values in the map. We then iterate
through the map to identify all values with the maximum frequency and adds
them to the result vector.
*/

class Solution
{
    unordered_map<int, int> map;
    void isValid(TreeNode *root)
    {
        if (root == NULL)
            return;
        isValid(root->left);
        map[root->val]++;
        isValid(root->right);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        isValid(root);
        int maxi = 0;
        for (auto it : map)
        {
            if (it.second > maxi)
                maxi = it.second;
        }
        vector<int> ans;
        for (auto it : map)
        {
            if (it.second == maxi)
                ans.push_back(it.first);
        }
        return ans;
    }
};

int main()
{
    return 0;
}