#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this problem, we need to build and return an array avgs of length n where avgs[i]
is the k-radius average for the subarray centered at index i. So we use a sliding
window approach to efficiently calculate the averages. We maintain a running sum avg
of the current window's elements. At each step, we add the current element to avg and
subtracts the element that falls outside the window's range. When the window reaches
size 2*k+1, we calculate the average and stores it in the ans vector.
*/

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size(), size = 2 * k + 1;
        vector<int> ans(n, -1);
        long avg = 0;
        if (n < size)
            return ans;

        for (int i = 0; i < n; i++)
        {
            avg += nums[i];
            if (i - size >= 0)
                avg -= nums[i - size];
            if (i >= size - 1)
                ans[i - k] = avg / size;
        }
        return ans;
    }
};

int main()
{
    return 0;
}