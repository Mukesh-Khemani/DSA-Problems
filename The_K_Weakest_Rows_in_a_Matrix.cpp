#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem wants us to calculate the strength of each row (number of
soldiers) in the matrix, sorts the rows based on their strength, and
returns the indices of the k weakest rows in ascending order of strength.
We use the accumulate function for row-wise summing and a vector of pairs
for efficient sorting and tracking of row indices.
*/

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> helper;
        for (int i = 0; i < mat.size(); i++)
        {
            int strength = accumulate(mat[i].begin(), mat[i].end(), 0);
            helper.push_back({strength, i});
        }
        sort(helper.begin(), helper.end());
        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(helper[i].second);
        return result;
    }
};

int main()
{
    return 0;
}