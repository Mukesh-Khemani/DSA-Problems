#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
This problem aims to find the majority elements in an array, defined as
elements that appear more than ⌊n/3⌋ times, where n is the size of the
array. We use an unordered_map to count the occurrences of each element
in the input array. We then iterate through the map, and for each element,
checks if its count exceeds the threshold ⌊n/3⌋. If so, we add the element
to the result vector.
*/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]]++;
        vector<int> ans;
        for (auto element : map)
        {
            if (element.second > nums.size() / 3)
            {
                ans.push_back(element.first);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}