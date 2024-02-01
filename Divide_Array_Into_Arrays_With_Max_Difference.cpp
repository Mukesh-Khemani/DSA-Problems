#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition lies in sorting the array first to ensure that adjacent
elements are in ascending order. Then, we iterate over the sorted array
in increments of three, as each group contains three consecutive elements.
During each iteration, we check if the difference between the maximum and
minimum elements within the current group exceeds the given threshold k .
If it does, we return an empty vector, indicating that such division is
not possible. Otherwise, we add the current group to the result vector.
*/

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i += 3)
        {
            if (nums[i + 2] - nums[i] > k)
                return {};
            result.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return result;
    }
};

int main()
{
    return 0;
}