#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In this problem, we are given an integer array nums, we need to return the number of
longest increasing subsequences. We use dynamic programming to find the number of
longest increasing subsequences (LIS) in the vector nums. We do this by maintaining
\two vectors, length and count, to track the length and count of LIS ending at each
index. The solution then finds the maximum length and counts the number of subsequences
with that length.
*/
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> length(n, 1);
        vector<int> count(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (length[j] + 1 > length[i])
                    {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    }
                    if (length[j] + 1 == length[i])
                        count[i] += count[j];
                }
            }
        }
        int maxLength = *max_element(length.begin(), length.end());
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (length[i] == maxLength)
                result += count[i];
        }
        return result;
    }
};

int main()
{
    return 0;
}