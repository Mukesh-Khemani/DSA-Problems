#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The given problem involves counting the number of good strings within a specified range.
We can observe that the number of good strings at any position depends on the number of
zeroes and ones encountered so far. By using dynamic programming, we can keep track of
the number of good strings up to a particular position. We iterate from the minimum of
zeroes and ones to the highest value and update the count based on the number of zeroes
and ones encountered. Finally, we sum up the counts within the given range to obtain the
total number of good strings.
*/

class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int mod = 1000000007;
        for (int i = min(zero, one); i <= high; i++)
        {
            if (i >= zero)
            {
                dp[i] += dp[i - zero];
            }
            if (i >= one)
            {
                dp[i] += dp[i - one];
            }
            dp[i] %= mod;
        }
        int sum = 0;
        for (int i = low; i <= high; i++)
        {
            sum = (sum + dp[i]) % mod;
        }
        return sum;
    }
};

int main()
{
    return 0;
}