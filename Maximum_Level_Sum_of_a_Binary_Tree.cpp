#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The given problem is based on the intuition of performing a level-order traversal of
the binary tree to find the level with the maximum sum. By processing each level and
keeping track of the maximum sum encountered, we can determine the level that has the
highest sum of node values.

APPROACH:
This approach ensures that we traverse the tree level by level, calculating the sum at
each level and keeping track of the maximum sum encountered. By using a queue and performing
a level-order traversal, we process nodes in a breadth-first manner, allowing us to find the
level with the maximum sum efficiently.
*/
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int ans = -1, sum = INT_MIN, level = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sumAtThisLevel = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                sumAtThisLevel += temp->val;
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            level++;
            if (sum < sumAtThisLevel)
            {
                sum = sumAtThisLevel;
                ans = level;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}