#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The intuition is to iterate through each element of the array and use
a map to store the length of the subsequence ending at each element.
If there is a previous element with a value equal to the current element
minus the given difference, we update the length by adding 1 to the
length of the previous subsequence. We keep track of the maximum length
encountered and return it as the result.
*/

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        map<int, int> dp;
        int ans = 1;
        for (int it : arr)
        {
            dp[it] = 1 + (dp.count(it - difference) ? dp[it - difference] : 0);
            ans = max(ans, dp[it]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}