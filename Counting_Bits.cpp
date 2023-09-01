#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
As we iterate through the numbers from 0 to n, we calculate each number's
bit count by reusing the counts of smaller numbers, thus avoiding redundant
computations. The bit count for a number is obtained by adding the bit count
of its right-shifted form (halving the number) and the least significant bit.
This approach ensures that the solution provides an array containing the bit
counts for all numbers in the given range, offering an efficient solution for
binary bit counting.
*/

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++)
            ans[i] = ans[i / 2] + i % 2;
        return ans;
    }
};

int main()
{
    return 0;
}