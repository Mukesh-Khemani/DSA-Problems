#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find a binary string that differs from all
the binary strings in a given vector. So we iterate through the
input vector `nums` and constructs the result string `ans` by
choosing the opposite bit at each corresponding index from the
binary representation of the index. Specifically, for each string
in `nums`, we check the bit at the current index `i` and appends
the opposite bit (`0` if `1`, and `1` if `0`) to the result string.
*/

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string ans;
        for (int i = 0; i < nums.size(); i++)
        {
            char c = nums[i][i];
            ans += c == '0' ? '1' : '0';
        }
        return ans;
    }
};

int main()
{
    return 0;
}