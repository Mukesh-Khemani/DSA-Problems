#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The main intuition is using recursive backtracking to explore all possible
permutations of the input vector 'nums'. The code ensures that each element
is considered once by checking its absence in the temporary vector 'v'. The
process continues until all permutations are generated and stored in the result vector 'res'.
*/

class Solution
{
private:
    void helper(vector<vector<int>> &res, vector<int> &v, vector<int> &nums)
    {
        if (v.size() == nums.size())
        {
            res.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(v.begin(), v.end(), nums[i]) == v.end())
            {
                v.push_back(nums[i]);
                helper(res, v, nums);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> v;
        helper(res, v, nums);
        return res;
    }
};

int main()
{
    return 0;
}