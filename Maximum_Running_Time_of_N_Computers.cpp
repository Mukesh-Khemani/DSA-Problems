#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The given problem aims to find the maximum run time for a device with n batteries,
given their power levels. So we use binary search to efficiently find the maximum
run time that can be achieved. We iteratively adjust the search range based on the
available power and the required power for n batteries at the target run time. The
binary search narrows down the search space to find the maximum achievable run time,
optimizing the solution.
*/

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long sumPower = 0;
        for (int power : batteries)
            sumPower += power;
        long long left = 1, right = sumPower / n;
        while (left < right)
        {
            long target = right - (right - left) / 2;
            long extra = 0;
            for (long power : batteries)
                extra += min(power, target);
            if (extra >= (long)(n * target))
                left = target;
            else
                right = target - 1;
        }
        return left;
    }
};

int main()
{
    return 0;
}