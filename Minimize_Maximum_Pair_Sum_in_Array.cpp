#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the minimum possible pair sum in an array by
pairing elements in a way that maximizes the sum. We first sort the
input array in non-decreasing order. Then, we iterate over the first
half of the sorted array, pairing the smallest and largest elements
at corresponding positions. We calculate the sum of each pair and
updates the maximum sum encountered so far. The result is the maximum
sum among all possible pairs, representing the minimum pair sum.
*/

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int maxSum = 0;
        for (int i = 0; i < nums.size() / 2; i++)
        {
            maxSum = max(maxSum, nums[i] + nums[nums.size() - 1 - i]);
        }
        return maxSum;
    }
};

int main()
{
    return 0;
}