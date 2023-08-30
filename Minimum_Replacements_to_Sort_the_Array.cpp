#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this problem, we need to return the minimum number of operations to make an array
that is sorted in non-decreasing order. So we iterate through the array from the
second-to-last element to the first element. If the current element is greater than
or equal to the next element, we calculate the number of replacements needed to make
them strictly increasing. We then update the answer by subtracting 1 from the
replacements and divides the current element by the replacements.
*/

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long ans = 0;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
                continue;
            long replacements = (long)(nums[i] + nums[i + 1] - 1) / (long)nums[i + 1];
            ans += replacements - 1;
            nums[i] /= (int)replacements;
        }
        return ans;
    }
};

int main()
{
    return 0;
}