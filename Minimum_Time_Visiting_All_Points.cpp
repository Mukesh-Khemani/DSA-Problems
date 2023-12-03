#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to calculate the minimum time required to visit all
points in a given vector of 2D points. We iterate through each consecutive
pair of points in the input array, calculating the distance in both the x
and y directions. We then add the maximum of these distances to the running
total, representing the time taken to traverse from the current point to the
next. By accumulating these maximum distances for all point pairs, the
function provides the minimum time needed to visit all points, considering
only horizontal and vertical movements.


*/

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int ans = 0;
        for (int i = 0; i < points.size() - 1; i++)
        {
            int X = points[i][0];
            int Y = points[i][1];
            int targetX = points[i + 1][0];
            int targetY = points[i + 1][1];
            ans += max(abs(targetX - X), abs(targetY - Y));
        }
        return ans;
    }
};

int main()
{
    return 0;
}