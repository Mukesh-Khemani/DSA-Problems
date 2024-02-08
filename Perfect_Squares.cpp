#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
By iterating through each number up to `n`, we calculate the minimum number
of perfect squares required to form that number. We do this by considering
all possible square numbers (`j*j`) less than or equal to the current number
`i` and updating the minimum count needed to reach `i`. By continuously
updating the minimum count for each number, we eventually compute the minimum
number of perfect squares needed to form the given `n`.
*/

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> helper(n + 1, INT_MAX);
        helper[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                helper[i] = min(helper[i], helper[i - j * j] + 1);
            }
        }
        return helper[n];
    }
};

int main()
{
    return 0;
}