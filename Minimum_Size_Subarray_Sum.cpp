#include <bits/stdc++.h>
using namespace std;

/*
APPROACH:- Two Pointer Algorithm
The algorithm starts with two pointers, 'l' and 'r', representing the left and
right boundaries of the current subarray. Initially, both pointers are set to 0.
The variable 'sum' keeps track of the sum of the current subarray, and 'ans' stores
the minimum length found so far.
*/

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int sum = 0, l = 0, r = 0, ans = INT_MAX;
        while (r < nums.size())
        {
            sum += nums[r];
            while (sum >= target)
            {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    return 0;
}