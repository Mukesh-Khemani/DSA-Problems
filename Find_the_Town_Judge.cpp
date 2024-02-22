#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the judge in a town where the judge trusts
no one and everyone trusts the judge. We initialize a helper array
to track the trust score of each person, with negative scores indicating
trust given and positive scores indicating trust received. By iterating
through the trust relationships and updating the trust scores accordingly,
we identify the person who is trusted by everyone else (i.e., has a trust
score of n - 1). If such a person exists, they are returned as the judge;
otherwise, -1 is returned.
*/

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> helper(n + 1, 0);
        for (const auto &relation : trust)
        {
            helper[relation[0]]--;
            helper[relation[1]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (helper[i] == n - 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    return 0;
}