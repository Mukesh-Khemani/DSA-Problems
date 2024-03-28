#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition lies in finding the maximum length of a contiguous subarray
whose sum equals a given value 'k'. By utilizing a sliding window approach,
we maintain two pointers: 'start' and 'end', which define the boundaries of
the current subarray being considered. As we iterate through the array, we
update a frequency map to keep track of the occurrences of each element
encountered so far. Whenever the frequency of an element exceeds the given
value 'k', we move the 'start' pointer to shrink the window until the
condition is satisfied again. At each step, we update the maximum length
'ans' based on the current window size.
*/

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int ans = 0, start = -1;
        unordered_map<int, int> freq;
        for (int end = 0; end < nums.size(); end++)
        {
            freq[nums[end]]++;
            while (freq[nums[end]] > k)
            {
                start++;
                freq[nums[start]]--;
            }
            ans = max(ans, end - start);
        }
        return ans;
    }
};

int main()
{
    return 0;
}