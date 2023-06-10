#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The given solution uses binary search to find the maximum possible value that
can be assigned to an element at a given index, while maintaining the sum of
all elements in a range to be less than or equal to a given maximum sum. It
iteratively adjusts the search range based on the calculated sum until the
maximum value is found.
*/

class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {
        long right = n - index - 1;
        long left = index;
        long high = maxSum;
        long low = 1;
        long result = 0;
        while (low <= high)
        {
            long mid = high - (high - low) / 2;
            long rightSum = 0;
            long leftSum = 0;
            long Sum = mid;
            long m = mid - 1;
            if (right <= m)
            {
                rightSum = m * (m + 1) / 2 - (m - right) * (m - right + 1) / 2;
            }
            else
            {
                rightSum = m * (m + 1) / 2 + (right - m);
            }
            if (left <= m)
            {
                leftSum = m * (m + 1) / 2 - (m - left) * (m - left + 1) / 2;
            }
            else
            {
                leftSum = m * (m + 1) / 2 + (left - m);
            }
            Sum += rightSum + leftSum;
            if (Sum <= maxSum)
            {
                low = mid + 1;
                result = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}