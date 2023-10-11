#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition is to sort the starting and ending points of the flower intervals
separately and then use binary search to find the count of flowers that have started
or ended before or at the preferred time for each person. The difference between these
counts gives the number of flowers in full bloom at the preferred time for each person.
*/

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> starting;
        vector<int> ending;
        for (vector<int> &flower : flowers)
        {
            starting.push_back(flower[0]);
            ending.push_back(flower[1] + 1);
        }
        sort(starting.begin(), starting.end());
        sort(ending.begin(), ending.end());
        vector<int> ans;
        for (int person : people)
        {
            int i = upper_bound(starting.begin(), starting.end(), person) -
                    starting.begin();
            int j = upper_bound(ending.begin(), ending.end(), person) - ending.begin();
            ans.push_back(i - j);
        }
        return ans;
    }
};

int main()
{
    return 0;
}