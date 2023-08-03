#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the problem, we use a recursive approach to generate all possible letter combinations
corresponding to a given string of digits. We leverage the mappings of digits to their
corresponding letters on a phone keypad to explore different combinations. The helper
function recursively appends letters to the combination string, processing each digit
in the digits string one by one until the base case is reached. The base case is when
the digits string becomes empty, indicating that a valid letter combination is formed,
which is then added to the result vector ans.
*/

class Solution
{
    vector<string> v = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(vector<string> &ans, string digits, string combination)
    {
        if (digits.empty())
            ans.push_back(combination);
        else
        {
            string str = v[digits[0] - '2'];
            for (char it : str)
            {
                helper(ans, digits.substr(1), combination + it);
            }
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> ans;
        helper(ans, digits, "");
        return ans;
    }
};

int main()
{
    return 0;
}