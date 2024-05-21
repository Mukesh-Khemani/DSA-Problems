#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind this code is to use recursion to generate all possible
subsets of a given set of numbers. The idea is to recursively build subsets
by including each element or excluding it, starting from the first element
to the last. By systematically including and excluding elements, we explore
all possible combinations, effectively generating all subsets. The base case
of the recursion handles when we have processed all elements, and the
recursive calls ensure that both scenarios (including or excluding an element)
are considered, ultimately building the power set of the input set.
*/

class Solution
{
    void helper(vector<int> &nums, int i, vector<int> &s)
    {
        if (i >= nums.size())
        {
            return;
        }
        s.push_back(nums[i]);
        helper(nums, i + 1, s);
        v.push_back(s);
        s.pop_back();
        helper(nums, i + 1, s);
    }

public:
    vector<vector<int>> v;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> s;
        v.push_back(s);
        helper(nums, 0, s);
        return v;
    }
};

int main()
{
    return 0;
}