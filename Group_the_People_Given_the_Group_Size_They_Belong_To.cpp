#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to group people based on their group sizes efficiently.
So, we utilize an array of vectors called `group` to organize individuals
according to their group size. By iterating through the `groupSizes` vector,
we assign each person to their respective group size, incrementally adding
them to the corresponding `group` vector. When a group's size equals the
indicated group size, we signify that all members have been accounted for
in that group. Consequently, we move this complete group into the `ans`
vector and clears the `group` vector for future use. This process continues
until all people are assigned to their groups.
*/

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> ans;
        vector<int> group[groupSizes.size() + 1];

        for (int i = 0; i < groupSizes.size(); i++)
        {
            group[groupSizes[i]].push_back(i);
            if (group[groupSizes[i]].size() == groupSizes[i])
            {
                ans.push_back(group[groupSizes[i]]);
                group[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}