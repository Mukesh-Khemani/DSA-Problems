#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the maximum frequency of an element in a subarray
by utilizing a sliding window approach. We begin by sorting the input array
in ascending order. We then maintain a sliding window by iterating through
the array using two pointers, `l` and `r`, representing the left and right
boundaries of the window. For each iteration, we calculate the current sum
of the elements within the window and checks if the cost (difference between
the total sum and the sum within the window) exceeds the given threshold `k`.
If it does, we adjusts the window by moving the left boundary (`l`) and
updates the current sum accordingly. The result is the size of the maximum
frequency subarray, which is the total array size minus the left boundary index.
*/

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int l = 0;
        long curr = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            long target = nums[r];
            curr += target;
            if ((r - l + 1) * target - curr > k)
            {
                curr -= nums[l];
                l++;
            }
        }
        return nums.size() - l;
    }
};

int main()
{
    return 0;
}