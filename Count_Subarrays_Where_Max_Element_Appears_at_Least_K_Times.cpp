#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to calculate the number of subarrays in an array where the
maximum element occurs exactly K times. We utilize a sliding window approach,
initializing a start and end pointer to traverse the array. By iterating
through the array and adjusting the window based on the frequency of the
maximum element, we identify subarrays meeting the required condition.
Specifically, when encountering the maximum element, we decrement K, and
when K reaches zero, we move the start pointer forward until K becomes
positive again. The total count of valid subarrays is accumulated during
the process.
*/

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxElement = *max_element(nums.begin(), nums.end());
        long long ans = 0, start = 0;
        for (int end = 0; end < nums.size(); end++)
        {
            if (nums[end] == maxElement)
                k--;
            while (!k)
            {
                if (nums[start] == maxElement)
                    k++;
                start++;
            }
            ans += start;
        }
        return ans;
    }
};

int main()
{
    return 0;
}