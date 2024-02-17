#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
The problem aims to find the furthest building that can be reached using a
limited number of bricks and ladders. So we iterate through the heights of
buildings, calculating the height difference between adjacent buildings. If
the height difference is positive (indicating a climb), we add this
difference to a min-heap priority queue. This queue stores the smallest
height differences encountered so far. If the size of the priority queue
exceeds the number of available ladders, we use bricks to climb instead. We
replace the highest height difference in the queue with the current difference,
simulating the use of a ladder. If the remaining bricks become negative at
any point, the loop terminates, and the current index (representing the furthest
reachable building) is returned. If the loop completes without reaching a
negative brick count, the last building index is returned, indicating that all
buildings can be reached within the given resources.
*/

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < heights.size() - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0)
            {
                pq.push(diff);

                if (pq.size() > ladders)
                {
                    int highest_diff = pq.top();
                    pq.pop();
                    bricks -= highest_diff;
                    if (bricks < 0)
                        return i;
                }
            }
        }
        return heights.size() - 1;
    }
};

int main()
{
    return 0;
}