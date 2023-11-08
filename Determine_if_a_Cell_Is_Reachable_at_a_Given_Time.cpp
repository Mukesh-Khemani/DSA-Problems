#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The main aim of the problem is to determine whether a destination (`fx`, `fy`)
is reachable from a starting point (`sx`, `sy`) within a given time constraint
`t`. We calculate the width and height difference between the starting and
destination points and check if the time constraint is greater than or equal to
the maximum of these differences. If the `width` and `height` differences are
both zero (indicating the starting and destination points are the same) and the
time constraint is exactly 1, we return `false` since the destination cannot be
reached within that time. Otherwise, we return true, indicating that the destination
is reachable within the specified time.
*/

class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        int width = abs(sx - fx);
        int height = abs(sy - fy);
        if (width == 0 and height == 0 and t == 1)
            return false;
        return t >= max(width, height);
    }
};

int main()
{
    return 0;
}