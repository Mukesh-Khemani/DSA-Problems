#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
This problem wants us to calculate the number of unique paths
from the top-left corner of a grid to the bottom-right corner.
So we employ the concept of combinatorics, specifically the
binomial coefficient, to achieve this efficiently.
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long ans = 1;
        for (int i = 1; i <= m - 1; i++)
        {
            ans = ans * (n - 1 + i) / i;
        }
        return (int)ans;
    }
};

int main()
{
    return 0;
}