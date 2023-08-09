#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the minimum value of the maximum difference between array
elements, such that at least p pairs have a difference within that maximum. Binary
search narrows down this value. 'countPairs' counts pairs with differences within a
specified limit, and minimizeMax performs binary search to find the optimal maximum
difference that fulfills the requirement.
*/

class Solution
{
    int countPairs(vector<int> &nums, int p, int diff)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] <= diff)
            {
                i++;
                p--;
            }
        }
        return p <= 0;
    }

public:
    int minimizeMax(vector<int> &nums, int p)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums[n - 1] - nums[0], res = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (countPairs(nums, p, mid))
            {
                res = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}