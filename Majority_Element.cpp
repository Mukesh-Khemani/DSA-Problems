#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The majority element in an array is the element that appears more than
⌊n/2⌋ times, where n is the size of the array. We employ a variation of
Boyer-Moore Majority Vote algorithm. We iterate through the array,
maintaining a count of the majority element encountered so far. If the
count becomes zero, we update the current element as the potential
majority candidate. Whenever the current element matches the potential
majority candidate, the count is incremented, otherwise decremented.
This process effectively cancels out non-majority elements and leaves
the majority element as the final result.
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ans = 0;
        int majority = 0;
        for (int n : nums)
        {
            if (majority == 0)
                ans = n;
            majority += n == ans ? 1 : -1;
        }
        return ans;
    }
};

int main()
{
    return 0;
}