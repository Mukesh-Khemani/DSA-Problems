#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:

The problem aims to find out the number of equal rows and columns where a row and column
are said to be equal if all their elements are identical.

If we start comparing each row with each column, this will lead to a time complexity of O(N^3).
So we need to look for an optimised approach. This hints towards 'hashmap'.

APPROACH:
The given approach counts the number of equal pairs in a grid. It uses a hashmap to store the
frequency of each vector in the grid. Then, it iterates through each column, creates a vector from
its elements, and checks if that vector exists in the hashmap. If it does, it adds the frequency to
the answer. Finally, it returns the total count of equal pairs.
*/

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        map<vector<int>, int> hashmap;
        for (auto it : grid)
        {
            hashmap[it]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> array;
            for (int j = 0; j < n; j++)
            {
                array.push_back(grid[j][i]);
            }
            if (hashmap[array])
                ans += hashmap[array];
        }
        return ans;
    }
};

int main()
{
    return 0;
}