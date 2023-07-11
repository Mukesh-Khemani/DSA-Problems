#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        map<int, TreeNode *> parent;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *top = q.front();
                q.pop();
                if (top->left)
                {
                    parent[top->left->val] = top;
                    q.push(top->left);
                }
                if (top->right)
                {
                    parent[top->right->val] = top;
                    q.push(top->right);
                }
            }
        }
        map<int, int> visited;
        q.push(target);
        while (k-- and !q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *top = q.front();
                q.pop();
                visited[top->val] = 1;
                if (top->left and !visited[top->left->val])
                    q.push(top->left);
                if (top->right and !visited[top->right->val])
                    q.push(top->right);
                if (parent[top->val] and !visited[parent[top->val]->val])
                {
                    q.push(parent[top->val]);
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};

int main()
{
    return 0;
}