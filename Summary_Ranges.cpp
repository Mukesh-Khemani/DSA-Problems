#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this problem, we have to summarize the array to an array of ranges, if the array has consecutive
numbers. The intuition is to iterate through the input vector and identify consecutive elements to
create summarized ranges. By comparing each element with the next one, we can determine if a range exists.

APPROACH:
The solution iterates through the vector and identifies consecutive elements to create summarized ranges.
It keeps track of the current range using two pointers, i and j. The logic involves iterating through the
vector and comparing each element with the next one. If they are consecutive, the range continues. When a
non-consecutive element is encountered, the current range is summarized and added to the result vector.
*/

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        int i = 0;
        while (i < nums.size())
        {
            string s;
            s += to_string(nums[i]);
            int j = i;
            while (j < nums.size() - 1 and nums[j + 1] == nums[j] + 1)
            {
                j++;
            }
            if (i != j)
            {
                s += "->";
                s += to_string(nums[j]);
            }
            ans.push_back(s);
            i = j + 1;
        }
        return ans;
    }
};

int main()
{
    return 0;
}