#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to calculate the number of distinct ways to climb a staircase with `n`
steps, where each step can be taken either 1 or 2 at a time. The intuition is to use a
dynamic programming approach, optimizing space by only storing the last two calculated
values. We initialize `first` and `second` to represent the distinct ways to climb 2
and 3 steps, respectively. We then iteratively calculate the distinct ways for the
remaining steps, updating the variables `first`, `second`, and `third`. The final
result, stored in `third`, represents the total number of distinct ways to climb the
staircase with `n` steps.
*/

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 4)
        {
            return n;
        }
        int first = 2, second = 3, third = 0;
        while (n - 3)
        {
            n--;
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};

int main()
{
    return 0;
}