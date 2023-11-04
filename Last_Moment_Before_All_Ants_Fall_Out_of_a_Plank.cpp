#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The main intuition is the calculate the time at which the last particle
collides in a scenario where particles initially positioned on the left
and right sides move towards each other. So we iterate through the
positions of particles on the left and right sides, determining the
maximum position of a particle on the left and the maximum distance a
particle on the right has traveled from the rightmost position. The
result is the maximum of these two values, representing the moment when
the last collision occurs.
*/

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int res = 0;
        for (int num : left)
            res = max(res, num);
        for (int num : right)
            res = max(res, n - num);
        return res;
    }
};

int main()
{
    return 0;
}