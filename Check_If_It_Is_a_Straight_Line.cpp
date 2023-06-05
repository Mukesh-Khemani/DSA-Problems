#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
We have to find that the given set of points is collinear or not.
For that we can use a number of approaches like equal slopes of lines
formed by any 2 points into consideration, zero area of triangle formed
by all possible combinations of 3 points,etc.

APPROACH:
1) We iterate through the coordinates starting from the second point (index 1)
up to the second-to-last point (index coordinates.size()-1).
2) For each point, we use the slope formula to check if the slope between the current
point and the previous point is equal to the slope between the current point and the
next point. If the slopes are not equal, it means the points do not lie on a straight
line, and returns false.
3) If the loop completes without finding any unequal slopes, it means all points lie on the
same straight line, and returns true.
*/

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        if (coordinates.size() <= 2)
            return true;
        for (int i = 1; i < coordinates.size() - 1; i++)
        {
            if ((coordinates[i + 1][1] - coordinates[i][1]) *
                    (coordinates[i][0] - coordinates[i - 1][0]) !=
                (coordinates[i][1] - coordinates[i - 1][1]) *
                    (coordinates[i + 1][0] - coordinates[i][0]))
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}