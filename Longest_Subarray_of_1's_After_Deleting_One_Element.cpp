#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition behind the solution is to maintain a sliding window that
tracks the longest subarray with at most one zero. We keep track of the
number of zeroes encountered in the current window and adjust the window
boundaries accordingly.
*/

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int numberOfZeroes = 0;
        int ans = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            numberOfZeroes += (nums[i] == 0);
            while (numberOfZeroes > 1)
            {
                numberOfZeroes -= (nums[start++] == 0);
            }
            ans = max(ans, i - start);
        }
        return ans;
    }
};

int main()
{
    return 0;
}