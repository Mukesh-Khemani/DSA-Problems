#include <bits/stdc++.h>
using namespace std;

/*
INTUITION:
In the given problem, we use binary search to efficiently find the minimum speed
needed to complete a distance within a specified time limit.

APPROACH:
So we initialize low to 1 and high to a large value, then iteratively calculate
the time taken to cover the distance at the middle speed (mid). Depending on whether
the time exceeds the given limit or not, we narrow down the search range.The binary
search continues until low becomes greater than or equal to high. Finally, we return
the minimum required speed (low) to complete the journey within the time limit, and if
low is greater than a predefined value (10000000), we return -1, indicating it's impossible
to achieve the goal within the given time.
*/

class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int low = 1, high = 10000009;
        while (low < high)
        {
            int mid = (low + high) / 2;
            double time = 0;
            for (auto it : dist)
            {
                if (time > (int)time)
                    time = double((int)time + 1);
                time += ((double)it) / ((double)mid);
            }
            if (time > hour)
                low = mid + 1;
            else
                high = mid;
        }
        return (low > 10000000 ? -1 : low);
    }
};

int main()
{
    return 0;
}