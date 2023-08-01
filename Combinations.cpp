#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the problem, we use a recursive backtracking approach to generate all possible
combinations of k elements taken from the range 1 to n. We start with each number
from 1 to n, explore all combinations that include that number, and then backtrack
to try other numbers, eventually forming all combinations and storing them in the
ans vector.
*/
class Solution
{
private:
    void helper(vector<vector<int>> &ans, vector<int> &v, int k, int n, int start)
    {
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            v.push_back(i);
            helper(ans, v, k, n, i + 1);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans, v, k, n, 1);
        return ans;
    }
};

int main()
{
    return 0;
}